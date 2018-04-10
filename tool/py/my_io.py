#!/usr/bin/python
#coding=utf-8
import re
import os
import time
import sys

#把aaa目录里面所有 图片格式都在前面加上"lx_"字段
#str.split(string)分割字符串
#'连接符'.join(list) 将列表组成字符串

def batchReplaceContent(path):                         #批量替换
	if not os.path.isdir(path) and not os.path.isfile(path):
		return False
		
		if os.path.isfile(path):
			file_path = os.path.split(path)    #分割文件和目录
			file_name_split = file_path[1].split('.')   #分割文件和文件扩展名
			file_type = file_name_split[-1]           #防止文件里面有多个'.'的存在 直接拿最后一个
			
			type_list = ['txt', 'dat', 'lua', 'plist']
			
			if file_type in type_list :
				with open(file_path, "r+") as f:           #实现文本批量替换  但是效率很低 原理是打开文本 获得行列表 清理文本 然后替换对应文本 然后重新写入
					list = f.readlines()
					f.seek(0)                            #把迭代器返回到文件头部
					f.truncate()                         #清理文件的内容   （至于么 我只是替换文本 还要清理  这种方式肯定是最弱的 到时候学习正则表达式就可以了）
					for item in list:
						item = item.replace('lx_lx_lx_lx_lx_lx_lx_lx', 'lx')
						f.write(item)
			

				
	elif os.path.isdir(path):
		for file_name in os.listdir(path):
			my_rename(os.path.join(path, file_name))   #递归
			
			
			
			

def my_rename(path):           
	if not os.path.isdir(path) and not os.path.isfile(path):
		return False
		
	if os.path.isfile(path):
		file_path = os.path.split(path)    #分割文件和目录
		file_name_split = file_path[1].split('.')   #分割文件和文件扩展名
		file_type = file_name_split[-1]           #防止文件里面有多个'.'的存在 直接拿最后一个
		
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
			my_rename(os.path.join(path, file_name))   #递归
			

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
				
				
				
