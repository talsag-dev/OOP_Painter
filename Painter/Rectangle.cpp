#include "stdafx.h"
#include "Rectangle_.h"
// Must write all these commands in al CPP files
IMPLEMENT_SERIAL (Rectangle_, Figure, 1)
//---------------------------------------------------------------------//
// Defualt constructor
Rectangle_::Rectangle_(void) {}
// Defualt destructor
Rectangle_::~Rectangle_(void){}
void Rectangle_::Draw(CDC * dc)
{
	CBrush myBrush(RGB(red, green, blue)), *oldBrush;
	oldBrush = dc->SelectObject(&myBrush);
	dc->Rectangle(startx, starty, endx, endy);
	dc->SelectObject(oldBrush);
}
//---------------------------------------------------------------------//