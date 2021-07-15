#pragma once
#include "Figure.h"
// Class Ellipse
class Ellipse_ :public Figure // Ellipse is a successor of Figure
{
	DECLARE_SERIAL(Ellipse_)

public:
	//---------------------------------------------------------------------//
	// Constructors:
	Ellipse_(); // Default constructor
	~Ellipse_(void);
	Ellipse_(int x1, int y1, int x2, int y2, int red, int green, int blue) :Figure(x1, y1, x2, y2, red, green, blue) {}
	void Draw(CDC* dc);
	//---------------------------------------------------------------------//



};
