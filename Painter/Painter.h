
// File creates automatic with MFC project - We didn't touch it
// Painter.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CPainterApp:
// See Painter.cpp for the implementation of this class
//

class CPainterApp : public CWinApp
{
public:
	CPainterApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CPainterApp theApp;//CHECK AGAIN