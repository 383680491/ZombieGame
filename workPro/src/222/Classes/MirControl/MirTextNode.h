#ifndef MirLabelTextInfo_h__
#define MirLabelTextInfo_h__

#include "cocos2d.h"

USING_NS_CC;

class MirTextNodeFormatter;
class MirBatchDrawLabel;

/************************************************************************
                    Label����ڵ�
       ֻ����_transform �� _modelviewtransform,�����������
************************************************************************/
class MirTextNode : public Node
{
    struct LetterInfo
    {
        FontLetterDefinition    def;

        Vec2                    position;
        Size                    contentSize;
        Color3B                 color;

        V3F_C4B_T2F_Quad        quad; // ����ϵΪģ������ϵ
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
        @brief ��ȡ���ַ���������������
    */
    inline size_t getLettersCount() { return _lettersInfo.size(); };

    /*
        @brief Ϊÿһ�������ö�������ɫ
        @note colors.empty() == true ʱ�رմ�����
    */
    void setColors(const std::vector<Color3B> & colors);

    /*
        @brief ����ָ�������ַ�����ɫ
        @note  ������
    */
    void setRangeColors(Color3B color, int32_t beginIndex, int32_t endIndex);

    inline Vec2 getOffset() { return _offset; };
    inline void setOffset(const Vec2 & offset) { _offset = offset; };

    virtual void setPosition(const Point& pos) override;
	virtual void setPosition(float x, float y) override;
    // ���³�ʼ��
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
    bool                            _colorEveryLetter;      // Ϊÿһ�������ö�������ɫ

    MirBatchDrawLabel             * _batchDrawLabel;        // ��Ҫʹ���� _ttfConfig
    std::string                     _text;
    std::u16string                  _currentUTF16String;
    int                             _limitShowCount;   // �����Զ����У����Կ��ܸ� _currentUTF16String.size() ��ͬ

    std::vector<LetterInfo>         _lettersInfo;
    unsigned int                    _maxLineWidth;
    bool                            _lineBreakWithoutSpaces;

    TextHAlignment                  _hAlignment;
    TextVAlignment                  _vAlignment;

    int                           * _horizontalKernings; // updateContent ʱ����ֵ, ��΢���ź�������û����������
    float                           _commonLineHeight;
    int                             _currNumLines;
    unsigned int                    _labelWidth;
    unsigned int                    _labelHeight;
    float                           _additionalKerning;
    Vec2                            _offset;
};

#endif // MirLabelTextInfo_h__
