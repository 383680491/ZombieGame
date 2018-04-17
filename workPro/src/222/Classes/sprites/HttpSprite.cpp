#include "HttpSprite.h"
#include "network/HttpRequest.h"
#include "network/HttpClient.h"

USING_NS_CC;
using namespace cocos2d::network;

HttpSprite::HttpSprite(void)
{
	m_request = nullptr;
	base_url.clear();
}


HttpSprite *HttpSprite::create(const std::string&pszFileName,const std::string&imgurl)
{
    HttpSprite *pRet = new HttpSprite();
    if (pRet && pRet->initWithFile(pszFileName))
    {
		pRet->GetHttpImg(imgurl);
        pRet->autorelease();
        return pRet;
    }
    else
    {
        CC_SAFE_DELETE(pRet);
        return NULL;
    }
}


void HttpSprite::GetHttpImg(const std::string&imgurl)
{
	SpriteFrame *cache_spframe = SpriteFrameCache::getInstance()->getSpriteFrameByName(imgurl);
	if( cache_spframe != nullptr )
	{
		setTexture(cache_spframe->getTextureReal());
		return;
	}
	base_url = imgurl;
    m_request = new HttpRequest();
	//m_request->retain();
    // required fields
    m_request->setUrl(imgurl.c_str());
    m_request->setRequestType(HttpRequest::Type::GET);
	m_request->setResponseCallback(CC_CALLBACK_2(HttpSprite::onHttpRequestRptImg, this));
    //HttpClient::getInstance()->sendImmediate(request);
    HttpClient::getInstance()->send(m_request);
}

void HttpSprite::onHttpRequestRptImg(HttpClient *sender,HttpResponse *response)
{
	if(m_request != nullptr)
	{
		m_request->release();
		m_request = nullptr;
	}
    if (!response)
    {
        return;
    }
    if (!response->isSucceed())
    {
        log("response failed");
        log("error buffer: %s", response->getErrorBuffer());
        return;
    }
    
    std::vector<char> *buffer = response->getResponseData();
    
    //create image
    Image* img = new Image;
    img->initWithImageData((unsigned char*)buffer->data(),buffer->size());
    
    //create texture
    Texture2D* texture = new Texture2D();
    bool isImg = texture->initWithImage(img);
    img->release();
	setTexture(texture);
	buffer->clear();
	SpriteFrame *frame = SpriteFrame::createWithTexture(texture,Rect(0,0,texture->getContentSize().width,texture->getContentSize().height));
	if(frame != nullptr && base_url.size()>0 )
		SpriteFrameCache::getInstance()->addSpriteFrame(frame,base_url);
	base_url.clear(); 
	texture->release();
}

HttpSprite::~HttpSprite(void)
{
	if(m_request != nullptr)
	{
		m_request->setResponseCallback(nullptr);
		m_request->release();
	}
	base_url.clear(); 
}