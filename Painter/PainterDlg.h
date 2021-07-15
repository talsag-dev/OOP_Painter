#pragma once

#include <vector>
#include "Figure.h"
#include "Rectangle_.h"
#include "Rombos.h"
#include "Ellipse_.h"
#include "Triangle_.h"
using namespace std;

//---------------------------------------------------------------------//
// Class PainterDlg
class PainterDlg:public CDialogEx
{
private:

	enum FIGURES{RECTANGLE,ELLIPSE,ROMBOS,TRIANGLE};
	FIGURES nextfig; // The next figure we are going to draw
	bool is_press;	// Check if the mouse is pressed
	int mov_fig; // Check if we are trying to drag a figure
	bool reSizing; // Check if we are resizing a shape
	CPoint nearP; // If we are 'reSizing' updates the new points of the figure
	CPoint startP; // Start point
	CPoint endP; // End point
	Figure *f; //Pointer for new figure
	CTypedPtrArray <CObArray, Figure*>figs_arr; // Array of figures
	CTypedPtrArray <CObArray, Figure*> temp_f; // Array of deleted figures
	int red;
	int green;
	int blue;

//---------------------------------------------------------------------//
public:

	
	PainterDlg(CWnd* pParent = NULL);	// standard constructor
	enum { IDD = IDD_Painter_DIALOG }; // Dialog Data

protected:
	
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation

	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();

	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedCheck1();
	BOOL isThin;
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedRadio4();
};