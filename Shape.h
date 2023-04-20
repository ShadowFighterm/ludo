#pragma once
#include<SFML/Graphics.hpp>
#include"Global.h"
class Shape
{
protected:
	sf::Color fillClr;
	sf::Color outClr;
	char id;
public:
	Shape(sf::Color fillClr, sf::Color outClr, char id);
	virtual void DrawShape(sf::RenderWindow& window) = 0;
	char GetId()const;
	sf::Color GetFillClr()const;
	sf::Color GetOutClr()const;
	void SetOutClr(sf::Color c);
	void SetFillClr(sf::Color c);
};

