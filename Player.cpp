#include "Player.h"
#include<iostream>
#include<string>
using namespace std;
Player::Player(sf::Text&name, int turn, sf::Color& clr)
{
	this->d = new Dice(turn);
	SetName(name);
	SetTurnNo(turn);
	SetClr(clr);
	SetHasRolled(false);
	this->name.setPosition((float)Global::SqrDim.x * 24 + (Global::SqrDim.x / 4), (float)Global::SqrDim.y * 1);
	this->name.setCharacterSize(40);
	this->name.setFillColor(this->clr);
}
int Player::RollDice()const
{
	return this->d->Roll();
}
void Player::DisplayName(sf::RenderWindow& window)const
{
	window.draw(name);
}
void Player::SetName(sf::Text& name)
{
	this->name.setString(name.getString());
	this->name.setFont(Global::f1);
}
void Player::SetClr(sf::Color& clr)
{
	this->clr = clr;
}
void Player::SetTurnNo(int turn)
{
	this->turnNo = turn;
}
void Player::SetHasRolled(bool b)
{
	this->HasRolled = b;
}
bool Player::GetHasRolled()const
{
	return this->HasRolled;
}
const sf::Text& Player::GetName()const
{
	return this->name;
}
const sf::Color& Player::GetClr()const
{
	return this->clr;
}
Dice Player::GetDice()const
{
	return *d;
}
