#pragma once
#include<string>
#include"Dice.h"
#include"Global.h"
#include<SFML/Graphics.hpp>
using namespace std;
class Dice;
class Player
{
private:
	sf::Text name;
	sf::Color clr;
	int turnNo;
	Dice*d;
public:
	Player(sf::Text&name,int turn, sf::Color&clr);
	int RollDice()const;
	void DisplayName(sf::RenderWindow& window)const;
	void SetName(sf::Text& name);
	void SetClr(sf::Color& clr);
	void SetTurnNo(int turn);
	const sf::Text& GetName()const;
	const sf::Color& GetClr()const;
	Dice GetDice()const;
};

