#include "Dice.h"
#include<iostream>
using namespace std;
int Dice::Roll()const
{
	srand(time(0));
	int r = rand() % 6 + 1;
	return r;
}
void Dice::DisplayRoll()const
{

}
