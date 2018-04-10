import re
import os
import time
import sys

#把aaa目录里面所有 图片格式都在前面加上"lx_"字段
#str.split(string)分割字符串
#'连接符'.join(list) 将列表组成字符串

def my_rename(path):           
	if not os.path.isdir(path) and not os.path.isfile(path):
		return False
		
	if os.path.isfile(path):
		file_path = os.path.split(path)    #分割文件和目录
		file_name_split = file_path[1].split('.')   #分割文件和文件扩展名
		file_type = file_name_split[-1]           #防止文件里面有多个'.'的存在 直接拿最后一个
		
		type_list = ['bmp', 'jpg', 'png', 'psd', 'jpeg', 'gif']
		
		if file_type in type_list :
			newFileName = file_path[0] + '/lx_' + file_path[1]     #这里自定义
			
			#tempName = newFileName.replace("lx_lx_lx_", "")
			os.rename(path, newFileName)
			
			logPath = file_path[0] + "/log.txt"    #保存日志
			temp = 'lx_' + file_path[1]
			with open(logPath, "a+") as f:
				f.write(temp)
				f.write('\n')
				
			
	elif os.path.isdir(path):
		for file_name in os.listdir(path):
			my_rename(os.path.join(path, file_name))   #递归
			
#start = time.time()

lastDir = './aaa/'
realLastDir = os.path.realpath(lastDir)
realLastDir = realLastDir.replace('\\', '/')          #window路径改为程序格式路径        转义
my_rename(realLastDir)

input()
				
				
				
