#!/usr/bin/python
#coding=utf-8

#关于 svn 终端指令 http://www.cnblogs.com/netcorner/p/5034006.html
# http://www.cnblogs.com/jiangzhaowei/p/6138866.html   字节流的操作

#F:\client\client\DzProjectBranchForAli>"C:\Program Files\TortoiseSVN\bin\TortoiseProc.exe" /command:update /path:F:\clie
#nt\client\DzProjectBranchForAli

import shutil
import re
import os
import time
import sys
import subprocess
import struct
import xxtea


reload(sys);
sys.setdefaultencoding( "utf-8" );

#将对应的文件移动到指定的目录  如果是移动文件夹也可以  目录不需要'/'即可
#shutil -- High-level file operations 是一种高层次的文件操作工具
#类似于高级API，而且主要强大之处在于其对文件的复制与删除操作更是比较支持好。

enValidType = ['png', 'jpg', 'pvrccz'];
enSrcType = ['lua']
CODE_SIGN = "hello_lx"   #签名
CODE_KEY = "WO_SHI_SHUI"   #加密  

def IsResFile(fileName):
	for t in enValidType:
		if fileName.endswith(t):
			return True
	return False
	
def IsSrcFile(fileName):
	for t in enSrcType:
		if fileName.endswith(t):
			return True
	return False

#加密 pic
def EncriptPic(data):
	#先判断是否混淆过了 
	dataLen = len(data);
	signLen = len(CODE_SIGN);
	keyLen = len(CODE_KEY);
	
	if dataLen > signLen:
		checkSign = data[(dataLen - signLen):dataLen];
		if checkSign == CODE_SIGN:
			print('has merge')
			return data;#说明混淆过了
			
	data = list(data);
	
	for i in range(keyLen):
		data[i] = chr((ord(data[i])+ord(CODE_KEY[i]))&255);  #两个转成ASC码 然后相加
	data = ''.join(data);
	data += CODE_SIGN;
	return data;
	
#解密 pic
def DecodePic(data):
	dataLen = len(data);
	signLen = len(CODE_SIGN);
	keyLen = len(CODE_KEY);

	if dataLen > signLen:
		checkSign = data[(dataLen - signLen):dataLen]
		if checkSign == CODE_SIGN:
			validData = data[0:(dataLen - signLen)];
			validData = list(validData)
			for i in range(keyLen):
				validData[i] = chr((ord(validData[i]) - ord(CODE_KEY[i]))&255);
				
			validData = ''.join(validData);
			return validData;

#加密 lua
def EncriptLua(data):
	#先判断是否混淆过了 
	dataLen = len(data);   #为了和cocos C++一致 放到前面
	signLen = len(CODE_SIGN);
	keyLen = len(CODE_KEY);
	
	if dataLen > signLen:
		checkSign = data[0:signLen];
		if checkSign == CODE_SIGN:
			print('has merge')
			return data;#说明混淆过了
	print('EncriptLua')
	data = xxtea.encrypt(data, CODE_KEY)
	data = CODE_SIGN + data
	return data		
			
def DecodeLua(data):
	dataLen = len(data);
	signLen = len(CODE_SIGN);
	keyLen = len(CODE_KEY);
	
	print('dataLen = %d' % (dataLen) )
	print('keyLen = %d' % (keyLen) )
	if dataLen > signLen:
		checkSign = data[0:signLen]
		print('checkSign = %s', checkSign)
		if checkSign == CODE_SIGN:
			print('DecodeLua3333333333')
			data = data[signLen:dataLen]
			data = xxtea.decrypt(data, CODE_KEY);  
			return data
			


#混淆
def MergeFile(fullPath, flag):
	filePath = os.path.split(fullPath) #分割出目录与文件
	vargs = filePath[1].split('.') #分割出文件与文件扩展名
	
	temp = 0
	if IsResFile(vargs[1]):
		temp = 1    #图片
	elif IsSrcFile(vargs[1]):
		temp = 2    #代码
		
	if temp == 0:
		return
	
	with open(fullPath, 'rb') as f:
		info = f.read()
		
		if 1 == flag:
			if temp == 1:
				info = EncriptPic(info)
			else:
				info = EncriptLua(info)
		else:
			if temp == 1:
				info = DecodePic(info)	
			else:
				info = DecodeLua(info)	
		
		with open(fullPath, 'wb') as f1:
			f1.write(info)


def workDic(path, type):
	for root, dirs, files in os.walk(path):
		for name in files:
			fullPath = os.path.join(root, name);
			MergeFile(fullPath, type)
				
				
global g_input		
while(1):
	print(u'1--encode      2--decode')
	input = raw_input()
	if '1' == input:
		g_input = 1
		break	
	elif '2' == input:
		g_input = 2
		break
	

path = r"G:\game\workPro\res\face2"
workDic(path, g_input)