#include "MirBatchDrawLabel.h"
#include "2d/CCFontAtlasCache.h"
#include "base/ccMacros.h"

const int MirBatchDrawLabel::DistanceFieldFontSize = 50;

MirTextNode * MirBatchDrawLabel::createLabel(const std::string& text, int32_t zOrder, const Vec2 & pos)
{
    MirTextNode * ret = new MirTextNode(this, zOrder);
	if(ret != nullptr)
	{
		ret->autorelease();
		ret->_commonLineHeight = this->_commonLineHeight;
		ret->setString(text);
		ret->setPosition(pos);
		ret->setLocalZOrder(zOrder);
		this->addChild(ret);
	}
	else
	{
		 CC_SAFE_DELETE(ret);
	}
    return ret;
}

void MirBatchDrawLabel::removeLabel(MirTextNode * lbl)
{
    if (lbl)
    {
        lbl->removeFromParent();
        //CC_SAFE_RELEASE_NULL(lbl); 
    }
}

void MirBatchDrawLabel::visit(Renderer *renderer, const Mat4 &parentTransform, uint32_t parentFlags)
{
    if (!_visible)
        return;

    uint32_t flags = processParentFlags(parentTransform, parentFlags);

    auto walkFunc = [=](Node * node)
    {
        node->visit(renderer, _modelViewTransform, flags);
    };

    if (_walkHelper == nullptr)
    {
        for (auto node : _children)
        {
            walkFunc(node);
        }
    }
    else
    {
        _walkHelper->walk(walkFunc, this);
    }

    draw(renderer, parentTransform, parentFlags);
}

void MirBatchDrawLabel::draw(Renderer *renderer, const Mat4 &transform, uint32_t flags)
{
    if (_children.empty())
    {
        return;
    }

    _currTextureId = -1;
    _quadsSpliters.clear();

    _quadsCount = 0;
    _currDrawCallQuadsCount = 0; // 当前 drawcall 的 quad 数目

    auto walkFunc = [&](Node * node)
    {
        auto lbl = dynamic_cast<MirTextNode *>(node);
        if (lbl == nullptr || lbl->isVisible() == false) return;

        V3F_C4B_T2F_Quad    * pQuad = (V3F_C4B_T2F_Quad *)_quadBuff;

        auto & lettersInfo = lbl->_lettersInfo;
        for (auto &letterInfo : lettersInfo)
        {
            if (letterInfo.def.validDefinition == false)
                continue;

            memcpy(pQuad, &letterInfo.quad, sizeof(V3F_C4B_T2F_Quad));

            auto & mat = lbl->_modelViewTransform;
            mat.transformPoint(&pQuad->bl.vertices);
            mat.transformPoint(&pQuad->tl.vertices);
            mat.transformPoint(&pQuad->br.vertices);
            mat.transformPoint(&pQuad->tr.vertices);

            if (_quadsCount >= _quads.size())
                _quads.push_back(*pQuad);
            else
                memcpy(&_quads[_quadsCount], pQuad, sizeof(V3F_C4B_T2F_Quad));

            _quadsCount++;
            _currDrawCallQuadsCount++;

			if (_currDrawCallQuadsCount * 4 + 4 > Renderer::VBO_SIZE
                || letterInfo.def.textureID != _currTextureId)
            {
                _currTextureId = letterInfo.def.textureID;
                _quadsSpliters.push_back(std::make_pair(_quadsCount - 1, _currTextureId));
                _currDrawCallQuadsCount = 1;
            }
        }
    };

    if (_walkHelper == nullptr)
    {
		Node* myNode = nullptr;

		ssize_t asize = _children.size();
		for (ssize_t i = 0; i < asize; ++i)
        {
			Node* cnode = _children.at(i);
			if (myNode == nullptr && cnode->getTag() == 1327)
			{
				myNode = cnode;
			}
			else
			{
				walkFunc(cnode);
			}
        }

		if (myNode)
		{
			walkFunc(myNode);
		}

    }
    else
    {
        _walkHelper->walk(walkFunc, this);
    }
    
    _quadsSpliters.push_back(std::make_pair(_quadsCount, -1));

    /*if (_quadsCount > _indices.size() / 6)
    {
        resizeIndices(_quadsCount);
    }*/

    if (_quadsSpliters.size() < 2)
        return;

    _cmd.init(_globalZOrder);
    _cmd.func = _onDrawFunc;
    renderer->addCommand(&_cmd);
}

void MirBatchDrawLabel::onDraw()
{
	if (_quads.empty())
		return;

    GL::blendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    setGLProgramState(_glProgramState);
    getGLProgramState()->apply(Mat4::IDENTITY); // 参数随便传，因为我们不用 mv,只用 project 矩阵

    auto glprogram = getGLProgram();
    glprogram->setUniformLocationWith4f(_uniformTextColor, _textColor.r / 255.f, _textColor.g / 255.f, _textColor.b / 255.f, 1.f);
    if (_currLabelEffect == cocos2d::LabelEffect::OUTLINE || _currLabelEffect == cocos2d::LabelEffect::GLOW)
    {
        glprogram->setUniformLocationWith4f(_uniformEffectColor, _effectColor.r / 255.f, _effectColor.g / 255.f, _effectColor.b / 255.f, 1.f);
    }

	GLuint vbo = Director::getInstance()->getRenderer()->getSharedVertexsVBO();
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(V3F_C4B_T2F_Quad)* _quadsCount, &_quads[0], GL_DYNAMIC_DRAW);
   
    GL::enableVertexAttribs(GL::VERTEX_ATTRIB_FLAG_POS_COLOR_TEX);
    glVertexAttribPointer(GLProgram::VERTEX_ATTRIB_POSITION, 3, GL_FLOAT, GL_FALSE, sizeof(V3F_C4B_T2F), (GLvoid*)offsetof(V3F_C4B_T2F, vertices));
    glVertexAttribPointer(GLProgram::VERTEX_ATTRIB_COLOR, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(V3F_C4B_T2F), (GLvoid*)offsetof(V3F_C4B_T2F, colors));
    glVertexAttribPointer(GLProgram::VERTEX_ATTRIB_TEX_COORD, 2, GL_FLOAT, GL_FALSE, sizeof(V3F_C4B_T2F), (GLvoid*)offsetof(V3F_C4B_T2F, texCoords));

    //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _vbos[1]);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Director::getInstance()->getRenderer()->getSharedIndicesVBO());

    size_t spliterCount = _quadsSpliters.size();
    for (uint32_t i = 0; i < spliterCount - 1; i++)
    {
        int32_t quadIdxBegin = _quadsSpliters[i].first;
        int32_t quadIdxEnd = _quadsSpliters[i + 1].first;
        int numberOfQuads = quadIdxEnd - quadIdxBegin;

        GLuint texName = _fontAtlas->getTexture(_quadsSpliters[i].second)->getName();
        GL::bindTexture2D(texName);

        glDrawElements(GL_TRIANGLES, (GLsizei)numberOfQuads * 6, GL_UNSIGNED_SHORT, (GLvoid*)(quadIdxBegin * 6 * 2));

        CC_INCREMENT_GL_DRAWN_BATCHES_AND_VERTICES(1, numberOfQuads * 6);
    }

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void MirBatchDrawLabel::updateShaderProgram()
{
    switch (_currLabelEffect)
    {
    case cocos2d::LabelEffect::NORMAL:
        if (_useDistanceField)
            setGLProgramState(GLProgramState::getOrCreateWithGLProgramName(GLProgram::SHADER_NAME_LABEL_DISTANCEFIELD_NORMAL_NO_MV));
        else if (_useA8Shader)
            setGLProgramState(GLProgramState::getOrCreateWithGLProgramName(GLProgram::SHADER_NAME_LABEL_NORMAL_NO_MV));
        else
            setGLProgramState(GLProgramState::getOrCreateWithGLProgramName(GLProgram::SHADER_NAME_POSITION_TEXTURE_COLOR_NO_MVP));

        break;
    case cocos2d::LabelEffect::OUTLINE:
        setGLProgramState(GLProgramState::getOrCreateWithGLProgramName(GLProgram::SHADER_NAME_LABEL_OUTLINE_NO_MV));
        _uniformEffectColor = glGetUniformLocation(getGLProgram()->getProgram(), "u_effectColor");
        break;
    case cocos2d::LabelEffect::GLOW:
        if (_useDistanceField)
        {
            setGLProgramState(GLProgramState::getOrCreateWithGLProgramName(GLProgram::SHADER_NAME_LABEL_DISTANCEFIELD_GLOW_NO_MV));
            _uniformEffectColor = glGetUniformLocation(getGLProgram()->getProgram(), "u_effectColor");
        }
        break;
    default:
        return;
    }

    _uniformTextColor = glGetUniformLocation(getGLProgram()->getProgram(), "u_textColor");
}

MirBatchDrawLabel * MirBatchDrawLabel::createWithTTF(const TTFConfig & ttfConfig)
{
    auto ret = new MirBatchDrawLabel;
    ret->_ttfConfig = ttfConfig;
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

MirBatchDrawLabel::MirBatchDrawLabel()
    : _reusedLetter(nullptr)
    , _textColor(Color3B::WHITE)
    , _effectColor(Color3B::BLACK)
    , _fontAtlas(nullptr)
    , _walkHelper(nullptr)
	, _quadsCount(1)
	, _currDrawCallQuadsCount(0)
	, _currTextureId(-1)
	, _recreateVBOEventListener(nullptr)
{
	if (_quadsCount > 0)
		_quads.resize(_quadsCount);

//#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
//
//	// Need to listen the event only when not use batchnode, because it will use VBO
//	auto listener = EventListenerCustom::create(EVENT_RENDERER_RECREATED, [this](EventCustom* event){
//		/** listen the event that renderer was recreated on Android/WP8 */
//		this->recreateVBO();
//	});
//
//	_eventDispatcher->addEventListenerWithFixedPriority(listener, 1);
//	
//#endif


	_purgeTextureListener = EventListenerCustom::create(FontAtlas::CMD_PURGE_FONTATLAS, [this](EventCustom* event){
        if (_fontAtlas && event->getUserData() == _fontAtlas)
        {
			if (_fontAtlas)
			{
				FontAtlasCache::releaseFontAtlas(_fontAtlas);
			}

            for (auto node : _children)
            {
                MirTextNode * textNode = dynamic_cast<MirTextNode *>(node);
                if (textNode)
                {
                    textNode->resetDirty();
                }
            }
        }
    });
	_eventDispatcher->addEventListenerWithFixedPriority(_purgeTextureListener, 1);


	_resetTextureListener = EventListenerCustom::create(FontAtlas::CMD_RESET_FONTATLAS, [this](EventCustom* event){
		if (_fontAtlas && event->getUserData() == _fontAtlas)
		{
			_fontAtlas = nullptr;
			setTTFConfig(_ttfConfig);
		}
	});
	_eventDispatcher->addEventListenerWithFixedPriority(_resetTextureListener, 2);
}

void MirBatchDrawLabel::recreateVBO()
{
	//updateShaderProgram();

	//glGenBuffers(1, _vbos);
	//_vbos[1] = 0;
	//
	//CHECK_GL_ERROR_DEBUG();
}

bool MirBatchDrawLabel::init()
{
    setTTFConfig(_ttfConfig);

    //glGenBuffers(1, _vbos);
    //_vbos[1] = Director::getInstance()->getRenderer()->getSharedIndicesVBO();
    //resizeIndices(1000); // 预留1000个 quad 的索引, 其实可以共用renderer的
    if (_reusedLetter == nullptr)
    {
        _reusedLetter = Sprite::create();
        _reusedLetter->setOpacityModifyRGB(false);
        _reusedLetter->retain();
        _reusedLetter->setKeepBlendFunc(true);
        _reusedLetter->setAnchorPoint(Vec2::ANCHOR_TOP_LEFT);
    }
    _onDrawFunc = CC_CALLBACK_0(MirBatchDrawLabel::onDraw, this);

    return true;
}

//void MirBatchDrawLabel::resizeIndices(size_t newSize)
//{
//    size_t oldSize = _indices.size() / 6;
//    if (newSize <= oldSize) return;
//
//    _indices.resize(newSize * 6);
//    for (size_t i = oldSize; i <= newSize - 1; i++)
//    {
//        _indices[i * 6 + 0] = i * 4 + 0;
//        _indices[i * 6 + 1] = i * 4 + 1;
//        _indices[i * 6 + 2] = i * 4 + 2;
//        _indices[i * 6 + 3] = i * 4 + 3;
//        _indices[i * 6 + 4] = i * 4 + 2;
//        _indices[i * 6 + 5] = i * 4 + 1;
//    }
//
//    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _vbos[1]);
//    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(short) * _indices.size(), &_indices[0], GL_STATIC_DRAW);
//
//    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
//}


void MirBatchDrawLabel::setFontScale(float fontScale)
{
    _fontScale = fontScale * CC_CONTENT_SCALE_FACTOR();
    Node::setScale(_fontScale);
}

MirBatchDrawLabel::~MirBatchDrawLabel()
{
    //glDeleteBuffers(1, _vbos);
    //_vbos[1] = 0;
    if (_fontAtlas)
    {
        FontAtlasCache::releaseFontAtlas(_fontAtlas);
        _fontAtlas = nullptr;
    }
    CC_SAFE_RELEASE_NULL(_reusedLetter);

	_eventDispatcher->removeEventListener(_purgeTextureListener);
	_eventDispatcher->removeEventListener(_resetTextureListener);

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	Director::getInstance()->getEventDispatcher()->removeEventListener(_recreateVBOEventListener);
#endif
}

bool MirBatchDrawLabel::setTTFConfig(const TTFConfig& ttfConfig)
{
	FontAtlas *newAtlas = FontAtlasCache::getFontAtlasTTF(&ttfConfig);
	if (newAtlas == _fontAtlas)
	{
		FontAtlasCache::releaseFontAtlas(newAtlas);
		return true;
	}

	if (_fontAtlas)
	{
		FontAtlasCache::releaseFontAtlas(_fontAtlas);
		_fontAtlas = nullptr;
	}

    _ttfConfig = ttfConfig;
	_fontAtlas = newAtlas;

	if (!_fontAtlas)
		return false;

    _commonLineHeight = _fontAtlas->getLineHeight();
    _useDistanceField = _ttfConfig.distanceFieldEnabled;
    _useA8Shader = true;

    if (_ttfConfig.outlineSize > 0)
    {
        _ttfConfig.distanceFieldEnabled = false;
        _useDistanceField = false;
        _useA8Shader = false;
        _currLabelEffect = LabelEffect::OUTLINE;
        updateShaderProgram();
    }
    else
    {
        _currLabelEffect = LabelEffect::NORMAL;
        updateShaderProgram();
        if (_ttfConfig.distanceFieldEnabled)
        {
            setFontScale(1.f * _ttfConfig.fontSize / DistanceFieldFontSize);
        }
    }
    /*_spTmp = Sprite::createWithTexture(_fontAtlas->getTexture(0));
    addChild(_spTmp);*/
    return true;
}

void MirBatchDrawLabel::sortAllChildren()
{
    if (_walkHelper != nullptr)
    {
        _reorderChildDirty = false;
        return;
    }

    Node::sortAllChildren();
}

void MirBatchDrawLabel::setPosition(const Vec2 &position)
{
    Node::setPosition(position);
}

void MirBatchDrawLabel::setPosition(float x, float y)
{
    Node::setPosition(x+_baseOffset.x,y+_baseOffset.y);
}
