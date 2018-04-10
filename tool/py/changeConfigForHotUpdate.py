#!/usr/bin/python
#coding=utf-8

#关于 svn 终端指令 http://www.cnblogs.com/netcorner/p/5034006.html

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

#将对应的文件移动到指定的目录  如果是移动文件夹也可以  目录不需要'/'即可
#shutil -- High-level file operations 是一种高层次的文件操作工具
#类似于高级API，而且主要强大之处在于其对文件的复制与删除操作更是比较支持好。


fileList = {'../../../src/app/config.lua', '../../../src/app/config_pre.lua'}
global g_curChannel
global g_curPublish
global g_curLan

while(1):
	print(u'请选择当前版本 1- Ali      2- TaiTan')
	input = raw_input()
	if '1' == input:
		g_curChannel = 1
		break	
	elif '2' == input:
		g_curChannel = 2
		break

while(1):
	print(u'请选择更新渠道 1- 正式服      2- 测试服')
	input = raw_input()
	if '1' == input:
		g_curPublish = 1
		break	
	elif '2' == input:
		g_curPublish = 2
		break

while(1):
	print(u'请选择语言 1- 中文      2- 英文')
	input = raw_input()
	if '1' == input:
		g_curLan = 1
		break	
	elif '2' == input:
		g_curLan = 2
		break

		
data = ''

re_channle_ali = re.compile('(--(\s*))?APP_FOR(\s*)=(\s*)\"BiYin\"')  
re_channle_TaiTan = re.compile('(--(\s*))?APP_FOR(\s*)=(\s*)\"TaiTan\"')

re_lan = re.compile('USE_LANGUAGE(\s*)=(\s*)\"(\w*)\"')

re_debug_mod = re.compile('DEBUG_MOD(\s*)=(\s*)(true|false)')
re_choose_server = re.compile('CAN_CHOOSE_SERVE(\s*)=(\s*)(true|false)')
re_hot_update = re.compile('OPEN_HOT_UPDATE(\s*)=(\s*)(true|false)')
re_hot_update_server = re.compile('HOT_UPDATE_PACKAGE_TEST(\s*)=(\s*)(true|false)')
re_check_during = re.compile('local CheckDuringDay =(\s*)\d')

for path in fileList:
	if os.path.isfile(path):
		with open(path, 'r+') as f:
			lines = f.readlines()
			for line in lines:
				if 1 == g_curChannel:   # 1 Ani
					if re_channle_ali.match(line):
						line = 'APP_FOR = "BiYin"\n'
					if re_channle_TaiTan.match(line):
						line = '-- APP_FOR = "TaiTan"\n'
				elif 2 == g_curChannel:   # 2 Taitan
					if re_channle_ali.match(line):
						line = '-- APP_FOR = "BiYin"\n'
					if re_channle_TaiTan.match(line):
						line = 'APP_FOR = "TaiTan"\n'
				
				if 1 == g_curLan:   # 1 中文
					if re_lan.match(line):
						line = re_lan.sub('USE_LANGUAGE = "CH"', line)
				elif 2 == g_curLan:   # 2 英文
					if re_lan.match(line):
						line = re_lan.sub('USE_LANGUAGE = "EN"', line)
					
				if 1 == g_curPublish:   #1 正式服
					if re_debug_mod.match(line):
						line = re_debug_mod.sub('DEBUG_MOD = false', line)				
					if re_choose_server.match(line):
						line = re_choose_server.sub('CAN_CHOOSE_SERVE = false', line)				
					if re_hot_update.match(line):
						line = re_hot_update.sub('OPEN_HOT_UPDATE = true', line)					
					if re_hot_update_server.match(line):
						line = re_hot_update_server.sub('HOT_UPDATE_PACKAGE_TEST = false', line)
				elif 2 == g_curPublish:
					if re_debug_mod.match(line):
						line = re_debug_mod.sub('DEBUG_MOD = true', line)				
					if re_choose_server.match(line):
						line = re_choose_server.sub('CAN_CHOOSE_SERVE = true', line)				
					if re_hot_update.match(line):
						line = re_hot_update.sub('OPEN_HOT_UPDATE = true', line)
					if re_hot_update_server.match(line):
						line = re_hot_update_server.sub('HOT_UPDATE_PACKAGE_TEST = true', line)
				
				
				if re_check_during.match(line):
					line = re_check_during.sub('local CheckDuringDay = 0', line)		
				
				
				data = data + line
		
		with open(path, 'w') as f:
			f.write(data)
		data = ''

print(u"修改成功")

