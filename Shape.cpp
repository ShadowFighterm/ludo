#include"Shape.h"
Shape::Shape(sf::Color fillClr, sf::Color outClr, char id)
{
	this->id = id;
	this->fillClr = fillClr;
	this->outClr = outClr;
}
char Shape::GetId()const
{
	return this->id;
}
sf::Color Shape::GetFillClr()const
{
	return this->fillClr;
}
sf::Color Shape::GetOutClr()const
{
	return this->outClr;
}
void Shape::SetOutClr(sf::Color c)
{
	this->outClr = c;
}
void Shape::SetFillClr(sf::Color c)
{
	this->fillClr = c;
}