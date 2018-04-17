#pragma once
#include <cocos2d.h>
using namespace std;
USING_NS_CC;
class CGameFunc
{
public:
	CGameFunc();
	~CGameFunc();

	//创建目录
	static void MkDir(const char* sPath);

	//获取工作目录
	static void GetWorkDir(char* sDirPath);

	//执行cmd命令
	static void DoCmd(const char* pszCmd);
	
	//解析ini
	//e.g. 
	//[Main]
	//	luadebug = 1
	//	workingdir = / . /
	static void ParseIniToMap(const char* sFileFullPath, map<string, map<string, string>>& stMap);



	static void LoadIni(const char* sFileFullPath);
	static void GetIniMap(std::map<std::string, std::map<std::string, std::string>>& stMap);
	static void setAccount(string strAcount, string strPwd = "!@#$%123456");
	
	static void getAccount(string& strAccout, string& strPwd);
	 
private:
	static map<string, map<string, string>> stIniCfg;
	static string m_strAccount;
	static string m_strPwd;
};