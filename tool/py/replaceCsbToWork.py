#!/usr/bin/python
#coding=utf-8

#���� svn �ն�ָ�� http://www.cnblogs.com/netcorner/p/5034006.html

#F:\client\client\DzProjectBranchForAli>"C:\Program Files\TortoiseSVN\bin\TortoiseProc.exe" /command:update /path:F:\clie
#nt\client\DzProjectBranchForAli

# ������Ŀ¼�е�ͼƬ �滻��studio����  ��ͬ���ֵ��滻 

import shutil
import re
import os
import time
import sys
import subprocess

reload(sys);
sys.setdefaultencoding( "utf-8" );

#����Ӧ���ļ��ƶ���ָ����Ŀ¼  ������ƶ��ļ���Ҳ����  Ŀ¼����Ҫ'/'����
#shutil -- High-level file operations ��һ�ָ߲�ε��ļ���������
#�����ڸ߼�API��������Ҫǿ��֮����������ļ��ĸ�����ɾ���������ǱȽ�֧�ֺá�
		
descList = []
inType = ['.csb', '.plist', '.png']

def isInType(file):
	for t in inType:
		if file.endswith(t):                                      #�����ж��ַ����Ƿ���ָ����׺��β
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

