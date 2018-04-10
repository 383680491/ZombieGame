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
		
order = r'"C:\Program Files\TortoiseSVN\bin\TortoiseProc.exe" /command:update /path:' + r'F:\pub\服务端\PB工具\protoc'     #python 这个特别奇怪 我把这个“”转义有问题  查资料写成这样 很有意思
cmd = subprocess.Popen(order, shell=True, stdout=subprocess.PIPE)
cmd.wait()
out = cmd.stdout.readlines()
for line in out:
	print line.strip()

if cmd.returncode != 0:
	print "Error: svn update fail"

print('svn 更新成功')


#order = r'cmd.exe F:\\pub\\服务端\\PB工具\\pb_window\\pb_lua\\protoc-gen-lua\\buildproto.bat'
path = r"F:\pub\服务端\PB工具\pb_window\pb_lua\protoc-gen-lua"
order = os.path.join(path, 'buildproto.bat')
os.chdir(path)
cmd = subprocess.Popen('buildproto.bat', shell=True, stdout=subprocess.PIPE)   #shell=True 相当于执行了cmd.exe /c   
cmd.wait()
if cmd.returncode != 0:
	print "Error: 生成pb文件 fail"


print('生成pb文件成功')

#src = r'F:\pub\服务端\PB工具\lua'
#src = src.replace('\\', '/')
#dest = r"F:\client\client\DzProjectBranchForAli\src\protobuf"
#dest = dest.replace('\\', '/')
#copy(src, dest)

