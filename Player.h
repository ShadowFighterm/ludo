#pragma once
#include<string>
#include"Dice.h"
using namespace std;
class Player
{
private:
	string name;
	int tunrNo;
	int clr;
	Dice d;
public:
	Player(string name, int turn, int clr);
	int RollDice()const;
	void SetName(string name);
	void SetClr(int clr);
	void SetTurnNo(int turn);
	string GetName()const;
	int GetClr()const;
	int GetTurnNo()const;
};

