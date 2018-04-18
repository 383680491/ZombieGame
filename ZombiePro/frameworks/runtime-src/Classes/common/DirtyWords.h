#pragma once
#include "cocos2d.h"

class DirtyWords
{
public:
	DirtyWords(){}
	virtual ~DirtyWords(void){}
	static void Init();
	static bool isHaveDirytWords(const std::string& str);
	static std::string checkAndReplaceDirtyWords(std::string str, const std::string strDst = "****");

private:	
	static std::vector<std::string>   m_Words;
};

