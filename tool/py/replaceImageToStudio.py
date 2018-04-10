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
inType = ['.png', '.jpg']

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
		
	for file_name in os.listdir(srcPath):
		srcInfo = os.path.join(srcPath, file_name)
		
		if isInType(file_name):
			for t in descList:
				if t.endswith(file_name):
					shutil.copyfile(srcInfo, t);
					print('move ---- ' + file_name)
				
		



order = r'"C:\Program Files\TortoiseSVN\bin\TortoiseProc.exe" /command:update /path:' + r'F:\art\外部文件\新版界面切片英文版\drawable-xhdpi'     #python 这个特别奇怪 我把这个“”转义有问题  查资料写成这样 很有意思
cmd = subprocess.Popen(order, shell=True, stdout=subprocess.PIPE)
cmd.wait()
if cmd.returncode != 0:
	print "Error: svn update fail"

print('svn 更新成功')



dest = r"F:\client\client\studioFiles_English\1_初始资源图\img"
src = r'F:\art\外部文件\新版界面切片英文版\drawable-xhdpi'
dest = dest.replace('\\', '/')
src = src.replace('\\', '/')

getDescPath(dest)
copy(src, dest)

