#include "Rectangle.h"
Rectangle::Rectangle(sf::Color fillClr, sf::Color outClr, Position p, char id)
	:Shape(fillClr, outClr, id)
{
	float average = (float)(Global::SqrDim.x + Global::SqrDim.y) / 2.0f;
	rec.setSize(Global::SqrDim);
	rec.setOutlineThickness(-(float)average / 30);
	rec.setPosition(p.ci * Global::SqrDim.x, p.ri * Global::SqrDim.y);
	rec.setFillColor(GetFillClr());
	rec.setOutlineColor(GetOutClr());
}
void Rectangle::DrawShape(sf::RenderWindow& window)
{
	rec.setFillColor(fillClr);
	rec.setOutlineColor(outClr);
	window.draw(rec);
}