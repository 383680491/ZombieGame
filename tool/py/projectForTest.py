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


fileList = {'../../../src/app/config.lua', '../../../src/app/config_pre.lua'}

def delete(path):
	if os.path.isdir(path):
		shutil.rmtree(path)
	elif os.path.isfile(path):
		os.remove(path)
	print('ɾ��cache�ɹ�')
		
order = r'"C:\Program Files\TortoiseSVN\bin\TortoiseProc.exe" /command:update /path:' + r'../../../'     #python ����ر���� �Ұ��������ת��������  ������д������ ������˼
cmd = subprocess.Popen(order, shell=True, stdout=subprocess.PIPE)
cmd.wait()
out = cmd.stdout.readlines()
for line in out:
	print line.strip()

if cmd.returncode != 0:
	print "Error: svn update fail"

print('svn ���³ɹ�')

delete('../../../cache')

data = ''

re_debug_mod = re.compile('DEBUG_MOD(\s*)=(\s*)false')
re_choose_server = re.compile('CAN_CHOOSE_SERVE(\s*)=(\s*)false')
re_hot_update = re.compile('OPEN_HOT_UPDATE(\s*)=(\s*)true')

for path in fileList:
	if os.path.isfile(path):
		with open(path, 'r+') as f:
			lines = f.readlines()
			for line in lines:
				if re_debug_mod.match(line):
					line = re_debug_mod.sub('DEBUG_MOD = true', line)				
				if re_choose_server.match(line):
					line = re_choose_server.sub('CAN_CHOOSE_SERVE = true', line)				
				if re_hot_update.match(line):
					line = re_hot_update.sub('OPEN_HOT_UPDATE = false', line)
				
				
				data = data + line
		
		with open(path, 'w') as f:
			f.write(data)
		data = ''
print('�޸ĳɹ�')
#src = r'F:\pub\�����\PB����\lua'
#src = src.replace('\\', '/')
#dest = r"F:\client\client\DzProjectBranchForAli\src\protobuf"
#dest = dest.replace('\\', '/')
#copy(src, dest)

