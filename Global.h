#pragma once
#include<SFML/Graphics.hpp>
class Global
{
public:
	static enum dir { UP, DOWN, RIGHT, LEFT };
	static char* turnId;
	static sf::Vector2f SqrDim;
	static sf::Texture* ts;
	static sf::Font f;

	void static getRowColbyLeftClick(int& rpos, int& cpos, sf::RenderWindow&window);
};

