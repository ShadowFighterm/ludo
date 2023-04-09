#include "Ludo.h"
#include"Board.h"
#include"Piece.h"
#include"Shape.h"
#include"Global.h"
#include<iostream>
using namespace std;
void Ludo::MainMenu(sf::RenderWindow& window)
{
	sf::Text p2;
	sf::Text p4;
	sf::Text p6;
	sf::Sprite logo;
	sf::Sprite menubg;
	sf::Sprite twop;
	logo.setTexture(Global::ts[8]);
	logo.setScale(1, 1);
	logo.setPosition((float)window.getSize().x / 3 + (window.getSize().x / 32), (float)window.getSize().y / 8);
	menubg.setTexture(Global::ts[9]);
	menubg.setScale((float)window.getSize().x / Global::ts[9].getSize().x, (float)window.getSize().y / Global::ts[9].getSize().y);
	twop.setTexture(Global::ts[10]);
	twop.setScale(0.2, 0.2);
	twop.setPosition((float)window.getSize().x / 2 - 40, (float)window.getSize().y / 3);
	p2.setFont(Global::f);
	p2.setString("2 Player");
	p2.setCharacterSize(30);
	p2.setPosition((float)window.getSize().x / 2 - 70, (float)window.getSize().y / 3 + 50);
	p4.setCharacterSize(30);
	p4.setFont(Global::f);
	p4.setString("4 Player");
	p4.setPosition((float)window.getSize().x / 2 - 70, (float)window.getSize().y / 3 + 120);
	p6.setCharacterSize(30);
	p6.setFont(Global::f);
	p6.setString("6 Player");
	p6.setPosition((float)window.getSize().x / 2 - 70, (float)window.getSize().y / 3 + 190);

	while (window.isOpen())
	{
		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			if (evnt.type == evnt.Closed)
				window.close();
		}
		if (p2.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window))))
			p2.setFillColor(sf::Color::Green);
		else
			p2.setFillColor(sf::Color::White);
		if (p4.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window))))
			p4.setFillColor(sf::Color::Green);
		else
			p4.setFillColor(sf::Color::White);

		if (p6.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window))))
			p6.setFillColor(sf::Color::Green);
		else
			p6.setFillColor(sf::Color::White);

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (p2.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window))))
			{
				nop = 2;
				break;
			}
			if (p4.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window))))
			{
				nop = 4;
				break;
			}
			if (p6.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window))))
			{
				nop = 6;
				break;
			}

		}
		window.clear();
		window.draw(menubg);
		window.draw(logo);
		window.draw(p2);
		window.draw(p4);
		window.draw(p6);
		window.display();
	}
}
Ludo::Ludo(sf::RenderWindow& window)
{
	Global::ts = new sf::Texture[11];
	Global::f.loadFromFile("arial.ttf");
	Global::ts[0].loadFromFile("red_piece.png");
	Global::ts[1].loadFromFile("green_piece.png");
	Global::ts[2].loadFromFile("blue_piece.png");
	Global::ts[3].loadFromFile("yellow_piece.png");
	Global::ts[4].loadFromFile("cyan_piece.png");
	Global::ts[5].loadFromFile("orange_piece.png");
	Global::ts[6].loadFromFile("star.png");
	Global::ts[7].loadFromFile("background.jpg");
	Global::ts[8].loadFromFile("logo.png");
	Global::ts[9].loadFromFile("menu_bg.jpg");
	Global::ts[10].loadFromFile("two_player.png");
	MainMenu(window);
	this->IsDesSel = false;
	this-> IsSocSel = false;
	this->turn = 1;
	this->b = new Board(window, nop);
}
void Ludo::Play(sf::RenderWindow& window)
{
	while (window.isOpen())
	{
		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			switch (evnt.type)
			{
			case evnt.Closed:
				window.close();
			case evnt.MouseButtonPressed:
				SelectPosition(window);
			}
		}
		window.clear();
		b->DrawBoard(window);
		b->DrawPieces(window);
		window.display();
	}
}
bool Ludo::InBound()const
{
	if (s.ri < 0 || s.ri >= b->GetDim().y || s.ci < 0 || s.ci >= b->GetDim().x)
		return false;
	return true;
}
bool Ludo::IsValidSource()const
{
	if (b->IsEmptySpace(s))
		return false;
	char id = b->GetPieceAt(s)->GetId();
	if (turn == 1 && id == 'r' || turn == 2 && id == 'g' || turn == 3 && id == 'b' || turn == 4 && id == 'y' || turn == 5 && id == 'c' || turn == 6 && id == 'o')
		return true;
	return false;
}
bool Ludo::IsValidDestin()const
{
	char id = b->GetShapeAt(d)->GetId();
	if (turn == 1 && id == '/' || turn == 2 && id == '*' || turn == 3 && id == '+' || turn == 4 && id == '_' || turn == 5 && id == '|' || turn == 6 && id == '&')
		return true;
	return false;
}
void Ludo::SelectPosition(sf::RenderWindow& window)
{
	Position soc = s;
	Position des = d;
	Position p;
	Global::getRowColbyLeftClick(p.ri, p.ci, window);
	p.ri /= Global::SqrDim.y;
	p.ci /= Global::SqrDim.x;
	s = p;
	d = p;
	if (!IsSocSel && IsValidSource())
	{
		soc = p;
		IsSocSel = true;
		if (!b->GetPieceAt(p)->GetIsFirst())
			IsDesSel = true;
	}
	else if (!IsDesSel && IsSocSel && IsValidDestin())
	{
		des = p;
		IsDesSel = true;
	}
	else
	{
		IsDesSel = false;
		IsSocSel = false;
	}
	s = soc;
	d = des;
	if (IsSocSel && IsDesSel)
	{
		if (b->GetPieceAt(s)->GetIsFirst())
			b->UpdateBoard(window, s, d);
		else
			b->UpdateBoard(window, s, 2);
	}
}
