#pragma once
#include<SFML/Graphics.hpp>
class Global
{
public:
	static enum dir { UP, DOWN, RIGHT, LEFT };
	static char* turnId;
	static sf::Vector2f SqrDim;
	static sf::Texture* ts;
	static sf::Texture* dts;
	static sf::Font f;
	static sf::Font f1;
	static sf::Font f2;
	static sf::Font f3;
	void static getRowColbyLeftClick(int& rpos, int& cpos, sf::RenderWindow&window);
};

