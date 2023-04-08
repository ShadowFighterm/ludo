#include "Ludo.h"
#include"Board.h"
#include"Global.h"
#include<iostream>
using namespace std;
void Ludo::MainMenu(sf::RenderWindow& window)
{
	sf::Text p2;
	sf::Sprite logo;
	sf::Sprite menubg;
	sf::Sprite twop;
	logo.setTexture(Global::ts[8]);
	logo.setScale(1, 1);
	logo.setPosition((float)window.getSize().x / 3 + (window.getSize().x / 32),(float) window.getSize().y / 8);
	menubg.setTexture(Global::ts[9]);
	menubg.setScale((float)window.getSize().x / Global::ts[9].getSize().x, (float)window.getSize().y / Global::ts[9].getSize().y);
	twop.setTexture(Global::ts[10]);
	twop.setScale(0.2, 0.2);
	twop.setPosition((float)window.getSize().x / 2 - 40, (float)window.getSize().y / 3);
	p2.setFont(Global::f);
	p2.setString("2 Player");
	p2.setCharacterSize(20);
	//p2.setFillColor(sf::Color::White);
	p2.setPosition((float)window.getSize().x / 2 - 40, (float)window.getSize().y / 3);
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
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (p2.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window))))
			{
				nop = 2;
				break;
			}
		}
		window.clear();
		window.draw(menubg);
		window.draw(logo);
		window.draw(p2);
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
			}
		}
		window.clear();
		b->DrawBoard(window);
		b->DrawPieces(window);
		window.display();
	}
}
