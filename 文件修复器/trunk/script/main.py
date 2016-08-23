# $Id$

def Start(argv):
	InitPath()

	import log
	log.Init()

	Repair()


def Repair():
	fullbadlst = []
	from md5dic import md5dic
	import C_fls, md5
	for fname in md5dic:
		fobj = C_fls.CFileObject(fname, "full_old.fls")
		real_md5 = md5.md5(gobj.GetData()).hexdigest()
		if real_md5 != md5dic[fname]:
			fullbadlst.append(fname)
	
	if not fullbadlst:
		return
	
	import http
	http.DownLoad(fullbadlst)



g_Step = 1000
def Loop():
	import timer
	timer.Loop()

	import http
	http.Loop()
	
	global g_Step
	if g_Step>0:
		g_Step -=1
		return 0
	return 1


def InitPath():
	import sys
	root = sys.path[0]
	sys.apth.append("%s/lib"%root)

