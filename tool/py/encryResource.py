#!/usr/bin/python
#coding=utf-8

#���� svn �ն�ָ�� http://www.cnblogs.com/netcorner/p/5034006.html
# http://www.cnblogs.com/jiangzhaowei/p/6138866.html   �ֽ����Ĳ���

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

#����Ӧ���ļ��ƶ���ָ����Ŀ¼  ������ƶ��ļ���Ҳ����  Ŀ¼����Ҫ'/'����
#shutil -- High-level file operations ��һ�ָ߲�ε��ļ���������
#�����ڸ߼�API��������Ҫǿ��֮����������ļ��ĸ�����ɾ���������ǱȽ�֧�ֺá�

enValidType = ['png', 'jpg', 'pvrccz'];
enSrcType = ['lua']
CODE_SIGN = "hello_lx"   #ǩ��
CODE_KEY = "WO_SHI_SHUI"   #����  

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

#���� pic
def EncriptPic(data):
	#���ж��Ƿ�������� 
	dataLen = len(data);
	signLen = len(CODE_SIGN);
	keyLen = len(CODE_KEY);
	
	if dataLen > signLen:
		checkSign = data[(dataLen - signLen):dataLen];
		if checkSign == CODE_SIGN:
			print('has merge')
			return data;#˵����������
			
	data = list(data);
	
	for i in range(keyLen):
		data[i] = chr((ord(data[i])+ord(CODE_KEY[i]))&255);  #����ת��ASC�� Ȼ�����
	data = ''.join(data);
	data += CODE_SIGN;
	return data;
	
#���� pic
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

#���� lua
def EncriptLua(data):
	#���ж��Ƿ�������� 
	dataLen = len(data);   #Ϊ�˺�cocos C++һ�� �ŵ�ǰ��
	signLen = len(CODE_SIGN);
	keyLen = len(CODE_KEY);
	
	if dataLen > signLen:
		checkSign = data[0:signLen];
		if checkSign == CODE_SIGN:
			print('has merge')
			return data;#˵����������
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
			


#����
def MergeFile(fullPath, flag):
	filePath = os.path.split(fullPath) #�ָ��Ŀ¼���ļ�
	vargs = filePath[1].split('.') #�ָ���ļ����ļ���չ��
	
	temp = 0
	if IsResFile(vargs[1]):
		temp = 1    #ͼƬ
	elif IsSrcFile(vargs[1]):
		temp = 2    #����
		
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