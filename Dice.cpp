#include "Dice.h"
#include<iostream>
#include"Global.h"
using namespace std;
Dice::Dice(int turn)
{
	d1.setTexture(Global::dts[turn * 6]);
	d2.setTexture(Global::dts[turn * 6 + 1]);
	d3.setTexture(Global::dts[turn * 6 + 2]);
	d4.setTexture(Global::dts[turn * 6 + 3]);
	d5.setTexture(Global::dts[turn * 6 + 4]);
	d6.setTexture(Global::dts[turn * 6 + 5]);
	d.setTexture(*d1.getTexture());
	d.setPosition(25 * Global::SqrDim.x, 2 * Global::SqrDim.y);
	d.setScale((float)Global::SqrDim.x / d.getTexture()->getSize().x, (float)Global::SqrDim.y / d.getTexture()->getSize().y);
	d1.setScale((float)Global::SqrDim.x / d1.getTexture()->getSize().x, (float)Global::SqrDim.y / d1.getTexture()->getSize().y);
	d2.setScale((float)Global::SqrDim.x / d2.getTexture()->getSize().x, (float)Global::SqrDim.y / d2.getTexture()->getSize().y);
	d3.setScale((float)Global::SqrDim.x / d3.getTexture()->getSize().x, (float)Global::SqrDim.y / d3.getTexture()->getSize().y);
	d4.setScale((float)Global::SqrDim.x / d4.getTexture()->getSize().x, (float)Global::SqrDim.y / d4.getTexture()->getSize().y);
	d5.setScale((float)Global::SqrDim.x / d5.getTexture()->getSize().x, (float)Global::SqrDim.y / d5.getTexture()->getSize().y);
	d6.setScale((float)Global::SqrDim.x / d6.getTexture()->getSize().x, (float)Global::SqrDim.y / d6.getTexture()->getSize().y);
}
int Dice::Roll()const
{
	srand(time(0));
	int r = rand() % 6 + 1;
	return r;
}
bool Dice::IsDiceThrown(Position p)const
{
	return p.ri == 2 && p.ci == 25;
}
void Dice::DisplayNumbers(sf::RenderWindow& window, vector<int>n)
{
	for (int i = 0;i < n.size();i++)
	{
		switch (n[i])
		{
		case 1:
			d1.setPosition(Global::SqrDim.x * 24 + (i * Global::SqrDim.x), Global::SqrDim.y * 3);
			window.draw(d1);
			break;
		case 2:
			d2.setPosition(Global::SqrDim.x * 24 + (i * Global::SqrDim.x), Global::SqrDim.y * 3);
			window.draw(d2);
			break;
		case 3:
			d3.setPosition(Global::SqrDim.x * 24 + (i * Global::SqrDim.x), Global::SqrDim.y * 3);
			window.draw(d3);
			break;
		case 4:
			d4.setPosition(Global::SqrDim.x * 24 + (i * Global::SqrDim.x), Global::SqrDim.y * 3);
			window.draw(d4);
			break;
		case 5:
			d5.setPosition(Global::SqrDim.x * 24 + (i * Global::SqrDim.x), Global::SqrDim.y * 3);
			window.draw(d5);
			break;
		case 6:
			d6.setPosition(Global::SqrDim.x * 24 + (i * Global::SqrDim.x), Global::SqrDim.y * 3);
			window.draw(d6);
			break;
		}
	}
}
void Dice::DisplayRoll(sf::RenderWindow& window, const Board&b, int n)
{
	d1.setPosition(25 * Global::SqrDim.x, 2 * Global::SqrDim.y);
	d2.setPosition(25 * Global::SqrDim.x, 2 * Global::SqrDim.y);
	d3.setPosition(25 * Global::SqrDim.x, 2 * Global::SqrDim.y);
	d4.setPosition(25 * Global::SqrDim.x, 2 * Global::SqrDim.y);
	d5.setPosition(25 * Global::SqrDim.x, 2 * Global::SqrDim.y);
	d6.setPosition(25 * Global::SqrDim.x, 2 * Global::SqrDim.y);
	srand(time(0));
	int count = 0;
	while (window.isOpen())
	{
		int r = rand() % 6 + 1;
		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			if (evnt.type == evnt.Closed)
				window.close();
		}
		window.clear();
		b.DrawBoard(window);
		b.DrawPieces(window);
		if (count == 10)
		{
			switch (n)
			{
			case 1:
				window.draw(d1);
				break;
			case 2:
				window.draw(d2);
				break;
			case 3:
				window.draw(d3);
				break;
			case 4:
				window.draw(d4);
				break;
			case 5:
				window.draw(d5);
				break;
			case 6:
				window.draw(d6);
				break;
			}
			window.display();
			break;
		}
		switch (r)
		{
		case 1:
			window.draw(d1);
			break;
		case 2:
			window.draw(d2);
			break;
		case 3:
			window.draw(d3);
			break;
		case 4:
			window.draw(d4);
			break;
		case 5:
			window.draw(d5);
			break;
		case 6:
			window.draw(d6);
			break;
		}
		window.display();
		sf::sleep(sf::seconds(0.1));
		count++;
	}
}
void Dice::DrawMainDice(sf::RenderWindow& window)const
{
	window.draw(d);
}
sf::Sprite Dice::GetDiceAt(int i)const
{
	switch (i)
	{
	case 0:
		return d;
		break;
	case 1:
		return d1;
		break;
	case 2:
		return d2;
		break;
	case 3:
		return d3;
		break;
	case 4:
		return d4;
		break;
	case 5:
		return d5;
		break;
	case 6:
		return d6;
		break;
	}
}
