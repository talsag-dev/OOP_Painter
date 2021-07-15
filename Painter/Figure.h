#pragma once
//---------------------------------------------------------------------//
// Class Figure
class Figure:public CObject // figure is a successor of object
{
	DECLARE_SERIAL(Figure)
public:
	Figure();
	int red;
	int green;
	int blue;
	int startx,starty,endx,endy;
	CPoint start, end;
	int size;
	COLORREF bgColor;
	virtual void Draw(CDC *dc){};
	virtual ~Figure(void);
	Figure(int x1, int y1, int x2, int y2, int r, int g, int b);
//---------------------------------------------------------------------//
	void Serialize(CArchive& ar);
};
