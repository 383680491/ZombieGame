#ifndef MirLabelDrawNode_h__
#define MirLabelDrawNode_h__

#include "cocos2d.h"
#include "MirTextNode.h"

USING_NS_CC;

class MirWalkable : public Node
{
public:
    /*
    @brief 自定义遍历子节点依次调用 callback
    @param callback 遍历子节点需要调用的方法
    @param sender 要求遍历的对象，通过 sender->getName() 方法判断需要遍历的数据
    */
    virtual void walk(std::function<void(Node *)> callback, Node * sender) = 0;
};

/************************************************************************
                  同一节点下批量绘制同一种效果label的组件
                     要求必须使用同样的 TTfConfig
************************************************************************/
class MirBatchDrawLabel : public Node
{
public:
    static MirBatchDrawLabel * createWithTTF(const TTFConfig & ttfConfig);

    virtual ~MirBatchDrawLabel();

    MirTextNode * createLabel(const std::string& text, int32_t zOrder, const Vec2 & pos);

    void removeLabel(MirTextNode * lbl);

    /*
        @brief 覆盖 Node 的排序，使用 MirActorMgr 的排序
    */
    virtual void sortAllChildren() override;

    virtual void visit(Renderer *renderer, const Mat4 &parentTransform, uint32_t parentFlags) override;
    virtual void draw(Renderer *renderer, const Mat4 &transform, uint32_t flags) override;

    inline FontAtlas * getFontAtlas() { return _fontAtlas; };

    bool setTTFConfig(const TTFConfig& ttfConfig);
    const TTFConfig& getTTFConfig() const { return _ttfConfig; }

    //virtual void sortAllChildren() override;

    inline void setTextColor(Color3B color) { _textColor = color; };
    inline void setEffectColor(Color3B color) { _effectColor = color; };

    inline Vec2    getBaseOffset() { return _baseOffset; };
    inline void    setBaseOffset(Vec2 baseOffset) { _baseOffset = baseOffset; };

    virtual void setPosition(const Vec2 &position) override;
	virtual void setPosition(float x, float y) override;
    inline void setWalkHelper(MirWalkable * walkHelper) { _walkHelper = walkHelper; };

protected:
    void updateShaderProgram();
	void recreateVBO();

private:
    MirBatchDrawLabel();
    virtual bool init() override;

    void onDraw();
    //void resizeIndices(size_t newSize);

    void setFontScale(float fontScale);

    friend class MirTextNode;
private:
    TTFConfig                        _ttfConfig;
    bool                             _zOrderIsDirty;
    FontAtlas                      * _fontAtlas;

    CustomCommand                                   _cmd;
    std::vector<V3F_C4B_T2F_Quad>                   _quads;
    size_t                                          _quadsCount;
    uint32_t                                        _currDrawCallQuadsCount; // 当前 drawcall 的 quad 数目
    int                                             _currTextureId;

    /*
        @brief _quads里不同textureId的分隔索引，用于快速切换Texture
        @param first quad begin index
        @param second textureId, get texture name by [_fontAtlas->getTexture(textureId)->getName()]
    */
    std::vector<std::pair< int32_t, int32_t>>       _quadsSpliters;
    //std::vector<short>                              _indices;
    //GLuint                                          _vbos[2];

    uint8_t                                         _quadBuff[sizeof(V3F_C4B_T2F_Quad)];

    LabelEffect _currLabelEffect;
    bool _useDistanceField;
    bool _useA8Shader;
    GLuint _uniformEffectColor;
    GLuint _uniformTextColor;
    float _fontScale;
    float _commonLineHeight;

    Color3B     _textColor;
    Color3B     _effectColor;

    Vec2              _baseOffset;

    Sprite          * _reusedLetter; // 用来偷懒的一个玩意

    MirWalkable     * _walkHelper;

    std::function<void()>   _onDrawFunc;

	EventListenerCustom* _recreateVBOEventListener;
	EventListenerCustom* _purgeTextureListener;
	EventListenerCustom* _resetTextureListener;

    static const int DistanceFieldFontSize;
};
#endif // MirLabelDrawNode_h__