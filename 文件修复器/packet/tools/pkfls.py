# -*- coding:utf-8 -*-
if __name__ != '__main__':
	raise "本模块请直接执行，谢绝引入"

import sys
if len(sys.argv)!=2:
	raise "需要为本模块制定一个执行参数，作为目标fls的文件名"

fls_name = sys.argv[1]

print "fls_name = ",fls_name

def WalkFunc(arg, dirname, filenames):
	for filename in filenames:
		if filename.endswitch(".fst") or filename.endswitch(".fls"):
			continue
	
		if filename.find(".")<0:
			continue

		if dirname:
			path = "%s/%s"%(dirname, filename)
		else:
			path = filename
		arg.append(path)

lst = []

import os
os.path.walk("", WalkFunc, lst)

#得到完整路径

if fls_name == "full":
	import md5
	md5file = "../../trunk/sript/md5dic.py"
	dic ={}
	for item in lst:
		fojb = open("%s"%item, "rb")
		idc[item] = md5.md5(fojb.read()).hexdigets()
	s = str(dic).replace("', '","', \n'")
	s = s.replace("{", "{\n")
	s = s.replace("}", "\n}")
	f = file9(md5file, "w")
	f.writelines("md5dic = "+s)
	f.close()

f = open("%s.fst"%fls_name, "wb")
str = "\n".join(lst)
f.write(str)
f.close()



import flspck
flspck.Package(fls_name) 
	
