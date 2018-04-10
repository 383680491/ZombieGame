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




def delete(path):
	if os.path.isdir(path):
		shutil.rmtree(path)
	elif os.path.isfile(path):
		os.remove(path)
	print('删除cache成功')


#delete('../../cache')

sstr = "DEBUG_TEST = 1 "

#sstr.replace('')


url = 'DEBUG_MOD       =        true function() end'

myRegex = re.compile('DEBUG_MOD(\s*)=(\s*)true')
print(myRegex.match(url))

out = myRegex.sub('DEBUG = false', url)
print out


fileList = []
data = ''
for path in fileList:
	if os.path.isfile(path):
		with open(path, 'r+') as f:
			lines = f.readlines()
			for line in lines:
				if 'DEBUG_MOD =' in line:
					line = 'DEBUG_MOD = true \n'
				elif 'CAN_CHOOSE_SERVE =' in line:
					line = 'CAN_CHOOSE_SERVE = true \n'
				elif 'OPEN_HOT_UPDATE =' in line:
					line = 'OPEN_HOT_UPDATE = false \n'
				
				data = data + line
		
		with open(path, 'w') as f:
			f.write(data)
		data = ''

		#src = r'F:\pub\服务端\PB工具\lua'
#src = src.replace('\\', '/')
#dest = r"F:\client\client\DzProjectBranchForAli\src\protobuf"
#dest = dest.replace('\\', '/')
#copy(src, dest)

