#pragma once

#include "EasiioLibrary.h"
#include <string>
// CallManagerDlg 对话框

class CallManagerDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CallManagerDlg)

public:
	CallManagerDlg(CWnd* pParent , CString call_number);   // 标准构造函数
	virtual ~CallManagerDlg();

	// 对话框数据
	//#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALLMANAGER_DIALOG };
	//#endif
private:
	CString mcall_number;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedVoiceCallButton();
	afx_msg void OnBnClickedVideoCallButton();
};
