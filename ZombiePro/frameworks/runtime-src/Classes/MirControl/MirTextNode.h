#ifndef MirLabelTextInfo_h__
#define MirLabelTextInfo_h__

#include "cocos2d.h"

USING_NS_CC;

class MirTextNodeFormatter;
class MirBatchDrawLabel;

/************************************************************************
                    Label计算节点
       只计算_transform 和 _modelviewtransform,但不参与绘制
************************************************************************/
class MirTextNode : public Node
{
    struct LetterInfo
    {
        FontLetterDefinition    def;

        Vec2                    position;
        Size                    contentSize;
        Color3B                 color;

        V3F_C4B_T2F_Quad        quad; // 坐标系为模型坐标系
    };
    enum class LabelType {

        TTF,
        BMFONT,
        CHARMAP,
        STRING_TEXTURE
    };

public:
    MirTextNode(MirBatchDrawLabel * batchedDrawLabel, int32_t zOrder);
    ~MirTextNode();

    void setText(const std::string & text);
    inline void setString(const std::string & text) { setText(text); };

    virtual void visit(Renderer *renderer, const Mat4 &parentTransform, uint32_t parentFlags) override;
    void setLineBreakWithoutSpace(bool breakWithoutSpace);

    virtual const Size& getContentSize() const override;

    virtual void setColor(const Color3B& color) override;

    /*
        @brief 获取总字符数，不包括换行
    */
    inline size_t getLettersCount() { return _lettersInfo.size(); };

    /*
        @brief 为每一个字设置独立的颜色
        @note colors.empty() == true 时关闭此设置
    */
    void setColors(const std::vector<Color3B> & colors);

    /*
        @brief 设置指定区间字符的颜色
        @note  闭区间
    */
    void setRangeColors(Color3B color, int32_t beginIndex, int32_t endIndex);

    inline Vec2 getOffset() { return _offset; };
    inline void setOffset(const Vec2 & offset) { _offset = offset; };

    virtual void setPosition(const Point& pos) override;
	virtual void setPosition(float x, float y) override;
    // 重新初始化
    void resetDirty();
private:
    void updateContent();
    void alignText();
    bool computeHorizontalKernings(const std::u16string& stringToRender);
    void computeStringNumLines();

    bool recordLetterInfo(const cocos2d::Vec2& point, const FontLetterDefinition& letterDef, int spriteIndex);
    bool recordPlaceholderInfo(int spriteIndex);

    void updateQuads();
    virtual void updateColor() override;
    void clearLetters();

    friend class MirBatchDrawLabel;
    friend class MirTextNodeFormatter;
private:
    int32_t                         _zOrder;
    bool                            _contentDirty;
    bool                            _colorDirty;
    bool                            _colorEveryLetter;      // 为每一个字设置独立的颜色

    MirBatchDrawLabel             * _batchDrawLabel;        // 主要使用其 _ttfConfig
    std::string                     _text;
    std::u16string                  _currentUTF16String;
    int                             _limitShowCount;   // 包括自动换行，所以可能跟 _currentUTF16String.size() 不同

    std::vector<LetterInfo>         _lettersInfo;
    unsigned int                    _maxLineWidth;
    bool                            _lineBreakWithoutSpaces;

    TextHAlignment                  _hAlignment;
    TextVAlignment                  _vAlignment;

    int                           * _horizontalKernings; // updateContent 时被赋值, 但微软雅黑字体是没这个玩意儿的
    float                           _commonLineHeight;
    int                             _currNumLines;
    unsigned int                    _labelWidth;
    unsigned int                    _labelHeight;
    float                           _additionalKerning;
    Vec2                            _offset;
};

#endif // MirLabelTextInfo_h__
