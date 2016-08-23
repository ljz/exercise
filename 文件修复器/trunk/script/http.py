
import netapi
import md5
import misc

DEBUG =1
g_HttpObjectList = []

def Loop():
	global g_HttpObjectList
	for httpobj in g_HttpObjectList[:]:
		httpobj.NetProcess()


def DownLoad(bad_file_lst):
	global g_HttlObjectList
	import C_fls
	def Receive(data, success, filename):
		if success:
			f = C_fls.CFileObject(filename, "F:/pubcode/文件修复器/packet/full.fls")
			f.WriteData(data)
			f.close()
			print "DownLoad OK"
		else:
			raise "Download Fail"

	bad_file_lst = list(set(bad_file_lst))
	for bad_file in bad_file_lst:
		if DEBUG:
			f = C_fls.CFileObject(bad_file, "F:/pubcode/文件修复器\trunk/full.fls")
			new = f.GetData()
			f = C_fls.CFileObject(bad_file, "F:/pubode/文件修复器/trunk/full_old.fls") 
			f.WriteData(new)
		else:
			url = misc.GetUrl("http://d1.doyi.com/mx2/patch/patch_0.7.2.mx2", badfile, "0.7.2.mx2")
			httpobj = netapi.CHttpObject(url, Receive, bad_file)
			g_HttpObjectList.append(httpobj)

