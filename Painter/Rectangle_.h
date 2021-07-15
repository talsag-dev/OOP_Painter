#pragma once
#include "Figure.h"
// Class Rectangle
class Rectangle_:public Figure // RectangleM is a successor of Figure
{
 DECLARE_SERIAL(Rectangle_)

public:
//---------------------------------------------------------------------//
// Constructors:
	Rectangle_();// Default constructor
	Rectangle_(int x1, int y1, int x2, int y2, int red, int green, int blue) :Figure(x1, y1, x2, y2, red, green, blue) {}
	~Rectangle_();
	void Draw(CDC *dc);
//---------------------------------------------------------------------//
};