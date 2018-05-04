//#include "MapView.h"
#include "FindPath.h"
#include "CCLuaEngine.h"

USING_NS_CC;


// -----------------------------------------------------------
// MapSimpleResLoadMgr
// -----------------------------------------------------------
MapSimpleResLoadMgr * MapSimpleResLoadMgr::s_instance = nullptr;

MapSimpleResLoadMgr * MapSimpleResLoadMgr::getInstance()
{
	if (s_instance == nullptr)
	{
		s_instance = new MapSimpleResLoadMgr;
	}
	return s_instance;
}

void MapSimpleResLoadMgr::destroyInstance()
{
	CC_SAFE_RELEASE_NULL(s_instance);
}

MapSimpleResLoadMgr::MapSimpleResLoadMgr()
{
	//Director::getInstance()->getScheduler()->schedule(SEL_SCHEDULE(&MapSimpleResLoadMgr::updateSF), this, 0.03f, false);
}


MapSimpleResLoadMgr::~MapSimpleResLoadMgr()
{
	//Director::getInstance()->getScheduler()->unschedule(SEL_SCHEDULE(&MapSimpleResLoadMgr::updateSF), this);
}

SpriteFrame * MapSimpleResLoadMgr::getSpriteFrameByImgName(const std::string & imgName)
{
	std::string textureFullPath = FileUtils::getInstance()->fullPathForFilename(imgName);
	if (textureFullPath.empty())
	{
		//CCLOGWIN32("MapSimpleResLoadMgr::getSpriteFrameByImgName: file %s not exist", imgName.c_str());
		return nullptr;
	}

	Texture2D * tex = Director::getInstance()->getTextureCache()->getTextureForKeyFullPath(textureFullPath);
	if (tex != nullptr)
	{
		/*
		系统里有的就不再重复延迟返回了
		也可以注释掉此段代码测试地图在移动出可视范围后的区域是否已经被释放，再次显示时是否会再次调用此代码加载纹理
		*/
		return SpriteFrame::createWithTexture(tex, Rect(0.f, 0.f, tex->getContentSize().width, tex->getContentSize().height));
	}

	// check if file exists
	//if (!FileUtils::getInstance()->isFileExist(textureFullPath))
	//{
	//	CCLOGWIN32("MapSimpleResLoadMgr::getSpriteFrameByImgName: file %s not exist 2", imgName.c_str());
	//	return nullptr;
	//}

	bool hasFound = false;
	VecLoadingSpriteFrame::iterator ret = _sfWaitingToLoad.begin();
	for (; ret != _sfWaitingToLoad.end(); ++ret)
	{
		if (ret->first == textureFullPath)
		{
			hasFound = true;
			break;
		}
	}



	//SpriteFrame* sf = SpriteFrame::create(textureFullPath, Rect(0, 0, 512, 512));

	if (!hasFound)
		Director::getInstance()->getTextureCache()->addImageAsync(textureFullPath, CC_CALLBACK_1(MapSimpleResLoadMgr::imageLoaded, this));

	SpriteFrame *sf = SpriteFrame::createWithTexture(nullptr, Rect(0.f, 0.f, 2, 2));
	if (sf)
	{
		sf->retain();
		_sfWaitingToLoad.push_back(std::make_pair(textureFullPath, sf));
	}

	return sf;
}

void MapSimpleResLoadMgr::imageLoaded(cocos2d::Texture2D *texture)
{
	if (texture == nullptr)
		return;

	const std::string& textureFullPath = Director::getInstance()->getTextureCache()->GetLoadAsyncTextureFullPath();
	if (textureFullPath.empty())
		return;

	for (auto it = _sfWaitingToLoad.begin(); it != _sfWaitingToLoad.end();)
	{
		if (it->second->getReferenceCount() == 1) // 已经被使用者抛弃
		{
			it->second->release();
			it = _sfWaitingToLoad.erase(it);
			continue;
		}

		if (textureFullPath == it->first)
		{
			it->second->setTexture(texture);
			it->second->release();
			it = _sfWaitingToLoad.erase(it);
			continue;
		}

		++it;
	}
}

void MapSimpleResLoadMgr::updateSF(float)
{
	// 模拟加载缓慢及边玩边下载的情况
	std::pair<std::string, SpriteFrame *> sfInfo;
	bool hasFound = false;
	while (true)
	{
		if (_sfWaitingToLoad.empty()) return;

		auto __sfInfo = _sfWaitingToLoad.back();
		_sfWaitingToLoad.pop_back();

		if (__sfInfo.second->getReferenceCount() == 1) // 已经被使用者抛弃
		{
			__sfInfo.second->release();
			continue;;
		}
		sfInfo = __sfInfo;
		hasFound = true;
		break;
	}

	if (hasFound)
	{
		Texture2D * tex = Director::getInstance()->getTextureCache()->addImage(sfInfo.first);
		if (tex != nullptr)
			sfInfo.second->setTexture(tex);
		sfInfo.second->release();
	}

}

























MapView::MapView()
: m_pMap(nullptr)
{
}

MapView::~MapView()
{
}


MapView * MapView::create()
{
	MapView * ret = new MapView();
	if (ret && ret->init())
	{
		ret->autorelease();
	}
	else
	{
		CC_SAFE_DELETE(ret);
	}

	return ret;
}

void MapView::load(const std::string& filename)
{
	m_block_str.clear();
	if (!filename.empty() && FileUtils::getInstance()->isFileExist(filename))
	{
		// 地图节点
		cocos2d::experimental::TMXTiledMap * _tmxMap = cocos2d::experimental::TMXTiledMap::create(filename);
		if (_tmxMap)
		{
			m_mapSize = _tmxMap->getMapSize();
			m_perTileSize = _tmxMap->getTileSize();

			_tmxMap->setExtFatSize(m_perTileSize);
			_tmxMap->setLoadSpriteFrameFunction([](const std::string & imgName, int32_t) { return MapSimpleResLoadMgr::getInstance()->getSpriteFrameByImgName(imgName); });
			_tmxMap->setFixArtifactsByStrechingTexel(true);
			_tmxMap->setAnchorPoint(Point::ZERO);
			_tmxMap->setPosition(Point::ZERO);

			/*
			将 alpha 层和 block 层中的数据读取到游戏后将其移除降低内存占用
			*/
			cocos2d::experimental::TMXLayer * pBolckLayer = _tmxMap->getLayer("block");
			cocos2d::experimental::TMXLayer * pAlphaLayer = _tmxMap->getLayer("alpha");

			int sizeHint = 0;
			int sizeHintAlpha = 0;
			int sizeHintBlock = 0;

			if (pAlphaLayer)
			{
				Size s = pAlphaLayer->getLayerSize();
				sizeHintAlpha = s.width * s.height;
			}

			if (pBolckLayer)
			{
				Size s = pBolckLayer->getLayerSize();
				sizeHintBlock = s.width * s.height;
			}
			else
			{
				Size s = _tmxMap->getMapSize();
				sizeHintBlock = s.width * s.height;
			}

			sizeHint = max(sizeHintAlpha, sizeHintBlock);
			if (sizeHint > 0)
				m_block_str.resize(sizeHint, '0');

			if (pAlphaLayer)
			{
				const uint32_t* tiles = pAlphaLayer->getTiles();

				for (int ib = 0; ib < sizeHintAlpha; ++ib)
				{
					if (tiles[ib] != 0)
					{
						m_block_str[ib] = '2';
					}
				}
			}
			if (pBolckLayer)
			{
				const uint32_t* tiles = pBolckLayer->getTiles();

				for (int ib = 0; ib < sizeHintBlock; ++ib)
				{
					if (tiles[ib] != 0)
					{
						m_block_str[ib] = '1';
					}
				}
			}


			//FileUtils::getInstance()->writeStringToFile(m_block_str, "res/mapnew/a.txt");

			_tmxMap->removeLayer("alpha");
			_tmxMap->removeLayer("block");

			Size mapSize = m_mapSize;
			mapSize.width *= m_perTileSize.width;
			mapSize.height *= m_perTileSize.height;

			_tmxMap->setPosition(0, mapSize.height - m_perTileSize.height);
			addChild(_tmxMap);
		}
	}
	else
	{
		m_perTileSize = Size(32, 48);
		m_mapSize = Size(400, 400);
		m_block_str.resize(m_mapSize.width*m_mapSize.height, '0');
	}
}

bool MapView::isBlock(Point tile)
{
	if ((tile.x >= m_mapSize.width || tile.y >= m_mapSize.height || tile.x<0 || tile.y<0) || (tile.x == 0 && tile.y == 0))
		return true;
	int x = tile.x;
	int y = tile.y;
	return (m_block_str.at(y*int(m_mapSize.width) + x) == '1');
}

bool MapView::isOpacity(Point tile)
{
	if (tile.x >= m_mapSize.width || tile.y >= m_mapSize.height || tile.x<0 || tile.y<0)
		return true;
	int x = tile.x;
	int y = tile.y;
	return (m_block_str.at(y*int(m_mapSize.width) + x) == '2');
}


Point MapView::tile2Space(Point tile)
{
	int sx = (tile.x + 0.5) * m_perTileSize.width;
	int sy = (m_mapSize.height - (tile.y + 0.5))* m_perTileSize.height;
	return Point(sx, sy);
}

Point MapView::space2Tile(Point pos)
{
	int ty = m_mapSize.height - ceil(pos.y / m_perTileSize.height);
	int tx = floor(pos.x / m_perTileSize.width);
	return Point(tx, ty);
}

Point MapView::getCenterTile()
{
	Size scrSize = Director::getInstance()->getWinSize();
	return screen2Tile(Point(scrSize.width / 2, scrSize.height / 2));
}

Point MapView::screen2Tile(Point point)
{
	return space2Tile(screen2Space(point));
}

Point MapView::tile2Screen(Point tile)
{
	return space2Screen(tile2Space(tile));
}

Point MapView::screen2Space(Point point)
{
	return convertToNodeSpace(point);
	//float scale = Director::getInstance()->getMapScale();
	//return CC_POINT_POINTS_TO_PIXELS((point-getPosition())/scale);
}

Point MapView::space2Screen(Point pos)
{
	////float scale = Director::getInstance()->getMapScale();
	////return (CC_POINT_PIXELS_TO_POINTS(pos)+ getPosition());
	return convertToWorldSpace(pos);
}

void MapView::setPosition(const Point& position)
{
	Node::setPosition(position);
	//CCLOG("MapView Pos: (%d, %d)", (int)this->getPosition().x, (int)this->getPosition().y);
}
