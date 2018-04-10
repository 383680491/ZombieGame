#!/usr/bin/python
#coding=utf-8

import shutil
import re
import os
import time
import sys


#����Ӧ���ļ��ƶ���ָ����Ŀ¼  ������ƶ��ļ���Ҳ����  Ŀ¼����Ҫ'/'����
#shutil -- High-level file operations ��һ�ָ߲�ε��ļ���������
#�����ڸ߼�API��������Ҫǿ��֮����������ļ��ĸ�����ɾ���������ǱȽ�֧�ֺá�


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
	print('ɾ���ɹ�')
		

src = r"C:/Users/Administrator/AppData/Local/DeZhou/cache/hot"

#copy(src, dest)

dir = os.path.realpath(src)
dir = dir.replace('\\', '/')
#dir = os.path.join(dir, 'log.txt')

delete(dir)