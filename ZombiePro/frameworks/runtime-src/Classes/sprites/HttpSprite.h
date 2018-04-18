#ifndef _SPIRIT_HTTP_H_
#define _SPIRIT_HTTP_H_

#include "cocos2d.h"


NS_CC_BEGIN
namespace network {
	class HttpClient;
	class HttpResponse;
	class HttpRequest;
}
NS_CC_END

class HttpSprite : public cocos2d::Sprite
{
public: 
	HttpSprite();
	virtual ~HttpSprite(void);
	static HttpSprite* create(const std::string&pszFileName,const std::string&url);
	void GetHttpImg(const std::string&imgurl);
	void onHttpRequestRptImg(cocos2d::network::HttpClient *sender,cocos2d::network::HttpResponse *response);
private:
	cocos2d::network::HttpRequest* m_request;
	std::string base_url;
};
#endif