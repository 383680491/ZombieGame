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
			
#order = r'"C:\Program Files\TortoiseSVN\bin\TortoiseProc.exe" /command:update /path:' + srcPath     #python 这个特别奇怪 我把这个“”转义有问题  查资料写成这样 很有意思 srcPath不能用就用绝对路径
#cmd = subprocess.Popen(order, shell=True, stdout=subprocess.PIPE)
#cmd.wait()
#out = cmd.stdout.readlines()
#for line in out:
#	print line.strip()

#if cmd.returncode != 0:
#	print "Error: svn update fail"

#print('svn 更新成功')			
			

copy(srcPath, destPath)

