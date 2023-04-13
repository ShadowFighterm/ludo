#pragma once
#include<SFML/Graphics.hpp>
#include<vector>
#include"Board.h"
#include"Position.h"
using namespace std;
class Dice
{
private:
	sf::Sprite d;
	sf::Sprite d1, d2, d3, d4, d5, d6;
public:
	Dice(int turn);
	int Roll()const;
	void DrawMainDice(sf::RenderWindow& window)const;
	bool IsDiceThrown(Position p)const;
	void DisplayNumbers(sf::RenderWindow& window, vector<int> n);
	void DisplayRoll(sf::RenderWindow& window,const Board&b, int n);
	sf::Sprite GetDiceAt(int i)const;
};

