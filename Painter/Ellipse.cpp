#include "stdafx.h"
#include "Ellipse_.h"
IMPLEMENT_SERIAL (Ellipse_, Figure, 1)
//---------------------------------------------------------------------//
// Defualt constructor
Ellipse_::Ellipse_(void) {}
// Defualt destructor
Ellipse_::~Ellipse_(void) {}
//---------------------------------------------------------------------//
void Ellipse_::Draw(CDC* dc) // Check in which color to print and print accordingly 
{
	CBrush myBrush(RGB(red, green, blue)), * oldBrush;
	oldBrush = dc->SelectObject(&myBrush);
	dc->Ellipse(startx, starty, endx, endy);
	dc->SelectObject(oldBrush);
}