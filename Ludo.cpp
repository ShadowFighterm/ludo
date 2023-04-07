#include "Ludo.h"
#include"Board.h"
#include<iostream>
using namespace std;
Ludo::Ludo(sf::RenderWindow& window)
{
	cout << "Enter number of players:" << endl;
	cin >> this->nop;
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
