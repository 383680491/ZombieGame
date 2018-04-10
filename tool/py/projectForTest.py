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

def delete(path):
	if os.path.isdir(path):
		shutil.rmtree(path)
	elif os.path.isfile(path):
		os.remove(path)
	print('删除cache成功')
		
order = r'"C:\Program Files\TortoiseSVN\bin\TortoiseProc.exe" /command:update /path:' + r'../../../'     #python 这个特别奇怪 我把这个“”转义有问题  查资料写成这样 很有意思
cmd = subprocess.Popen(order, shell=True, stdout=subprocess.PIPE)
cmd.wait()
out = cmd.stdout.readlines()
for line in out:
	print line.strip()

if cmd.returncode != 0:
	print "Error: svn update fail"

print('svn 更新成功')

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
print('修改成功')
#src = r'F:\pub\服务端\PB工具\lua'
#src = src.replace('\\', '/')
#dest = r"F:\client\client\DzProjectBranchForAli\src\protobuf"
#dest = dest.replace('\\', '/')
#copy(src, dest)

