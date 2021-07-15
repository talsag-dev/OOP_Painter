#include "stdafx.h"
#include "Rombos.h"
// Must write all these commands in al CPP files
IMPLEMENT_SERIAL(Rombos,CObject, 1)
//---------------------------------------------------------------------//
// Defualt constructor
Rombos::Rombos(void) {}
// Defualt destructor
Rombos::~Rombos(void){}
//---------------------------------------------------------------------//
void Rombos::Draw(CDC* dc) // Will edit it again with the new palleta
{
	CBrush myBrush(RGB(red, green, blue)), * oldBrush;
	oldBrush = dc->SelectObject(&myBrush);

	POINT points[4];
	points[0].x = (startx + (endx - startx) / 2);
	points[0].y = starty;
	points[1].x = endx;
	points[1].y = starty - ((starty - endy) / 2);
	points[2].x = (startx + (endx - startx) / 2);
	points[2].y = endy;
	points[3].x = startx;
	points[3].y = starty - ((starty - endy) / 2);
	dc->Polygon(points, 4);
}