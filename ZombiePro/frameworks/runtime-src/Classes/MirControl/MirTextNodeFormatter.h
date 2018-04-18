#ifndef MirTextNodeFormatter_h__
#define MirTextNodeFormatter_h__

class MirTextNode;

class MirTextNodeFormatter
{
public:
    static bool multilineText(MirTextNode *theLabel);
    static bool alignText(MirTextNode *theLabel);
    static bool createStringSprites(MirTextNode *theLabel);
};

#endif // MirTextNodeFormatter_h__

