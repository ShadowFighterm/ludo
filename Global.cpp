#include "Global.h"
sf::Vector2f Global::SqrDim = sf::Vector2f(0, 0);
sf::Texture* Global::ts = nullptr;
sf::Texture* Global::dts = nullptr;
char* Global::turnId = nullptr;
sf::Font Global::f;
sf::Font Global::f1;
sf::Font Global::f2;
sf::Font Global::f3;
void Global::getRowColbyLeftClick(int& rpos, int& cpos, sf::RenderWindow& window)
{
	sf::Vector2f p = sf::Vector2f(sf::Mouse::getPosition(window));
	cpos = p.x;
	rpos = p.y;
}