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

def copy(srcPath, destPath):
	if not os.path.isdir(srcPath):
		return

	if not os.path.exists(destPath):
		os.mkdir(destPath)
		
	for file_name in os.listdir(srcPath):
		if file_name.endswith('.lua'):
			srcInfo = os.path.join(srcPath, file_name)
			print('copy ---- ' + file_name)
			shutil.copyfile(srcInfo, destPath + '/' + file_name);	

srcPath = r"../proto"
destPath = r"../../../workPro/src/net/MessageFile"
			
#order = r'"C:\Program Files\TortoiseSVN\bin\TortoiseProc.exe" /command:update /path:' + srcPath     #python ����ر���� �Ұ��������ת��������  ������д������ ������˼ srcPath�����þ��þ���·��
#cmd = subprocess.Popen(order, shell=True, stdout=subprocess.PIPE)
#cmd.wait()
#out = cmd.stdout.readlines()
#for line in out:
#	print line.strip()

#if cmd.returncode != 0:
#	print "Error: svn update fail"

#print('svn ���³ɹ�')			
			

copy(srcPath, destPath)

