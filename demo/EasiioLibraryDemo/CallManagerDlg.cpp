// CallManagerDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "EasiioLibraryDemo.h"
#include "CallManagerDlg.h"
#include "afxdialogex.h"


// CallManagerDlg 对话框

IMPLEMENT_DYNAMIC(CallManagerDlg, CDialogEx)

CallManagerDlg::CallManagerDlg(CWnd* pParent /*=NULL*/, CString call_number)
	: CDialogEx(CallManagerDlg::IDD, pParent), mcall_number(call_number) {
}

CallManagerDlg::~CallManagerDlg()
{
}

void CallManagerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CallManagerDlg, CDialogEx)
	ON_BN_CLICKED(IDC_VOICE_BUTTON, &CallManagerDlg::OnBnClickedVoiceCallButton)
	ON_BN_CLICKED(IDC_VIDEO_BUTTON, &CallManagerDlg::OnBnClickedVideoCallButton)
END_MESSAGE_MAP()


// CallManagerDlg 消息处理程序


void CallManagerDlg::OnBnClickedVoiceCallButton() {
	// TODO: 在此添加控件通知处理程序代码
	std::string numberstr = mcall_number.GetBuffer();
	const char* number = numberstr.c_str();
	int result = EasiioMakeCall(number, VOICE_CALL, "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789");
	if (result < 0) {
		printf("Make call failed!");
		return;
	}
	this->EndDialog(NULL);
}


void CallManagerDlg::OnBnClickedVideoCallButton() {
	// TODO: 在此添加控件通知处理程序代码
	std::string numberstr = mcall_number.GetBuffer();
	const char* number = numberstr.c_str();
	int result = EasiioMakeCall(number, VIDEO_CALL, "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789");
	if (result < 0) {
		printf("Make call failed!");
		return;
	}
	this->EndDialog(NULL);
}
