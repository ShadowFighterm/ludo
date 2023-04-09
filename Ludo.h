#pragma once
#include<SFML/Graphics.hpp>
#include"Position.h"
class Board;
class Player;
class Ludo
{
private:
	bool IsSocSel;
	bool IsDesSel;
	Position s;
	Position d;
	int nop;
	Board* b;
	Player* ps;
	int turn;
	bool InBound()const;
	bool IsValidSource()const;
	bool IsValidDestin()const;
	void MainMenu(sf::RenderWindow& window);
	void SelectPosition(sf::RenderWindow& window);
	void TurnCh();
public:
	Ludo(sf::RenderWindow& window);
	void Play(sf::RenderWindow& window);
};

