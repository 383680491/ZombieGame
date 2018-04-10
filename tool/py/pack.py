#!/usr/bin/python
#coding=utf-8
import re
import os
import time
import sys

#ʹ��zipfile��Ŀ¼ѹ������ѹ������
#http://blog.csdn.net/linda1000/article/details/10432133
#http://www.oschina.net/code/snippet_89296_9122

#os.walk(top, topdown=True, onerror=None, followlinks=False) 
#���Եõ�һ����Ԫtupple(dirpath, dirnames, filenames), 
#��һ��Ϊ��ʼ·�����ڶ���Ϊ��ʼ·���µ��ļ��У�����������ʼ·���µ��ļ���
#dirpath ��һ��string������Ŀ¼��·����
#dirnames ��һ��list��������dirpath��������Ŀ¼�����֡�
#filenames ��һ��list�������˷�Ŀ¼�ļ������֡�
#��Щ���ֲ�����·����Ϣ�������Ҫ�õ�ȫ·������Ҫʹ��os.path.join(dirpath, name).
 
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
				
	
	
	
#�ж��ļ��Ƿ���ͬ ���Ƿ��޸Ĺ�  ����2���ļ���MD5ֵ�����ļ��������
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
#os.remove("./bbb.zip")    #��ѹ�����Ƴ�



	
input()
				
				
				
