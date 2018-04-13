#!/usr/bin/python
#coding=utf-8

#���� svn �ն�ָ�� http://www.cnblogs.com/netcorner/p/5034006.html

#F:\client\client\DzProjectBranchForAli>"C:\Program Files\TortoiseSVN\bin\TortoiseProc.exe" /command:update /path:F:\clie
#nt\client\DzProjectBranchForAli

# ������Ŀ¼�е�ͼƬ �滻��studio����  ��ͬ���ֵ��滻 

import shutil
import re
import os
import time
import sys
import subprocess
from PIL import Image
from xml.dom import minidom                 #xml
import math  

reload(sys);
sys.setdefaultencoding( "utf-8" );

#����Ӧ���ļ��ƶ���ָ����Ŀ¼  ������ƶ��ļ���Ҳ����  Ŀ¼����Ҫ'/'����
#shutil -- High-level file operations ��һ�ָ߲�ε��ļ���������
#�����ڸ߼�API��������Ҫǿ��֮����������ļ��ĸ�����ɾ���������ǱȽ�֧�ֺá�
		
descList = []
inType = ['.png', '.jpg']

global g_W
global g_H

while(1):
	print(u'please select base width:')
	input = raw_input()
	g_W = input
	break
while(1):
	print(u'please select base height:')
	input = raw_input()
	g_H = input
	break
	
g_W = int(g_W)
g_H = int(g_H)

def isInType(file):
	for t in inType:
		if file.endswith(t):                                      #�����ж��ַ����Ƿ���ָ����׺��β
			return True;
	return False;

def split(sPath, dPath):
	if not os.path.isdir(sPath):
		return
	
	if not os.path.exists(dPath):
		os.mkdir(dPath)
	
	for root, dirs, files in os.walk(sPath):
		for name in files:
			fullPath = os.path.join(root, name)
			print('start split image')
			if isInType(fullPath):
				print(fullPath + '   will be split')

				s = os.path.split(fullPath)
				fileName = s[1].split('.')
				baseName = fileName[0]
				fileType = fileName[-1]
				
				print('baseName = '+(baseName))
				print('fileType = '+(fileType))
				
				image = Image.open(fullPath)
				width,height = image.size

				print('width = %d'%(width))
				print('height = %d'%(height))
				
				
				doc = minidom.Document()
				imgs = doc.createElement("imgs")
				imgs.setAttribute('tag', '0')
				imgs.setAttribute('width', str(width))
				imgs.setAttribute('height', str(height))
				doc.appendChild(imgs)
				
				if width > g_W and height > g_H:
					temp = float(width) / g_W
					print('temp = %f'%(temp))
					wCount = int(math.ceil(float(width) / g_W))   #pythonҪ����С�� �������һ��ֵ��float
					hCount = int(math.ceil(float(height) / g_H))
					
					print('wCount = %d'%(wCount))
					print('hCount = %d'%(hCount))
					
					for wIndex in range(wCount):
						for hIndex in range(hCount):
							lbX, lbY = wIndex * g_W, hIndex*g_H
							rtX, rtY = (wIndex + 1)*g_W, (hIndex + 1)*g_H
							if rtX > width:
								rtX = width
							
							if rtY > height:
								rtY = height
							
							box = (lbX, lbY, rtX, rtY)
							
							sizeW, sizeH = g_W, g_H
							if hIndex == hCount - 1:
								sizeH = height - hIndex * g_H
							
							if wIndex == wCount - 1:
								sizeW = width - wIndex * g_W
							
							name = '%s#%d_%d_%d_%d.%s' % (baseName, lbX, lbY, sizeW, sizeH, fileType)
							image.crop(box).save(os.path.join(dPath, name), str.upper('png'))         #jpg�޷�֧��
						
							img = doc.createElement("img")
							node = doc.createTextNode(name) #Ԫ������д�� 
							img.appendChild(node)	
							imgs.appendChild(img)	
				
				f = open(dPath + '/' + baseName + ".xml","w")
				f.write(doc.toprettyxml(indent = "\t", newl = "\n", encoding = "utf-8"))  
				f.close()	
				
		
def copy(srcPath, destPath):
	if not os.path.isdir(srcPath):
		return

	if not os.path.exists(destPath):
		os.mkdir(destPath)
		
	for file_name in os.listdir(srcPath):
		srcInfo = os.path.join(srcPath, file_name)
		
		if isInType(file_name):
			for t in descList:
				if t.endswith(file_name):
					shutil.copyfile(srcInfo, t);
					print('move ---- ' + file_name)



dest = r"F:\me\ZombieGame\tool\SplitImage\dest"
src = r'F:\me\ZombieGame\tool\SplitImage\src'
dest = dest.replace('\\', '/')
src = src.replace('\\', '/')

split(src, dest)
