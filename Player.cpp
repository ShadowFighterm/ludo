#include "Player.h"
#include<iostream>
#include<string>
using namespace std;
Player::Player(string name, int turn, int clr)
{
	this->d = new Dice(turn);
	SetName(name);
	SetTurnNo(turn);
	SetClr(clr);
}
int Player::RollDice()const
{
	return this->d->Roll();
}
void Player::SetName(string name)
{
	this->name = name;
}
void Player::SetClr(int clr)
{
	this->clr = clr;
}
void Player::SetTurnNo(int turn)
{
	this->tunrNo = turn;
}
string Player::GetName()const
{
	return this->name;
}
int Player::GetClr()const
{
	return this->clr;
}
int Player::GetTurnNo()const
{
	return this->tunrNo;
}
Dice Player::GetDice()const
{
	return *d;
}
