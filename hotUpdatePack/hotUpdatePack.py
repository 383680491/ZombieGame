#!/usr/bin/python
#coding=utf-8

#使用zipfile做目录压缩，解压缩功能
#http://blog.csdn.net/linda1000/article/details/10432133
#http://www.oschina.net/code/snippet_89296_9122

#os.walk(top, topdown=True, onerror=None, followlinks=False) 
#可以得到一个三元tupple(dirpath, dirnames, filenames), 
#第一个为起始路径，第二个为起始路径下的文件夹，第三个是起始路径下的文件。
#dirpath 是一个string，代表目录的路径，
#dirnames 是一个list，包含了dirpath下所有子目录的名字。
#filenames 是一个list，包含了非目录文件的名字。
#这些名字不包含路径信息，如果需要得到全路径，需要使用os.path.join(dirpath, name).

#原理：先与脚本目录下的versioninfo.json与res下面的热更新配置进行比较 如果大于res下面的
#版本则使用该版本配置，找到需要热更新的目录，获取每一个文件的md5值并以名字为键值保存起来，判断文件是否被
#修改或者是否为最新文件，打包这些文件

import os;
import re
import time
import sys
import json
import hashlib
import zipfile

reload(sys);
sys.setdefaultencoding( "utf-8" );

makePkgPath = './makePkg/'
localVersionFullPath = '../workPro/res/versioninfo.json'
hotVersionFullPath = makePkgPath + 'versioninfo.json'
hotMd5FullPath = makePkgPath + 'md5.json'
projectPath='../workPro';
checkScrPath = [projectPath + '/src', projectPath + '/res']   #这个是以projectPath为目标主要是 因为 获得fullPath后 找到src 或者 res 文件名称 例如（src\main.lua  而不是单独的main.lua）
hotVersionList = makePkgPath + 'uploadVersionList.json'   #用来上传给服务器的热更新配置列表
ignoreType = ['.ccb','.h','.cpp','.c','.proto','.csd','.css','.ccs','.udf','.dll','.lib','.exe','.bat','.cc','res\\versioninfo.json'];
ignoreDictory = []   #如果是必赢则只要必赢的配置 泰坦的就过滤掉 'json_BiYin', 'json_TaiTan'
#游戏里有两种配置 必赢和泰坦 

global isBase
isBase = False

global g_curChannel    #当前版本渠道

while(1):
	print(u'请选择当前版本 1- Ali      2- TaiTan')
	getValue = raw_input()
	if '1' == getValue:
		g_curChannel = 1
		ignoreDictory.insert(0, 'json_TaiTan')
		break	
	elif '2' == getValue:
		g_curChannel = 2
		ignoreDictory.insert(0, 'json_BiYin')
		break
	

#创建文件夹  生成的文件放入该文件夹
def createBaseDic():
	if not os.path.exists(makePkgPath):
		os.makedirs(makePkgPath)

#获得文件的md5值


def md5sum(fname): 
    #""" 计算文件的MD5值 """ 
    def read_chunks(fh): 
        fh.seek(0) 
        chunk = fh.read(8096) 
        while chunk: 
            yield chunk 
            chunk = fh.read(8096) 
        else: #最后要将游标放回文件开头 
            fh.seek(0) 
    m = hashlib.md5() 
    if isinstance(fname, basestring) and os.path.exists(fname): 
        with open(fname, "rb") as fh: 
            for chunk in read_chunks(fh): 
                m.update(chunk) 
    #上传的文件缓存 或 已打开的文件流 
    elif fname.__class__.__name__ in ["StringIO", "StringO"] or isinstance(fname, file): 
        for chunk in read_chunks(fname): 
            m.update(chunk) 
    else: 
        return "" 
    return m.hexdigest()
	
	
	
	
	
def getHash(f):  
	#line=f.readline()  
	data = f.read()
	hash=hashlib.md5()  
	hash.update(data) 
	
	#while(line):  
	#	hash.update(line)  
	#	line=f.readline()  
		
	return hash.hexdigest()  
	
def sameFile(f1,f2):  
	str1=getHash(f1)  
	str2=getHash(f2)  
	return str1 == str2  
	
#先无视目录ignoreDictory 然后无视后缀ignoreType
def isIgnore(file):
	for t in ignoreDictory:
		if -1 != file.find(t, 0, len(file)):     #-1则没有找到  
			if isBase:
				print(u'过滤了文件 = ' + file)
			return True;

	for t in ignoreType:
		if file.endswith(t):                                      #用于判断字符串是否以指定后缀结尾
			return True;
	return False;
	
	


#判断res下是否有versioninfo.json 有的话就直接拷贝过来 同时 版本加1 如果没有则创建该文件执行同样的逻辑
def getVersionInfo():
	info = None
	
	if not os.path.isfile(hotVersionFullPath):
		info = {}
		
		if not os.path.isfile(localVersionFullPath):
			info['des'] = 'liuxiang'
			info['data'] = 0
			info['svn'] = 0
			info['version'] = 1
			info['build'] = 1
			info['size'] = 0
			info['restart'] = 0
			
			temp = info
			temp = json.dumps(info);
			localVersion = open(localVersionFullPath, 'w+')
			localVersion.write(temp);
			localVersion.close()
		else:
			localVersion = open(localVersionFullPath, 'r+')
			info = localVersion.read()
			info = json.loads(info)
			localVersion.close()
		
		temp = info
		temp = json.dumps(temp);
		hotVersion = open(hotVersionFullPath, 'w+')
		hotVersion.write(temp);
		hotVersion.close()
		
		list = [];
		list.append(info);
		upHandle = open(hotVersionList, 'w+')
		upHandle.write(json.dumps(list))
		upHandle.close()
	else:
		localVersion = open(hotVersionFullPath, 'r+')
		info = localVersion.read()
		info = json.loads(info)
		
	return info
	
createBaseDic()
versionInfo = getVersionInfo()		
versionInfo['version'] = versionInfo['version'] + 1


#遍历需要热更新目录的文件 进行md5值比较 是否相同   同时以fullPath为键值保存文件的md5值 以方便之后的比较

def checkMd5():
	Md5List = None
	
	if not os.path.isfile(hotMd5FullPath):
		Md5List = {}
		
		global isBase
		isBase = True
		print('hotMd5FullPath not exist')
	else:
		handle = open(hotMd5FullPath, 'r')
		Md5List = handle.read()
		handle.close()
		
		if Md5List == '': 
			Md5List = {}
		else:
			Md5List = json.loads(Md5List)
	
	sourceMd5List = {}
	zipList = [];
	zipFullList = [];
	
	packageType = 1
	
	if not isBase:
		while(1):
			print(u'请选择打包方式(请尽量选择1)：')
			print(u'           1、修改增量打包')
			print(u'           2、单独src打包')
			print(u'           3、单独res打包')
			
			getValue = raw_input()
			if '1' == getValue:
				packageType = 1
				break	
			elif '2' == getValue:
				packageType = 2
				break
			elif '3' == getValue:
				packageType = 3
				break
	
	if 1 == packageType:
		for sPath in checkScrPath:
			for root, dirs, files in os.walk(sPath):
				for name in files:
					fullPath = os.path.join(root, name);
					if not isIgnore(fullPath):
						md5 = md5sum(fullPath)
						sourceMd5List[fullPath] = md5
						
						#每次打热更新包都会把当前的checkScrPath里面的文件打包，生成zip文件，这样子以后回滚方便
						zipFullList.append(fullPath);
						
						if Md5List.has_key(fullPath):
							if md5 != Md5List[fullPath]:
								print(fullPath + '    has modified')
								zipList.append(fullPath);
						else:
							print(fullPath + '    is new file')
							zipList.append(fullPath);
	elif 2 == packageType or 3 == packageType:
		tempPath = (projectPath + '/src') if packageType == 2 else (projectPath + '/lastRes')    #三目运算
		
		for sPath in checkScrPath:
			if sPath == tempPath:
				for root, dirs, files in os.walk(sPath):
					for name in files:
						fullPath = os.path.join(root, name);
						if not isIgnore(fullPath):
							md5 = md5sum(fullPath)
							sourceMd5List[fullPath] = md5
							
							#每次打热更新包都会把当前的checkScrPath里面的文件打包，生成zip文件，这样子以后回滚方便
							zipFullList.append(fullPath);
							zipList.append(fullPath);
			else:
				for root, dirs, files in os.walk(sPath):
					for name in files:
						fullPath = os.path.join(root, name);
						if not isIgnore(fullPath):
							md5 = md5sum(fullPath)
							sourceMd5List[fullPath] = Md5List[fullPath]
							
							#每次打热更新包都会把当前的checkScrPath里面的文件打包，生成zip文件，这样子以后回滚方便
							zipFullList.append(fullPath);
							
							
							
							
							
							

	handle = open(hotMd5FullPath, 'w')
	handle.write(json.dumps(sourceMd5List));
	handle.close()
	
	return zipList, zipFullList
	
#进行压缩 
def compress(zipList, zipFullList):
	if 0 == len(zipList):
		print('no file has modified')
		return False
		
	zipName = ''
	global isBase
	
	if not isBase:
		timestamp = time.time()
		timestruct = time.localtime(timestamp)
		name = makePkgPath + time.strftime('%Y-%m-%d-%H-%M', timestruct) + '.zip'  # 2016-12-22 10:49:57
		
		zip = zipfile.ZipFile(name, 'w');
		for fullName in zipFullList:
			headLen=len(projectPath + '/')
			fileName = fullName[headLen:len(fullName)]
			
			handle = open(fullName, 'rb')
			data = handle.read();
			handle.close()
			
			zip.writestr(fileName, data)
			
		zip.close(); 
	
	
	if isBase:
		zipName = makePkgPath + 'base.zip'
	else:
		zipName = makePkgPath + 'zeus_' + str(versionInfo['build']) + '_' + str(versionInfo['version']) + '.zip'
		
	newZip = zipfile.ZipFile(zipName, 'w');

	for fullName in zipList:
		headLen=len(projectPath + '/')
		fileName = fullName[headLen:len(fullName)]  #例如../../newProject_0824/src\\errorcode.lua 截取   fileName =  src\\errorcode.lua
		
		handle = open(fullName, 'rb')
		data = handle.read();
		handle.close()
		
		newZip.writestr(fileName, data)          #写入字符串 直到写完后执行 close 才关闭结束
		
	newZip.close(); 
	
	totalsize='%d'% (os.path.getsize(zipName)/1024) +'k';
	versionInfo['size'] = os.path.getsize(zipName)/1024
	print('zip file size==' + totalsize)
	
	return True

zipList, zipFullList = checkMd5()
flag = compress(zipList, zipFullList)

if flag:
	if not isBase:
		hotVersion = open(hotVersionFullPath, 'w+')   #打包需要的配置
		hotVersion.write(json.dumps(versionInfo));
		hotVersion.close()
		
		if not os.path.isfile(hotVersionList):
			list = [];
			list.append(versionInfo);
			
			handle = open(hotVersionList, 'w+')
			handle.write(json.dumps(list));
			handle.close()
		else:
			handle = open(hotVersionList, 'r+')  #热更新上传需要的配置
			info = handle.read()
			
			if info == '': 
				info = []
			else:
				info = json.loads(info)
			
			handle.close()
			
			info.append(versionInfo)
			
			handle = open(hotVersionList, 'w+')
			handle.write(json.dumps(info));
			handle.close()
	
		
		
		
		
		
		
		