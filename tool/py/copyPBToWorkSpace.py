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
		
order = r'"C:\Program Files\TortoiseSVN\bin\TortoiseProc.exe" /command:update /path:' + r'F:\pub\�����\PB����\protoc'     #python ����ر���� �Ұ��������ת��������  ������д������ ������˼
cmd = subprocess.Popen(order, shell=True, stdout=subprocess.PIPE)
cmd.wait()
out = cmd.stdout.readlines()
for line in out:
	print line.strip()

if cmd.returncode != 0:
	print "Error: svn update fail"

print('svn ���³ɹ�')


#order = r'cmd.exe F:\\pub\\�����\\PB����\\pb_window\\pb_lua\\protoc-gen-lua\\buildproto.bat'
path = r"F:\pub\�����\PB����\pb_window\pb_lua\protoc-gen-lua"
order = os.path.join(path, 'buildproto.bat')
os.chdir(path)
cmd = subprocess.Popen('buildproto.bat', shell=True, stdout=subprocess.PIPE)   #shell=True �൱��ִ����cmd.exe /c   
cmd.wait()
if cmd.returncode != 0:
	print "Error: ����pb�ļ� fail"


print('����pb�ļ��ɹ�')

#src = r'F:\pub\�����\PB����\lua'
#src = src.replace('\\', '/')
#dest = r"F:\client\client\DzProjectBranchForAli\src\protobuf"
#dest = dest.replace('\\', '/')
#copy(src, dest)

