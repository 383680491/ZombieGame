先确定几个路径 
	writePath    : cocos2dx可写路径，热更新包会下载到该路径
	res          ：cocos2dx资源路径
	server       : 远程服务器
	hotUpdatePack ：工程根目录下的目录，脚本文件 以及打包生成的包等都在这里 

	scriptePath  : 用来存放打包脚本和打包生成的压缩包的路径
	versioninfo.json ：配置路径 res writePath scriptePath 都会有这个配置文件
	versionlist.json ： 远程服务器上的版本管理文件
	versionlist.dat  ：与服务器版本比较
	uploadVersionList : 上传包的配置文件，在scriptePath文件夹里面

配置文件里面都是这种结构体
	struct = {
		version : 版本号，基于这个来判断热更新版本
		build   ：build版本，如果这个版本与本地不同，则无法热更新，请重新下载游戏
		svn     ：svn版本号，这个可以有很多用途 不用也没关系
		data    ：附加参数
		des     ：描述，比如我测试 写的是liuxiang
		size    : 包大小
	};

1、创建热更新目录
2、通过http协议下载uploadVersionList.json，然后与res目录下面的versioninfo.json进行版本比较。
   如果有需要更新的版本则放到列表里面，同时保存在versionlist.dat并保存到读写目录
3、对更新列表遍历进行下载，可能会下载几个更新包，当所有更新包下载完成后读取versionlist.dat
   数据，获得更新的列表，同时挨个进行解压缩。
4、打包，具体细节看代码比较靠谱
5、res src 严禁中文名字 否则会报错
   
