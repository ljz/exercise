# -*- coding:utf-8 -*-
import hashlib
import os, sys

#检测大文件的MD5值
def GetFileMd5(filename):
	if not os.path.isfile(filename):
		return
	myhash = hashlib.md5()
	f = file(filename, 'rb')
	while True:
		b = f.read(8096)
		if not b:
			break
		myhash.update(b)
	f.close()
	return myhash.hexdigest()

def test():
	print "11111"
	file_object = open("checkmd5.txt", 'w')
	rootdir = "./"
	for parent, dirnames, filenames in os.walk(rootdir):
		print "parent == ",parent
		for filename in filenames:
			print 'filename == ',filename
			fullname = os.path.join(parent, filename)
			Md5 = GetFileMd5(fullname)
			file_object.write(fullname)
			file_object.write("\n")
			file_object.write(Md5)
			file_object.write("\n")

	file_object.close()

if __name__ == '__main__':
	test()
