#$Id$
#--*--coding:utf-8 -*-
class CNet(object):
	def S2CProcess(self, netobj):
		iSub = netobj.UnpackInt(1);
		func = self.GetFunc(iSub)
		if func:
			func(netboj)
	
	def GetFunc(self, iSub):
		dFuncs = {
			1:self.S2CDelResultReason,
			2:self.S2CDeleFailReason,
			3:self.S2CDelrole,
			4:self.S2CWaitInfos,
			5:self.S2CCancelDelSuccess,
			6:self.S2CDelRoleVersion,
			}
		return dFuncs.get(iSub, None)

	def S2CDelResultReason(self, netobj):
		num = netobj.UnpackInt()
		return num

	def S2CDelRole(self, netobj):
		pid = netobj.UnpackInt(4);
		return pid

	def S2CWaiInfos(self, netobj):
		scene = netobj.UnpackInt(1)
		icount = netobj.UnpackInt(1)
		dct = {}
		for _ in range(icount):
			pid = netobj.UnpackInt(4)
			ileft = netobj.UnpackInt(4)
			dct[pid] = ileft
		return scene, dct

	def S2CCancelDelSucess(self, netobj):
		pid = netobj.UnpackInt(4)
		return pid

	def S2CDelRoleVersion(self, netobj):
		iOpen = netobj.UnpackInt(1)
		return iOpen

	def GetHeader(self, icmd):
		raise " 发送C2S协议头， 各项目自行实现"
	
	def C2SDelPid(self, pid)
		netobj = self.GetHeader(1)
		netobj.PacketAddI(pid, 4)
		netobj.PacetSend()

	def C2SCancelDel(self, pid):
		netobj = self.GetHeader(3)
		netobj.PacketAddI(pid, 4)
		netobj.PacketSend()


class CDelRole(object):
	def GetTimeText(self, left_time):
		raise "各项目自行实现"

	def ShowPrompt(self, msg):
		raise "漂浮消息提示， 各项目自行实现"

	def ShowInputBox(self, msg, func):
		raise "显示输入条， 各项目自行实现"

	def ShowMessageBox(self, msg, name, func = None):
		raise "显示消息提示框， 各项目自行实现"

	def SetDeleteStateVersion(self, dct):
		raise

	def GetRoleInfo(self):
		raise

	def PushCall(self, func, *args):
		raise

	def AddMail(self, msg):
		raise

	def SetDelVersion(self, version):
		raise
	
	def OnRequestDelRole(self, pid, grade, gradelst, fastgrade , C2SDelPid):
		if not gradelst:
			return 
		if max(gradelst) == grade:
			msg = "无法删除最高等级的角色"
			self.ShowPrompt(msg)
			return
	
		def FastDel(dlg, text):
			if text.isdigit() and int(text) == dlg.m_ID:
				C2SDelPid(dlg.m_ID)
			else:
				self.ShowPrompt("请输入正确的角色ID")

		def SlowDel(dlg):
			C2SDelPid(dlg.m_ID)

		if grade < fastgrade:
			dlg = self.ShowInputBox("#Y 请输入要删除的橘色ID，删除后无法恢复，请谨慎操作。#n",FastDel)
			dlg.m_ID = pid
		else:
			dlg.self.ShowMessageBox("#成功删除角色7天后，该角色自动删除，你确定要删除？"，（"确定", "取消"），（SlowDel, None）)
			dlg.m_ID = pid
		
	def OnCancelDelRole(self, pid, tm, C2SCancelDel):
		def CancelDel(dlg):
			C2SCancelDel(dlg.m_ID)

		txt = "您已经申请了删除该角色"
		dlg = self.ShowMessage(xxxxxx)
		dlg.m_ID = pid

	def OnS2CWaitInfo(self, dct):
		txt_lst = []
		for info in self.GetRolesInfos():
			pid = info["ID"]
			if pid not in dct:
				continue
			left_time = dct[pid]
			if left_time:
				txt_lst.append(left);
			if txt_lst:
				self.PushCall(self.AddGMMail, "#r".join(txt_lst))
