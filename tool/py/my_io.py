#!/usr/bin/python
#coding=utf-8
import re
import os
import time
import sys

#��aaaĿ¼�������� ͼƬ��ʽ����ǰ�����"lx_"�ֶ�
#str.split(string)�ָ��ַ���
#'���ӷ�'.join(list) ���б�����ַ���

def batchReplaceContent(path):                         #�����滻
	if not os.path.isdir(path) and not os.path.isfile(path):
		return False
		
		if os.path.isfile(path):
			file_path = os.path.split(path)    #�ָ��ļ���Ŀ¼
			file_name_split = file_path[1].split('.')   #�ָ��ļ����ļ���չ��
			file_type = file_name_split[-1]           #��ֹ�ļ������ж��'.'�Ĵ��� ֱ�������һ��
			
			type_list = ['txt', 'dat', 'lua', 'plist']
			
			if file_type in type_list :
				with open(file_path, "r+") as f:           #ʵ���ı������滻  ����Ч�ʺܵ� ԭ���Ǵ��ı� ������б� �����ı� Ȼ���滻��Ӧ�ı� Ȼ������д��
					list = f.readlines()
					f.seek(0)                            #�ѵ��������ص��ļ�ͷ��
					f.truncate()                         #�����ļ�������   ������ô ��ֻ���滻�ı� ��Ҫ����  ���ַ�ʽ�϶��������� ��ʱ��ѧϰ������ʽ�Ϳ����ˣ�
					for item in list:
						item = item.replace('lx_lx_lx_lx_lx_lx_lx_lx', 'lx')
						f.write(item)
			

				
	elif os.path.isdir(path):
		for file_name in os.listdir(path):
			my_rename(os.path.join(path, file_name))   #�ݹ�
			
			
			
			

def my_rename(path):           
	if not os.path.isdir(path) and not os.path.isfile(path):
		return False
		
	if os.path.isfile(path):
		file_path = os.path.split(path)    #�ָ��ļ���Ŀ¼
		file_name_split = file_path[1].split('.')   #�ָ��ļ����ļ���չ��
		file_type = file_name_split[-1]           #��ֹ�ļ������ж��'.'�Ĵ��� ֱ�������һ��
		
		type_list = ['bmp', 'jpg', 'png', 'psd', 'jpeg', 'gif']
		
		if file_type in type_list :
			newFileName = file_path[0] + '/lx_' + file_path[1]
			
			#newFileName = file_path[1].replace("lx_lx_lx_lx_lx_lx_lx_", "")
			#newFileName = file_path[0] + newFileName
			os.rename(path, newFileName)
			
			logPath = file_path[0] + "/log.txt"
			temp = 'lx_' + file_path[1]
			with open(logPath, "a+") as f:
				f.write(temp)
				f.write('\n')
				
			
	elif os.path.isdir(path):
		for file_name in os.listdir(path):
			my_rename(os.path.join(path, file_name))   #�ݹ�
			

lastDir = './aaa/'
realLastDir = os.path.realpath(lastDir)
realLastDir = realLastDir.replace('\\', '/')

logPath = os.path.join(realLastDir, 'log.txt')
logTestPath = os.path.join(realLastDir, 'log_1.txt')

#if os.path.isfile(logPath):
#	os.remove(logPath)

#my_rename(realLastDir)

with open(logPath, "r") as f:
	print("fuck =====" + f.encoding)
	

with open(logTestPath, 'r') as f:
	content = f.read()
	s = re.findall(r'[0-9]+',content)
	print(s)
#partition = re.compile('')

	


	
	
	
	
	
	
input()
				
				
				
