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

dictoryList = [r'F:\pub\服务端\配置表导出文件_必赢\client', r'F:\pub\服务端\配置表导出文件_测试\client', r'F:\pub\服务端\配置表导出文件_泰坦\client']

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
	print('请选择目录')
	print('           1、配置表导出文件-必赢')
	print('           2、配置表导出文件-测试')
	print('           3、配置表导出文件-泰坦')
	
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
order = r'"C:\Program Files\TortoiseSVN\bin\TortoiseProc.exe" /command:update /path:' + dic     #python 这个特别奇怪 我把这个“”转义有问题  查资料写成这样 很有意思
cmd = subprocess.Popen(order, shell=True, stdout=subprocess.PIPE)
cmd.wait()
if cmd.returncode != 0:
	print "Error: svn update fail"

print('svn 更新成功')

while(1):
	print('请选择当前版本 1- Ali      2- TaiTan')
	
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
