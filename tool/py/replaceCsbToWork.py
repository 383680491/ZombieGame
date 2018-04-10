#!/usr/bin/python
#coding=utf-8

#关于 svn 终端指令 http://www.cnblogs.com/netcorner/p/5034006.html

#F:\client\client\DzProjectBranchForAli>"C:\Program Files\TortoiseSVN\bin\TortoiseProc.exe" /command:update /path:F:\clie
#nt\client\DzProjectBranchForAli

# 把美术目录中的图片 替换到studio工程  相同名字的替换 

import shutil
import re
import os
import time
import sys
import subprocess

reload(sys);
sys.setdefaultencoding( "utf-8" );

#将对应的文件移动到指定的目录  如果是移动文件夹也可以  目录不需要'/'即可
#shutil -- High-level file operations 是一种高层次的文件操作工具
#类似于高级API，而且主要强大之处在于其对文件的复制与删除操作更是比较支持好。
		
descList = []
inType = ['.csb', '.plist', '.png']

def isInType(file):
	for t in inType:
		if file.endswith(t):                                      #用于判断字符串是否以指定后缀结尾
			return True;
	return False;

def getDescPath(sPath):
	i = 0
	for root, dirs, files in os.walk(sPath):
		for name in files:
			fullPath = os.path.join(root, name)
			if isInType(fullPath):
				print(fullPath + '   will be copy')
				descList.insert(i, fullPath)
				i = i + 1
		
def copy(srcPath, destPath):
	if not os.path.isdir(srcPath):
		return

	if not os.path.exists(destPath):
		os.mkdir(destPath)
		
	for root, dirs, files in os.walk(srcPath):
		for file_name in files:
			fullPath = os.path.join(root, file_name)
			if isInType(fullPath):
				for t in descList:
					if t.endswith(file_name):
						shutil.copyfile(fullPath, t);
						print('move ---- ' + file_name)
		



src = r"F:\client\client\studioFiles_English\2_studios\Game_base\res"
dest = r'F:\client\client\Dz_English\lastRes'
dest = dest.replace('\\', '/')
src = src.replace('\\', '/')

getDescPath(dest)
copy(src, dest)

