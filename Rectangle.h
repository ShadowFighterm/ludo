#pragma once
#include"Shape.h"
#include"Position.h"
#include<SFML/Graphics.hpp>
class Rectangle:public Shape
{
private:
	sf::RectangleShape rec;
public:
	Rectangle(sf::Color fillClr, sf::Color outClr, Position p, char id);
	void DrawShape(sf::RenderWindow& window)const override;
};

