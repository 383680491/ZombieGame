#!/usr/bin/python
#coding=utf-8

#���� svn �ն�ָ�� http://www.cnblogs.com/netcorner/p/5034006.html

#F:\client\client\DzProjectBranchForAli>"C:\Program Files\TortoiseSVN\bin\TortoiseProc.exe" /command:update /path:F:\clie
#nt\client\DzProjectBranchForAli

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

dictoryList = [r'F:\pub\�����\���ñ����ļ�_��Ӯ\client', r'F:\pub\�����\���ñ����ļ�_����\client', r'F:\pub\�����\���ñ����ļ�_̩̹\client']

global dictory
global channelType

def move(srcPath, destPath):
	if not os.path.isdir(srcPath):
		return

	if not os.path.exists(destPath):
		os.mkdir(destPath)
		
	for file_name in os.listdir(srcPath):
		srcInfo = os.path.join(srcPath, file_name)
		os.rename(srcInfo, destPath + '/' + file_name);
		
		
		
def copy(srcPath, destPath):
	if not os.path.isdir(srcPath):
		return

	if not os.path.exists(destPath):
		os.mkdir(destPath)
		
	for file_name in os.listdir(srcPath):
		srcInfo = os.path.join(srcPath, file_name)
		print('move ---- ' + file_name)
		shutil.copyfile(srcInfo, destPath + '/' + file_name);	


while(1):
	print('��ѡ��Ŀ¼')
	print('           1�����ñ����ļ�-��Ӯ')
	print('           2�����ñ����ļ�-����')
	print('           3�����ñ����ļ�-̩̹')
	
	getValue = raw_input()
	if '1' == getValue:
		dictory = 0
		break	
	elif '2' == getValue:
		dictory = 1
		break
	elif '3' == getValue:
		dictory = 2
		break
		
dic = dictoryList[dictory]
order = r'"C:\Program Files\TortoiseSVN\bin\TortoiseProc.exe" /command:update /path:' + dic     #python ����ر���� �Ұ��������ת��������  ������д������ ������˼
cmd = subprocess.Popen(order, shell=True, stdout=subprocess.PIPE)
cmd.wait()
if cmd.returncode != 0:
	print "Error: svn update fail"

print('svn ���³ɹ�')

while(1):
	print('��ѡ��ǰ�汾 1- Ali      2- TaiTan')
	
	getValue = raw_input()
	if '1' == getValue:
		channelType = 1
		break	
	elif '2' == getValue:
		channelType = 2
		break

src = dictoryList[dictory]


if 1 == channelType:
	dest = r"F:\client\client\DzProjectBranchForAli\lastRes\json_BiYin"
	dest = dest.replace('\\', '/')
	copy(src, dest)
else:
	dest = r"F:\client\client\DzProjectBranchForAli\lastRes\json_TaiTan"
	dest = dest.replace('\\', '/')
	copy(src, dest)
