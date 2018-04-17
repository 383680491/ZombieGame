#include "DirtyWords.h"

USING_NS_CC;

std::vector<std::string> DirtyWords::m_Words;
void DirtyWords::Init()
{
	m_Words.clear();

	//解析文件
	std::string str = FileUtils::getInstance()->getStringFromFile("res/dirtyWords.dat");
	size_t begin = 0;
	size_t end = 0;
	while(1)
	{
		end = str.find("\r\n",begin);
		if( end == std::string::npos )
			break;

		std::string tmp = str.substr(begin, end - begin);
		if(tmp.size() > 0)
            m_Words.push_back(tmp);
		begin = end + 2;
	}
}

bool DirtyWords::isHaveDirytWords(const std::string& str)
{
	if (str.empty())
		return false;

	size_t pos = 0;
	for (unsigned int i = 0; i < m_Words.size(); i++)
	{
		if (m_Words[i].size() > str.size())
			continue;

		pos = str.find(m_Words[i]);
		if (pos != std::string::npos)
			return true;
	}

	return false;
}


std::string DirtyWords::checkAndReplaceDirtyWords(std::string str, const std::string strDst)
{
	if (str.empty())
		return str;

	std::string::size_type pos = 0;
	for (unsigned int i = 0; i < m_Words.size(); i++)
	{
		if (m_Words[i].size() > str.size())
			continue;

		while ( (pos = str.find(m_Words[i])) != std::string::npos)
		{
			str.replace(pos, m_Words[i].length(), strDst);
			pos += strDst.length();
		}
	}


	return str;
}