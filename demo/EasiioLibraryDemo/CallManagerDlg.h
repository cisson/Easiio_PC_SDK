#pragma once

#include "EasiioLibrary.h"
#include <string>
// CallManagerDlg �Ի���

class CallManagerDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CallManagerDlg)

public:
	CallManagerDlg(CWnd* pParent , CString call_number);   // ��׼���캯��
	virtual ~CallManagerDlg();

	// �Ի�������
	//#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALLMANAGER_DIALOG };
	//#endif
private:
	CString mcall_number;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedVoiceCallButton();
	afx_msg void OnBnClickedVideoCallButton();
};
