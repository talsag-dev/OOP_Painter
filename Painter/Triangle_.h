#pragma once
#include "Rectangle_.h"
class Triangle_ :public Rectangle_ // Triangle is a successor of RectangleM
{
	DECLARE_SERIAL(Triangle_)

public:
	//---------------------------------------------------------------------//
	// Constructors:
	Triangle_();// Default constructor
	~Triangle_();
	Triangle_(int x1, int y1, int x2, int y2, int red, int green, int blue) :Rectangle_(x1, y1, x2, y2, red, green, blue) {}
	//---------------------------------------------------------------------//
	void Draw(CDC *dc);
	
};