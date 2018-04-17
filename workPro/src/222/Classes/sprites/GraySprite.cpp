#include "GraySprite.h"
#include "MapView/SortNode.h"

USING_NS_CC;

GraySprite::GraySprite()
{
	m_reDraw = false;
	m_doreDraw = false;
}
GraySprite::~GraySprite(void)
{
}


GraySprite *GraySprite::create(const std::string&pszFileName)
{
    GraySprite *pRet = new GraySprite();
    if (pRet && pRet->initWithFile(pszFileName))
    {
        pRet->autorelease();
        return pRet;
    }
    else
    {
        CC_SAFE_DELETE(pRet);
        return NULL;
    }
}

GraySprite *GraySprite::create()
{
    GraySprite *pRet = new GraySprite();
    if (pRet&& pRet->init()) 
    {
        pRet->autorelease();
        return pRet;
    }
    else
    {
        CC_SAFE_DELETE(pRet);
        return NULL;
    }
}

void GraySprite::addColorGray()
{
	setGLProgram(ShaderCache::getInstance()->getGLProgram(GLProgram::SHADER_NAME_POSITION_GRAYSCALE));
	//setGLProgramState(GLProgramState::getOrCreateWithGLProgramName(GLProgram::SHADER_NAME_POSITION_GRAYSCALE));
}

void GraySprite::removeColorGray()
{
	setGLProgram(ShaderCache::getInstance()->getGLProgram(GLProgram::SHADER_NAME_POSITION_TEXTURE_COLOR_NO_MVP_STR));
	//setGLProgramState(GLProgramState::getOrCreateWithGLProgramName(GLProgram::SHADER_NAME_POSITION_TEXTURE_COLOR_NO_MVP));
}

void GraySprite::setColorGray(bool isgray)
{
	if(isgray)
		addColorGray();
	else
		removeColorGray();
}

void GraySprite::setColorWrite(bool isgray)
{
}

void GraySprite::visit(Renderer *renderer, const Mat4& parentTransform, uint32_t parentFlags)
{
	Sprite::visit(renderer, parentTransform, parentFlags);
}
void GraySprite::draw(Renderer *renderer, const Mat4 &transform, uint32_t flags)
{
#if CC_USE_CULLING
    // Don't do calculate the culling if the transform was not updated
    auto visitingCamera = Camera::getVisitingCamera();
    auto defaultCamera = Camera::getDefaultCamera();
    if (visitingCamera == defaultCamera) {
        _insideBounds = ((flags & FLAGS_TRANSFORM_DIRTY)|| visitingCamera->isViewProjectionUpdated()) ? renderer->checkVisibility(transform, _contentSize) : _insideBounds;
    }
    else
    {
        _insideBounds = renderer->checkVisibility(transform, _contentSize);
    }

    if(_insideBounds)
#endif
    {

		if(m_reDraw)
		{
			if(m_doreDraw)
			{
				m_polyInfo = _polyInfo;
				for (ssize_t i = 0; i < m_polyInfo.triangles.vertCount; i++) {
					m_polyInfo.triangles.verts[i].colors.a = getOpacity()/2;
				}
				m_cmd.init(_globalZOrder, _texture->getName(), getGLProgramState(), _blendFunc, m_polyInfo.triangles, transform, flags);
				renderer->addCommand(&m_cmd);
				m_doreDraw = false;
			}
			else
			{
				_trianglesCommand.init(_globalZOrder, _texture->getName(), getGLProgramState(), _blendFunc, _polyInfo.triangles, transform, flags);
				renderer->addCommand(&_trianglesCommand);
				SortNode::insertQueuq();
				m_doreDraw = true;
			}
		}
		else
		{
			_trianglesCommand.init(_globalZOrder, _texture->getName(), getGLProgramState(), _blendFunc, _polyInfo.triangles, transform, flags);
			renderer->addCommand(&_trianglesCommand);
		}
#if CC_SPRITE_DEBUG_DRAW
        _debugDrawNode->clear();
        auto count = _polyInfo.triangles.indexCount/3;
        auto indices = _polyInfo.triangles.indices;
        auto verts = _polyInfo.triangles.verts;
        for(ssize_t i = 0; i < count; i++)
        {
            //draw 3 lines
            Vec3 from =verts[indices[i*3]].vertices;
            Vec3 to = verts[indices[i*3+1]].vertices;
            _debugDrawNode->drawLine(Vec2(from.x, from.y), Vec2(to.x,to.y), Color4F::WHITE);
            
            from =verts[indices[i*3+1]].vertices;
            to = verts[indices[i*3+2]].vertices;
            _debugDrawNode->drawLine(Vec2(from.x, from.y), Vec2(to.x,to.y), Color4F::WHITE);
            
            from =verts[indices[i*3+2]].vertices;
            to = verts[indices[i*3]].vertices;
            _debugDrawNode->drawLine(Vec2(from.x, from.y), Vec2(to.x,to.y), Color4F::WHITE);
        }
#endif //CC_SPRITE_DEBUG_DRAW
    }
}

