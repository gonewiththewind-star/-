// sy1Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "sy1.h"
#include "sy1Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSy1Dlg dialog

CSy1Dlg::CSy1Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSy1Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSy1Dlg)
	m_Url1 = _T("");
	m_Ip1 = _T("");
	m_Ip2 = _T("");
	m_Url2 = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSy1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSy1Dlg)
	DDX_Text(pDX, IDC_EDIT1, m_Url1);
	DDX_Text(pDX, IDC_EDIT2, m_Ip1);
	DDX_Text(pDX, IDC_EDIT3, m_Ip2);
	DDX_Text(pDX, IDC_EDIT4, m_Url2);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSy1Dlg, CDialog)
	//{{AFX_MSG_MAP(CSy1Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK1, OnOk1)
	ON_BN_CLICKED(IDOK2, OnOk2)
	ON_WM_CAPTURECHANGED()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSy1Dlg message handlers

BOOL CSy1Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSy1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CSy1Dlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CSy1Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CSy1Dlg::OnOk1() 
{
	
	// TODO: Add your control notification handler code here
	WSADATA wsaData;
	LPHOSTENT lpHostEnt;//�ýṹ����������ip��
	
	if(WSAStartup(0X0101,&wsaData))//����ʼ���ɹ��򷵻�0���൱��Ӧ�ó�����dll
		//֮������ӳ�ʼ����Ȼ�����ʹ��winsock api�ĺ���
		MessageBox("Could not load windows sockets dll.",NULL,MB_OK|MB_ICONSTOP);
	else
	{
		UpdateData(TRUE);//���ڽ���Ļ�Ͽؼ��е����ݽ����������С�
		lpHostEnt = gethostbyname(m_Url1);
		//TODO: �˴���Ҫ�Լ���Ӻ������ɶԻ����������������m_Url1�õ���Ӧ�İ�������ip�Ľṹ����lpHostEnt

		//���磺�������www.seu.edu.cn���õ�������ӦIPΪ11000000001000000100000000000010�Ľṹ����
		
		if(!lpHostEnt)
			MessageBox("Could not get ip address.",NULL,MB_OK|MB_ICONSTOP);
		else
		{
			
			//TODO: �˴���Ҫ�Լ���Ӻ�������lpHostEnt�ṹ�г�Ա����h_addr_list����������λ˳���IPv4��ַת��Ϊ�����ĵ�����ʽIP�Թ���ʾ
		
			//���磺�������11000000001000000100000000000010���õ�192.32.64.2
			m_Ip1 = inet_ntoa(*(LPIN_ADDR)*lpHostEnt->h_addr_list);
			UpdateData(FALSE);//���ڽ���������Ļ�ж�Ӧ�ؼ�����ʾ������
		}
	}

	WSACleanup();

}

void CSy1Dlg::OnOk2() 
{
	// TODO: Add your control notification handler code here
	WSADATA wsaData;
	LPHOSTENT lpHostEnt;
    DWORD dwIPAddr;

	if(WSAStartup(0x0101,&wsaData))
		MessageBox("Could not load windows sockets dll.",NULL,MB_OK|MB_ICONSTOP);
	else
	{
		UpdateData(TRUE);//���ڽ���Ļ�Ͽؼ��е����ݽ����������С�

		//TODO: �˴���Ҫ�Լ���Ӻ������ɶԻ���������ĵ�����ʽ��IP��ַm_Ip2ת��Ϊһ���������ֽ�˳���ʾ��32λ������IP��ַdwIPAddr
	
		//���磬ԭ��Ϊ192.32.64.2��ת����Ϊ11000000001000000100000000000010
		dwIPAddr = inet_addr(m_Ip2);
		if(dwIPAddr==INADDR_NONE)
			MessageBox("Invalid Internet Address.",NULL,MB_OK|MB_ICONSTOP);
		else 
		{

			//TODO: �˴���Ҫ�Լ���Ӻ�������IP��ַdwIPAddrת��Ϊ��Ӧ�İ����������ƵĽṹ����lpHostEnt

			//���磺�������11000000001000000100000000000010���õ�www.seu.edu.cn
			lpHostEnt =gethostbyaddr((char FAR*)& dwIPAddr,4, PF_INET);


			
			if(!lpHostEnt)
				MessageBox("Could not get host name.",NULL,MB_OK|MB_ICONSTOP);
			else
			{
				
				//TODO: ��Ӻ������ӽṹ����lpHostEnt��ȡ�ö�ӦIP���Ƶĳ�Ա����h_name��������m_Url2�����Թ���ʾ
	m_Url2 = lpHostEnt->h_name;
				UpdateData(FALSE);//���ڽ���������Ļ�ж�Ӧ�ؼ�����ʾ������
			}
		}
	}

	WSACleanup();

}







void CSy1Dlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}

void CAboutDlg::OnOK() 
{
	// TODO: Add extra validation here
	
	CDialog::OnOK();
}

void CSy1Dlg::OnCaptureChanged(CWnd *pWnd) 
{
	// TODO: Add your message handler code here
	
	CDialog::OnCaptureChanged(pWnd);
}
