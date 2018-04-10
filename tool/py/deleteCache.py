#!/usr/bin/python
#coding=utf-8

import shutil
import re
import os
import time
import sys


#将对应的文件移动到指定的目录  如果是移动文件夹也可以  目录不需要'/'即可
#shutil -- High-level file operations 是一种高层次的文件操作工具
#类似于高级API，而且主要强大之处在于其对文件的复制与删除操作更是比较支持好。


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
		shutil.copyfile(srcInfo, destPath + '/' + file_name);		
		
		
def delete(path):
	if os.path.isdir(path):
		shutil.rmtree(path)
	elif os.path.isfile(path):
		os.remove(path)
	print('删除成功')
		

src = r"C:/Users/Administrator/AppData/Local/DeZhou/cache/hot"

#copy(src, dest)

dir = os.path.realpath(src)
dir = dir.replace('\\', '/')
#dir = os.path.join(dir, 'log.txt')

delete(dir)