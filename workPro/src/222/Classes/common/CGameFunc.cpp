#include "CGameFunc.h"
#ifdef WIN32
#include <psapi.h>
#include <direct.h>
#else
#include <sys/stat.h>
#endif
using namespace std;

map<string, map<string, string>> CGameFunc::stIniCfg;
string CGameFunc::m_strAccount = "";
string CGameFunc::m_strPwd = "";
CGameFunc::CGameFunc()
{
}

CGameFunc::~CGameFunc()
{
}

void CGameFunc::MkDir(const char* sPath)
{
#ifdef WIN32
	_mkdir(sPath);
#else
/*
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
	mkdir(sPath, 0777);
#endif*/
#endif
}

void CGameFunc::GetWorkDir(char* sDirPath)
{
#ifdef WIN32
	GetCurrentDirectoryA(255, (LPSTR)sDirPath);
#endif // WIN32
}

void CGameFunc::DoCmd(const char* pszCmd)
{
#ifdef WIN32
	UINT nRet = ::WinExec(pszCmd, SW_HIDE);
	CCLOG("nRet[%u]", nRet);
#endif
}

void CGameFunc::ParseIniToMap(const char* sFileFullPath, map<string, map<string, string>>& stMap)
{
#ifdef WIN32
	const int iVectorSize = 1024;
	char strAppNameTemp[iVectorSize];//所有AppName的返回值  
	char strKeyNameTemp[iVectorSize];//对应每个AppName的所有KeyName的返回值  
	char strReturnTemp[iVectorSize];//返回值  
	DWORD dwKeyNameSize;//对应每个AppName的所有KeyName的总长度  
	DWORD dwAppNameSize = GetPrivateProfileStringA(NULL, NULL, NULL, strAppNameTemp, iVectorSize, sFileFullPath);
	if (dwAppNameSize > 0)
	{
		char* pAppName = new char[dwAppNameSize];
		int iAppNameLenth = 0;
		for (int i = 0; i < dwAppNameSize; i++)
		{
			pAppName[iAppNameLenth++] = strAppNameTemp[i];
			if (strAppNameTemp[i] == '\0')
			{
				map<string, string>* stSubMap = new map<string, string>();
				dwKeyNameSize = GetPrivateProfileStringA(pAppName, NULL, NULL, strKeyNameTemp, iVectorSize, sFileFullPath);
				if (dwKeyNameSize > 0)
				{
					char* pKeyName = new char[dwKeyNameSize];
					int iKeyNameLenth = 0;
					for (int j = 0; j < dwKeyNameSize; j++)
					{
						pKeyName[iKeyNameLenth++] = strKeyNameTemp[j];
						if (strKeyNameTemp[j] == '\0')
						{
							if (GetPrivateProfileStringA(pAppName, pKeyName, NULL, strReturnTemp, iVectorSize, sFileFullPath))
							{
								(*stSubMap).insert(map<string, string>::value_type(pKeyName, strReturnTemp));
							}
							memset(pKeyName, 0, dwKeyNameSize);
							iKeyNameLenth = 0;
						}
					}
					delete[]pKeyName;
				}
				stMap.insert(map<string, map<string, string>>::value_type(string(pAppName), *stSubMap));

				memset(pAppName, 0, dwAppNameSize);
				iAppNameLenth = 0;
			}
		}
		delete[]pAppName;
	}
#endif
}

void CGameFunc::LoadIni(const char* sFileFullPath)
{
#ifdef WIN32
	CGameFunc::ParseIniToMap(sFileFullPath, stIniCfg);
#endif
}

void CGameFunc::GetIniMap(std::map<std::string, std::map<std::string, std::string>>& stMap)
{
#ifdef WIN32
	if (!stIniCfg.empty())
	{
		std::map<std::string, std::map<std::string, std::string>>::iterator it;
		for (it = stIniCfg.begin(); it != stIniCfg.end(); it++)
		{
			stMap.insert(std::map<std::string, std::map<std::string, std::string>>::value_type(it->first, it->second));
		}
	}
#endif
}
 
void CGameFunc::getAccount(string& strAccout, string& strPwd)
{
#ifdef WIN32
	strAccout = m_strAccount;
	strPwd = m_strPwd;
#endif
}

void CGameFunc::setAccount(string strAcount, string strPwd /* = "!@#$%123456" */)
{
#ifdef WIN32
	m_strAccount = strAcount;
	m_strPwd = strPwd;
#endif

}