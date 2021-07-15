#include "stdafx.h"
#include "Triangle_.h"
IMPLEMENT_SERIAL(Triangle_, Figure, 1)
//---------------------------------------------------------------------//
// Defualt constructor
Triangle_::Triangle_(void) {}
// Defualt destructor
Triangle_::~Triangle_(void) {}

void Triangle_::Draw(CDC * dc)
{
	CBrush myBrush(RGB(red, green, blue)), *oldBrush;
	oldBrush = dc->SelectObject(&myBrush);
	POINT points[3];
	points[0].x = startx;
	points[0].y = starty - ((starty - endy) / 2);
	points[1].x = (startx + (endx - startx) / 2);
	points[1].y = starty;
	points[2].x = endx;
	points[2].y = starty - ((starty - endy) / 2);
	dc->Polygon(points, 3);
}
