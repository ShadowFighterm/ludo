#pragma once
#include<SFML/Graphics.hpp>
class Board;
class Player;
class Ludo
{
private:
	int nop;
	Board* b;
	Player* ps;
	int turn;
	void MainMenu(sf::RenderWindow& window);
public:
	Ludo(sf::RenderWindow& window);
	void Play(sf::RenderWindow& window);
};

