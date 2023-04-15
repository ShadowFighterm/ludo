#pragma once
#include<SFML/Graphics.hpp>
#include<vector>
#include"Position.h"
using namespace std;
class Board;
class Player;
class Ludo
{
private:
	bool IsSocSel;
	bool IsDesSel;
	bool IsNumSel;
	vector<int>score;
	sf::Vector3f rs;
	Position s;
	Position d;
	int nop;
	Board* b;
	Player** ps;
	int turn;
	bool InBound()const;
	bool IsValidNum()const;
	bool IsValidSource()const;
	bool IsValidDestin()const;
	void MainMenu(sf::RenderWindow& window);
	void SelectPosition(sf::RenderWindow& window);
	bool CanMove()const;
	void FindSocAuto();
	void FindDestAuto(int n);
	bool CanMoveAuto()const;
	void MoveAuto(sf::RenderWindow&window);
	void TurnCh();
public:
	Ludo(sf::RenderWindow& window);
	void Play(sf::RenderWindow& window);
};

