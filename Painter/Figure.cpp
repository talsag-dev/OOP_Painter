#include "stdafx.h"
#include "Figure.h"
// Must write all these commands in al CPP files
IMPLEMENT_SERIAL (Figure, CObject, 1)
//---------------------------------------------------------------------//
// Defualt constructor
Figure::Figure(void) {}
// Defualt destructor
Figure::~Figure(void) {}
// Constructor
Figure::Figure(int x1, int y1, int x2, int y2, int r, int g, int b)
{
	startx = x1;
	endx = x2;
	starty = y1;
	endy = y2;
	red = r;
	green = g;
	blue = b;

}
void Figure::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << startx;
		ar << endx;
		ar << starty;
		ar << endy;
		ar << red;
		ar << green;
		ar << blue;
	}
	else //Loading
	{
		ar >> startx;
		ar >> endx;
		ar >> starty;
		ar >> endy;
		ar >> red;
		ar >> green;
		ar >> blue;
	}
}
//---------------------------------------------------------------------//