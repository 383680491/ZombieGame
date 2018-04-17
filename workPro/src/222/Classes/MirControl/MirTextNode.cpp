#include "MirTextNode.h"
#include "MirBatchDrawLabel.h"
#include "MirTextNodeFormatter.h"

#ifndef RENDER_IN_SUBPIXEL
#   if CC_SPRITEBATCHNODE_RENDER_SUBPIXEL
#       define RENDER_IN_SUBPIXEL
#   else
#       define RENDER_IN_SUBPIXEL(__ARGS__) (ceil(__ARGS__))
#   endif
#endif

void MirTextNode::setText(const std::string & text)
{
    if (text != _text)
    {
        _text = text;
        clearLetters();
        _contentDirty = true;
    }
}

void MirTextNode::updateContent()
{
    if (_batchDrawLabel == nullptr) return;

    std::u16string utf16String;
    if (StringUtils::UTF8ToUTF16(_text, utf16String))
    {
        _currentUTF16String = utf16String;
    }

    computeStringNumLines();
    computeHorizontalKernings(_currentUTF16String);
    alignText();

    _contentDirty = false;
}

void MirTextNode::alignText()
{
    if (_batchDrawLabel == nullptr) return;
    
    FontAtlas * fontAtlas = _batchDrawLabel->getFontAtlas();
    if (fontAtlas == nullptr || _currentUTF16String.empty()) return;

    fontAtlas->prepareLetterDefinitions(_currentUTF16String);

    MirTextNodeFormatter::createStringSprites(this);
    if (_maxLineWidth > 0 && _contentSize.width > _maxLineWidth && MirTextNodeFormatter::multilineText(this))
        MirTextNodeFormatter::createStringSprites(this);

    if (_labelWidth > 0 || (_currNumLines > 1 && _hAlignment != TextHAlignment::LEFT))
        MirTextNodeFormatter::alignText(this);

    updateQuads();
    updateColor();
}

void MirTextNode::setLineBreakWithoutSpace(bool breakWithoutSpace)
{

}

bool MirTextNode::computeHorizontalKernings(const std::u16string& stringToRender)
{
    if (_horizontalKernings)
    {
        delete[] _horizontalKernings;
        _horizontalKernings = nullptr;
    }

    int letterCount = 0;
    _horizontalKernings = _batchDrawLabel->getFontAtlas()->getFont()->getHorizontalKerningForTextUTF16(stringToRender, letterCount);

    if (!_horizontalKernings)
        return false;
    else
        return true;
}

void MirTextNode::computeStringNumLines()
{
    int quantityOfLines = 1;

    if (_currentUTF16String.empty())
    {
        _currNumLines = 0;
        return;
    }

    // count number of lines
    size_t stringLen = _currentUTF16String.length();
    for (size_t i = 0; i < stringLen - 1; ++i)
    {
        if (_currentUTF16String[i] == '\n')
        {
            quantityOfLines++;
        }
    }

    _currNumLines = quantityOfLines;
}

bool MirTextNode::recordLetterInfo(const cocos2d::Vec2& point, const FontLetterDefinition& letterDef, int spriteIndex)
{
    if (static_cast<std::size_t>(spriteIndex) >= _lettersInfo.size())
    {
        LetterInfo tmpInfo;
        _lettersInfo.push_back(tmpInfo);
    }

    _lettersInfo[spriteIndex].def = letterDef;
    _lettersInfo[spriteIndex].position = point;
    _lettersInfo[spriteIndex].contentSize.width = _lettersInfo[spriteIndex].def.width;
    _lettersInfo[spriteIndex].contentSize.height = _lettersInfo[spriteIndex].def.height;
    _limitShowCount++;

    return _lettersInfo[spriteIndex].def.validDefinition;
}

bool MirTextNode::recordPlaceholderInfo(int spriteIndex)
{
    if (static_cast<std::size_t>(spriteIndex) >= _lettersInfo.size())
    {
        LetterInfo tmpInfo;
        _lettersInfo.push_back(tmpInfo);
    }

    _lettersInfo[spriteIndex].def.validDefinition = false;
    _limitShowCount++;

    return false;
}

void MirTextNode::updateQuads()
{
    Rect letterRect;
    Sprite * reusedLetter = _batchDrawLabel->_reusedLetter;
    CCASSERT(reusedLetter != nullptr, "MirTextNode::updateQuads: reusedLetter can not be nullptr");

    for (auto & letterInfo: _lettersInfo)
    {
        if (letterInfo.def.validDefinition == false) continue;

        auto & letterDef = letterInfo.def;
        letterRect.size.height = letterDef.height;
        letterRect.size.width = letterDef.width;
        letterRect.origin.x = letterDef.U;
        letterRect.origin.y = letterDef.V;

        reusedLetter->setPosition(letterInfo.position);
        reusedLetter->setTexture(_batchDrawLabel->getFontAtlas()->getTexture(letterDef.textureID));
        reusedLetter->setTextureRect(letterRect, false, letterRect.size);

        auto & transform = reusedLetter->getNodeToParentTransform();

        auto quad = reusedLetter->getQuad();
        {
            Size &size = letterRect.size;
            Vec2 offsetPos = reusedLetter->getOffsetPosition();

            float x1 = offsetPos.x;
            float y1 = offsetPos.y;

            float x2 = x1 + size.width;
            float y2 = y1 + size.height;
            float x = transform.m[12];
            float y = transform.m[13];

            float cr = transform.m[0];
            float sr = transform.m[1];
            float cr2 = transform.m[5];
            float sr2 = -transform.m[4];
            float ax = x1 * cr - y1 * sr2 + x;
            float ay = x1 * sr + y1 * cr2 + y;

            float bx = x2 * cr - y1 * sr2 + x;
            float by = x2 * sr + y1 * cr2 + y;

            float cx = x2 * cr - y2 * sr2 + x;
            float cy = x2 * sr + y2 * cr2 + y;

            float dx = x1 * cr - y2 * sr2 + x;
            float dy = x1 * sr + y2 * cr2 + y;

            quad.bl.vertices = Vec3(RENDER_IN_SUBPIXEL(ax), RENDER_IN_SUBPIXEL(ay), _positionZ);
            quad.br.vertices = Vec3(RENDER_IN_SUBPIXEL(bx), RENDER_IN_SUBPIXEL(by), _positionZ);
            quad.tl.vertices = Vec3(RENDER_IN_SUBPIXEL(dx), RENDER_IN_SUBPIXEL(dy), _positionZ);
            quad.tr.vertices = Vec3(RENDER_IN_SUBPIXEL(cx), RENDER_IN_SUBPIXEL(cy), _positionZ);
        }
        // update color
        letterInfo.quad = quad;
    }
}

void MirTextNode::updateColor()
{
    if (_colorEveryLetter)
    {
        for (auto & letterInfo : _lettersInfo)
        {
            Color4B color4(letterInfo.color);
            color4.a = _displayedOpacity;

            letterInfo.quad.bl.colors = color4;
            letterInfo.quad.tl.colors = color4;
            letterInfo.quad.br.colors = color4;
            letterInfo.quad.tr.colors = color4;
        }
    }
    else
    {
        Color4B color4(_displayedColor.r, _displayedColor.g, _displayedColor.b, _displayedOpacity);

        for (auto & letterInfo : _lettersInfo)
        {
            letterInfo.quad.bl.colors = color4;
            letterInfo.quad.tl.colors = color4;
            letterInfo.quad.br.colors = color4;
            letterInfo.quad.tr.colors = color4;
        }
    }
}

const Size& MirTextNode::getContentSize() const
{
    if (_contentDirty)
    {
        const_cast<MirTextNode*>(this)->updateContent();
    }
    return _contentSize;
}

MirTextNode::MirTextNode(MirBatchDrawLabel * batchedDrawLabel, int32_t zOrder)
    : _contentDirty(true)
    , _colorDirty(true)
    , _limitShowCount(0)
    , _maxLineWidth(0)
    , _lineBreakWithoutSpaces(false)
    , _horizontalKernings(nullptr)
    , _commonLineHeight(0)
    , _currNumLines(0)
    , _labelWidth(0)
    , _labelHeight(0)
    , _additionalKerning(0.f)
    , _colorEveryLetter(false)
    , _offset(Vec2::ZERO)
	, _hAlignment(TextHAlignment::LEFT)
	, _vAlignment(TextVAlignment::TOP)
{
    setAnchorPoint(Vec2::ANCHOR_MIDDLE);
    _batchDrawLabel = batchedDrawLabel;
    _zOrder = zOrder;
}

MirTextNode::~MirTextNode()
{
    delete[] _horizontalKernings;
}

void MirTextNode::visit(Renderer *renderer, const Mat4 &parentTransform, uint32_t parentFlags)
{
    if (!_visible)
    {
        return;
    }

    processParentFlags(parentTransform, parentFlags);
    if (_contentDirty)
    {
        updateContent();
    }
}

void MirTextNode::setColors(const std::vector<Color3B> & colors)
{
    if (colors.empty())
    {
        _colorEveryLetter = false;
        return;
    }

    _colorEveryLetter = true;
    size_t minSize = std::min(colors.size(), _lettersInfo.size());
    for (size_t i = 0; i < minSize; i++)
    {
        _lettersInfo[i].color = colors[i];
    }

    if (minSize < _lettersInfo.size())
    {
        for (size_t i = minSize; i < _lettersInfo.size(); i++)
        {
            _lettersInfo[i].color = _displayedColor;
        }
    }
    updateColor();
}

void MirTextNode::setColor(const Color3B& color)
{
    _colorEveryLetter = false;
    Node::setColor(color);
}

void MirTextNode::setRangeColors(Color3B color, int32_t beginIndex, int32_t endIndex)
{
    if (beginIndex > endIndex || endIndex < 0 || endIndex > (int32_t)_lettersInfo.size() - 1)
        return;
    
    _colorEveryLetter = true;

    for (int32_t i = beginIndex; i <= endIndex; i++)
    {
        _lettersInfo[i].color = color;
    }
    updateColor();
}

void MirTextNode::setPosition(const Point& pos)
{
    Node::setPosition(pos);
}

void MirTextNode::setPosition(float x, float y)
{
    Node::setPosition(x+_offset.x,y+_offset.y);
}

void MirTextNode::clearLetters()
{
    _lettersInfo.clear();
    _limitShowCount = 0;
}

void MirTextNode::resetDirty()
{
    clearLetters();
    _contentDirty = true;
}
