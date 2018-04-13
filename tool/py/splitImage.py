#!/usr/bin/python
#coding=utf-8

#关于 svn 终端指令 http://www.cnblogs.com/netcorner/p/5034006.html

#F:\client\client\DzProjectBranchForAli>"C:\Program Files\TortoiseSVN\bin\TortoiseProc.exe" /command:update /path:F:\clie
#nt\client\DzProjectBranchForAli

# 把美术目录中的图片 替换到studio工程  相同名字的替换 

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

#将对应的文件移动到指定的目录  如果是移动文件夹也可以  目录不需要'/'即可
#shutil -- High-level file operations 是一种高层次的文件操作工具
#类似于高级API，而且主要强大之处在于其对文件的复制与删除操作更是比较支持好。
		
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
		if file.endswith(t):                                      #用于判断字符串是否以指定后缀结尾
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
					wCount = int(math.ceil(float(width) / g_W))   #python要保留小数 必须得有一个值是float
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
							image.crop(box).save(os.path.join(dPath, name), str.upper('png'))         #jpg无法支持
						
							img = doc.createElement("img")
							node = doc.createTextNode(name) #元素内容写入 
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
