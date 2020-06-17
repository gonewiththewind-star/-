// sy1Dlg.h : header file
//

#if !defined(AFX_SY1DLG_H__D235A808_C300_4534_B48C_DC3E2BAE6CBE__INCLUDED_)
#define AFX_SY1DLG_H__D235A808_C300_4534_B48C_DC3E2BAE6CBE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSy1Dlg dialog

class CSy1Dlg : public CDialog
{
// Construction
public:
	char fname[30];
	CSy1Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSy1Dlg)
	enum { IDD = IDD_SY1_DIALOG };
	CString	m_Url1;
	CString	m_Ip1;
	CString	m_Ip2;
	CString	m_Url2;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSy1Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSy1Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnOk1();
	afx_msg void OnOk2();
	virtual void OnCancel();
	afx_msg void OnCaptureChanged(CWnd *pWnd);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SY1DLG_H__D235A808_C300_4534_B48C_DC3E2BAE6CBE__INCLUDED_)
