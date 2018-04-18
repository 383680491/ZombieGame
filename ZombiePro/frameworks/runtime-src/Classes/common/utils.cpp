#include "cocos2d.h"
#include "utils.h"
#include "md5.h"

//hex 长度需要大于等于 2 * len + 1

inline char toHex(unsigned char x)
{
    if (x <= 9)
        return x + '0';
    
    return x - 10 + 'a';
}

inline char toChar(char x)
{
    if (x <= '9')
        return x - '0';
    
    return x - 'a' + 10;
}

void hexEncode(const char* str, int len, char* hex)
{
    for (unsigned int i = 0; i < len; i++)
    {
        hex[i*2] = toHex( ((unsigned char)str[i]) >> 4 );
        hex[i*2 + 1] = toHex( ((unsigned char)str[i]) & 0x0f );
    }
    
    hex[len*2] = 0;
}

//str 长度需要大于等于 len / 2 + 1
bool hexDecode(const char* hex, int len, char* str)
{
    //长度必须是偶数
    if (len & 0x01)
        return false;
    
    for (unsigned int i = 0; i < len; i += 2)
    {
        str[i/2] = (toChar(hex[i]) << 4) + toChar(hex[i+1]);
    }
    
    return true;
}

void getMd5HexStr(const void* data, int len, char hexstr[33])
{
    md5_state_t ctx;
    md5_init(&ctx);
    md5_append(&ctx, (const md5_byte_t*)data, len);

    unsigned char digest[16];
    md5_finish(&ctx, digest);
    
    hexEncode((const char*)digest, 16, hexstr);
}
