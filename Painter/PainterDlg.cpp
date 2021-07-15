
// PainterDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Painter.h"
#include "PainterDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About
// Class CAboutDlg
class CAboutDlg : public CDialogEx
{

public:

	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

protected:

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:

	DECLARE_MESSAGE_MAP()
};
//---------------------------------------------------------------------//
CAboutDlg::CAboutDlg():CDialogEx(CAboutDlg::IDD){}
//---------------------------------------------------------------------//
void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}
//---------------------------------------------------------------------//
BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
//---------------------------------------------------------------------//
END_MESSAGE_MAP()
//---------------------------------------------------------------------//
PainterDlg::PainterDlg
(CWnd* pParent /*=NULL*/):CDialogEx(PainterDlg::IDD, pParent),isThin(FALSE)
{
    f=NULL; // Pointer to next shape is null
	nextfig=RECTANGLE; // Future shape 
	mov_fig = -1;// if need to move -> -1 at default
	is_press=false; // if is pressed -> false at default
	reSizing=false;// if to resize -> false at default

	//_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}
//---------------------------nothing to change----------------------------//
void PainterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_CHECK1, isThin);
}
//---------------------------nothing to change------------------------//
BEGIN_MESSAGE_MAP(PainterDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_RADIO1, &PainterDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &PainterDlg::OnBnClickedRadio2)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_BN_CLICKED(IDC_BUTTON1, &PainterDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &PainterDlg::OnBnClickedButton2)
	ON_WM_RBUTTONDOWN()
	ON_BN_CLICKED(IDC_BUTTON3, &PainterDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_CHECK1, &PainterDlg::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_BUTTON4, &PainterDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &PainterDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &PainterDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_RADIO3, &PainterDlg::OnBnClickedRadio3)
	
	ON_BN_CLICKED(IDC_BUTTON7, &PainterDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_RADIO4, &PainterDlg::OnBnClickedRadio4)
END_MESSAGE_MAP()
// PainterDlg message handlers
//-----------------------nothing to change--------------------------//
BOOL PainterDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.
	// IDM_ABOUTBOX must be in the system command range.
	
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	CheckRadioButton(IDC_RADIO1,IDC_RADIO2,IDC_RADIO1); 

	

	return TRUE;  // return TRUE  unless you set the focus to a control
}
//----------------------nothing to change----------------------//
void PainterDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
		CDialogEx::OnSysCommand(nID, lParam);
}
//---------------------------------------------------------------------//
// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.
//---------------------------------------------------------------------//
void PainterDlg::OnPaint() //when we are actually on the painter part 
{
		CPaintDC dc2(this);  //another cdc variation help to draw
		CRect rect; //rectrangle for headline
		GetClientRect(&rect);
		CString opening ("Tal Sagie MFC_Painter");
		CFont font,*oldFont;
		font.CreatePointFont(120,_T("Arial Unicode MS")); // set font
		oldFont = dc2.SelectObject(&font);
		rect.OffsetRect(-150,210); //set on the screen 
		dc2.SetTextColor(RGB(200,70,100)); //set color 
		dc2.SetBkMode (TRANSPARENT);
		dc2.DrawText (opening, &rect, DT_SINGLELINE |
			DT_CENTER | DT_VCENTER);
		dc2.SelectObject(oldFont);
	
		for(int i=0;i<figs_arr.GetSize();i++)
			{     // prints the figures from figs array every time the arr-vector  is updates
			figs_arr[i]->Draw(&dc2); 
		    }

		
}
//---------------------------------------------------------------------//

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.

HCURSOR PainterDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
// chose rectangle
void PainterDlg::OnBnClickedRadio1()
{
	nextfig = RECTANGLE;
}
// chose ellipse 
void PainterDlg::OnBnClickedRadio2()
{
	nextfig = ELLIPSE;
}
// chose rombos
void PainterDlg::OnBnClickedRadio3()
{
	nextfig = ROMBOS;
}
// chose triangle
void PainterDlg::OnBnClickedRadio4()
{
	nextfig=TRIANGLE;
}

//while clicking on left button on the mouse 
void PainterDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
    endP=startP=point;
	is_press=true;
	
	int i;
	for(i = 0 ; i < figs_arr.GetSize() ; i++) 
	{// Check if user pressed inside a figure
		if((figs_arr[i]->startx < point.x && figs_arr[i]->endx > point.x) ||(figs_arr[i]->endx < point.x && figs_arr[i]->startx > point.x) )
			if((figs_arr[i]->starty < point.y && figs_arr[i]->endy > point.y)||(figs_arr[i]->endy < point.y && figs_arr[i]->starty > point.y) )
			{
				mov_fig = i; // the fig we are going to change

				// if we need to resize
				int a = (max(figs_arr[mov_fig]->startx,figs_arr[mov_fig]->endx)-min(figs_arr[mov_fig]->startx,figs_arr[mov_fig]->endx))/10;
				int b = (max(figs_arr[mov_fig]->starty,figs_arr[mov_fig]->endy)-min(figs_arr[mov_fig]->starty,figs_arr[mov_fig]->endy))/10;
				
				int maxX = max(figs_arr[mov_fig]->startx,figs_arr[mov_fig]->endx);
				int minX = min(figs_arr[mov_fig]->startx,figs_arr[mov_fig]->endx);
				int maxY = max(figs_arr[mov_fig]->starty,figs_arr[mov_fig]->endy);
				int minY = min(figs_arr[mov_fig]->starty,figs_arr[mov_fig]->endy);

				if( (point.x > (maxX-a) && point.x < maxX) || (point.x > minX && point.x < (minX + a)) )
					if( (point.y > (maxY-b) && point.y < maxY) || (point.y > minY && point.y < (minY + a)) )
					{
						reSizing = true; // we are risizng
						nearP.x = ((point.x-figs_arr[mov_fig]->startx)*(point.x-figs_arr[mov_fig]->startx)<(point.x-figs_arr[mov_fig]->endx)*(point.x-figs_arr[mov_fig]->endx))? figs_arr[mov_fig]->startx:figs_arr[mov_fig]->endx;
						nearP.y = ((point.y-figs_arr[mov_fig]->starty)*(point.y-figs_arr[mov_fig]->starty)<(point.y-figs_arr[mov_fig]->endy)*(point.y-figs_arr[mov_fig]->endy))? figs_arr[mov_fig]->starty:figs_arr[mov_fig]->endy;

						// update the points to the corners we have
					
							CPoint memulNearP;

							if(nearP.x == figs_arr[mov_fig]->startx && nearP.y == figs_arr[mov_fig]->starty 
								|| nearP.x == figs_arr[mov_fig]->endx && nearP.y == figs_arr[mov_fig]->endy)
								//  if new point is one of the corners we have 
							{
								if(figs_arr[mov_fig]->startx == nearP.x)
								{
									memulNearP.y = figs_arr[mov_fig]->endy;
									memulNearP.x = figs_arr[mov_fig]->endx;
								}
								else
								{
								memulNearP.y = figs_arr[mov_fig]->starty;
								memulNearP.x = figs_arr[mov_fig]->startx;
								}
							}
							else //  point is not in shape
							{
								if(figs_arr[mov_fig]->startx == nearP.x)
								{
									memulNearP.y = figs_arr[mov_fig]->starty;
									memulNearP.x = figs_arr[mov_fig]->endx;
								}
								else
								{
								memulNearP.y = figs_arr[mov_fig]->endy;
								memulNearP.x = figs_arr[mov_fig]->startx;
								}
							}

						figs_arr[mov_fig]->startx = memulNearP.x; 
						figs_arr[mov_fig]->starty = memulNearP.y; 

						figs_arr[mov_fig]->endx = nearP.x;
						figs_arr[mov_fig]->endy = nearP.y;
					}
			}
	}
}
//---------------------------------------------------------------------//
void PainterDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	

	if(is_press) //if i clicked LEFT MOUSE button 
	{
		if(mov_fig != -1) //  
		{
			if(reSizing == true) // changing place of figure on the move when my lbutton clicked
			{
				figs_arr[mov_fig]->endx += (point.x - endP.x);
				figs_arr[mov_fig]->endy += (point.y - endP.y);
				endP=point;
				Invalidate();
			}

			else //  change the figure place
			{
				RECT r;
				CPoint p1(figs_arr[mov_fig]->startx,figs_arr[mov_fig]->starty);
				CPoint p2(figs_arr[mov_fig]->endx,figs_arr[mov_fig]->endy);
				r.left=min(p1.x,p2.x);
				r.right=max(p1.x,p2.x)+1;
				r.top=min(p1.y,p2.y);
				r.bottom=max(p1.y,p2.y)+1;
				figs_arr[mov_fig]->startx += (point.x - endP.x); 
				figs_arr[mov_fig]->endx += (point.x - endP.x); 
				figs_arr[mov_fig]->starty += (point.y - endP.y);
				figs_arr[mov_fig]->endy += (point.y - endP.y);
				InvalidateRect(&r); 
		        endP=point;
			}	
		}
		else //draw a new fig 
		{
			CClientDC dc(this);
			CBrush myBrush(RGB(red,green,blue)),*oldBrush;
			oldBrush = dc.SelectObject(&myBrush);
			CPen myPen(PS_SOLID, isThin?1:9, RGB(110,0,0)),*oldPen;
			oldPen = dc.SelectObject(&myPen);
			dc.SetROP2(R2_NOTXORPEN); 
			switch(nextfig)
			{
				case RECTANGLE:
					{
					dc.Rectangle(startP.x, startP.y,endP.x, endP.y);
					endP=point;
					dc.Rectangle(startP.x, startP.y,endP.x, endP.y);
				break;
					}
				case ROMBOS:
					{
					dc.Rectangle(startP.x, startP.y,endP.x, endP.y);
					endP=point;
					dc.Rectangle(startP.x, startP.y,endP.x, endP.y);
					break;
					}
				case ELLIPSE:
					{
					dc.Ellipse(startP.x, startP.y,endP.x, endP.y);
					endP=point;
					dc.Ellipse(startP.x, startP.y,endP.x, endP.y);
				break;
					}
				case TRIANGLE:
					{
					dc.Rectangle(startP.x, startP.y,endP.x, endP.y);
					endP=point;
					dc.Rectangle(startP.x, startP.y,endP.x, endP.y);
					break;
					}
			}

			dc.SelectObject( oldPen ); 
			dc.SetROP2(R2_COPYPEN); 
		}
	}

}
//---------------------------------------------------------------------//
void PainterDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	
	if(is_press)
	{
		is_press=false;
		endP=point;
		if(mov_fig == -1)
		{

			switch(nextfig)
			{
				case RECTANGLE:
					{
					figs_arr.Add(new Rectangle_(startP.x,startP.y,endP.x,endP.y,red,green,blue));
					break;
					}
				case ROMBOS:
					{
					figs_arr.Add(new Rombos(startP.x,startP.y,endP.x,endP.y,red,green,blue));
						break;
					}
				case ELLIPSE:
					{
					figs_arr.Add(new Ellipse_(startP.x,startP.y,endP.x,endP.y,red,green,blue));
					break;
					}
					case TRIANGLE:
					{
					figs_arr.Add(new Triangle_(startP.x,startP.y,endP.x,endP.y,red,green,blue));
						break;
					}
			}
		}
		else
			mov_fig = -1;// back to ->
		reSizing = false;//  defaults
		Invalidate();
	}
}


//---------------------------------------------------------------------//
// Save button
void PainterDlg::OnBnClickedButton1()
{
	
	CFile file;
	CFileDialog FileDlg(TRUE);
	FileDlg.m_ofn.lpstrFilter=_T("DATA Files (*.dat)\0*.dat\0");
	FileDlg.m_ofn.lpstrTitle=_T("Save DATA File As");
	CString filename;
	if (FileDlg.DoModal()==IDOK)
	{
		filename=FileDlg.GetPathName();
		filename.Append(_T(".dat"));
	}
	if(file.Open(filename,CFile::modeCreate|CFile::modeWrite))
	{
		CArchive ar(&file, CArchive::store);
		figs_arr.Serialize(ar);
		ar.Close();
	}
	else
		return;
	file.Close();
}
// Load button
void PainterDlg::OnBnClickedButton2()
{
	
	CFile file;
	CFileDialog FileDlg(TRUE);
	FileDlg.m_ofn.lpstrFilter=_T("DATA Files (*.dat)\0*.dat\0");
	FileDlg.m_ofn.lpstrTitle=_T("Load DATA File");
	CString filename;
	if(FileDlg.DoModal()==IDOK)
	{
		filename=FileDlg.GetPathName();
	}
	if(file.Open(filename,CFile::modeRead))
	{
		CArchive ar(&file,CArchive::load);
		figs_arr.Serialize(ar);
		ar.Close();
	}
	else
		return;
	file.Close();
	Invalidate();
}
// Colors button
void PainterDlg::OnBnClickedButton3() 
{
	CColorDialog color;
	color.DoModal();
	COLORREF clr = color.GetColor();
	red=GetRValue(clr);
	blue=GetBValue(clr);
	green=GetGValue(clr);
	
}
// Thin button
void PainterDlg::OnBnClickedCheck1()
{
	UpdateData(true);
}
//remove all 
void PainterDlg::OnBnClickedButton4()
{
	if(figs_arr.IsEmpty())
		return;
	for(int i = 0 ; i < figs_arr.GetSize() ; i++) 
	{
       		temp_f.Add(figs_arr[i]);
	}
	figs_arr.RemoveAll();   
	 Invalidate();
}
//undo
void PainterDlg::OnBnClickedButton5() 
{
	if(figs_arr.IsEmpty())
		return;
	temp_f.Add(figs_arr[figs_arr.GetSize()-1]);
	figs_arr.RemoveAt(figs_arr.GetSize()-1);
	Invalidate();
}
//redo
void PainterDlg::OnBnClickedButton6() 
{
	if(temp_f.IsEmpty())
		return;
	figs_arr.Add(temp_f[temp_f.GetSize()-1]);
	temp_f.RemoveAt(temp_f.GetSize()-1);
	Invalidate();
}

void PainterDlg::OnBnClickedButton7()
{
	Invalidate(true);
}



