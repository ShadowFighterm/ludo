#include "Global.h"
sf::Vector2f Global::SqrDim = sf::Vector2f(0, 0);
sf::Texture* Global::ts = nullptr;
sf::Font Global::f;

void Global::getRowColbyLeftClick(int& rpos, int& cpos, sf::RenderWindow& window)
{
	sf::Vector2f p = sf::Vector2f(sf::Mouse::getPosition(window));
	cpos = p.x;
	rpos = p.y;
}