#!/usr/bin/python
#coding=utf-8
import re
import os
import time
import sys

#使用zipfile做目录压缩，解压缩功能
#http://blog.csdn.net/linda1000/article/details/10432133
#http://www.oschina.net/code/snippet_89296_9122

#os.walk(top, topdown=True, onerror=None, followlinks=False) 
#可以得到一个三元tupple(dirpath, dirnames, filenames), 
#第一个为起始路径，第二个为起始路径下的文件夹，第三个是起始路径下的文件。
#dirpath 是一个string，代表目录的路径，
#dirnames 是一个list，包含了dirpath下所有子目录的名字。
#filenames 是一个list，包含了非目录文件的名字。
#这些名字不包含路径信息，如果需要得到全路径，需要使用os.path.join(dirpath, name).
 
import zipfile
 
def zip_dir(dirname,zipfilename):
	print(dirname)
	filelist = []
	if os.path.isfile(dirname):
		filelist.append(dirname)
	else:
		for root, dirs, files in os.walk(dirname):
			for name in files:
				filelist.append(os.path.join(root, name))
				a = os.path.join(root, name)
				print(a)
				
	zf = zipfile.ZipFile(zipfilename, "w", zipfile.zlib.DEFLATED)
	for tar in filelist:
		arcname = tar[len(dirname):]
		zf.write(tar,arcname)
	zf.close()




def unzip_file(zipfilename, unziptodir):
	if not os.path.exists(unziptodir): 
		os.mkdir(unziptodir)
		
	zfobj = zipfile.ZipFile(zipfilename)
	for name in zfobj.namelist():
		name = name.replace('\\','/')
		
		if name.endswith('/'):
			os.mkdir(os.path.join(unziptodir, name))
		else:
			ext_filename = os.path.join(unziptodir, name)
			ext_filename = ext_filename.replace('\\','/')
			print(ext_filename)

			ext_dir= os.path.dirname(ext_filename)
			print(ext_dir)
			if not os.path.exists(ext_dir) : 
				os.mkdir(ext_dir)
			with open(ext_filename, 'wb') as file:
				file.write(zfobj.read(name))
				
	
	
	
#判断文件是否相同 即是否被修改过  计算2个文件的MD5值，大文件计算较慢
#http://blog.csdn.net/it_yuan/article/details/23770483
import hashlib

def getHash(f):  
	line=f.readline()  
	hash=hashlib.md5()  
	
	while(line):  
		hash.update(line)  
		line=f.readline()  
	return hash.hexdigest()  
	
def sameFile(f1,f2):  
	str1=getHash(f1)  
	str2=getHash(f2)  
	return str1 == str2  
	
	

	
with open("./aaa/log.txt", "rb") as f1:
	with open("./aaa/logcopy.txt", "rb") as f2:
		if sameFile(f1, f2):
			print("same")
		else:
			print("not same")
	
	
#zip_dir("./aaa", "bbb.zip")

#unzip_file("./bbb.zip", "./bbb")
#os.remove("./bbb.zip")    #解压缩后移除



	
input()
				
				
				
