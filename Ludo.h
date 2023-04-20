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
	sf::Sprite pause;
	bool IsSocSel;
	bool IsDesSel;
	bool IsNumSel;
	int nop;
	vector<int>score; 
	sf::Vector3f rs;
	Position s;
	Position d;
	Board* b;
	Player** ps;
	int turn;
	void SocHighlight();
	void SocUnhighlight();
	void ShowSocMsg(sf::RenderWindow& window)const;
	void ShowNumMsg(sf::RenderWindow& window)const;
	void init(sf::RenderWindow& window);
	void WinningScreen(sf::RenderWindow& window)const;
	bool IsWin()const;
	bool InBound()const;
	bool IsValidNum()const;
	bool IsValidSource()const;
	bool IsValidDestin()const;
	void MainMenu(sf::RenderWindow& window);
	void Pause(sf::RenderWindow& window);
	void SelectPosition(sf::RenderWindow& window);
	bool CanMove()const;
	void FindSocAuto();
	bool CanMoveAuto()const;
	void MoveAuto(sf::RenderWindow&window);
	void TurnCh();
public:
	Ludo(sf::RenderWindow& window);
	void Play(sf::RenderWindow& window);
};

