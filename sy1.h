// sy1.h : main header file for the SY1 application
//

#if !defined(AFX_SY1_H__E9F9213A_C8E9_4145_90C3_44FAF66C8A0E__INCLUDED_)
#define AFX_SY1_H__E9F9213A_C8E9_4145_90C3_44FAF66C8A0E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSy1App:
// See sy1.cpp for the implementation of this class
//

class CSy1App : public CWinApp
{
public:
	CSy1App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSy1App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSy1App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SY1_H__E9F9213A_C8E9_4145_90C3_44FAF66C8A0E__INCLUDED_)
