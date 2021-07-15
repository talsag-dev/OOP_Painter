#pragma once
#include "Rectangle_.h"
class Rombos :public Rectangle_ // Rombos is a successor of RectangleM
{
	DECLARE_SERIAL(Rombos)

public:
	//---------------------------------------------------------------------//
	// Constructors:
	Rombos();// Default constructor
	~Rombos();
	Rombos(int x1, int y1, int x2, int y2, int red, int green, int blue) :Rectangle_(x1, y1, x2, y2, red, green, blue) {}
	//---------------------------------------------------------------------//
	void Draw(CDC* dc);
};
