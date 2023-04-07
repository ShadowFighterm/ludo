#include "Board.h"
#include<iostream>
#include<fstream>
#include"Shape.h"
#include"Rectangle.h"
#include"Global.h"
#include"RedPiece.h"
#include"BluePiece.h"
#include"YellowPiece.h"
#include"GreenPiece.h"
#include"CyanPiece.h"
#include"OrangePiece.h"
#include<iostream>
using namespace std;
Board::Board(sf::RenderWindow& window, int nop)
{
	f.loadFromFile("arial.ttf");
	ludo.setCharacterSize(30);
	ludo.setFillColor(sf::Color::Black);
	ludo.setFont(f);
	ludo.setPosition((float)window.getSize().x / 2 - 120, window.getSize().y / 2 - 20);
	ludo.setString("L U D O");
	tbg.loadFromFile("background.jpg");
	bg.setTexture(tbg);
	bg.setScale((float)window.getSize().x / tbg.getSize().x, (float)window.getSize().y / tbg.getSize().y);
	tstr.loadFromFile("star.png");
	star.setTexture(tstr);
	sf::Color lightYellow(255, 255, 204); // for path
	sf::Color orange(255, 165, 0);
	Position p;
	ifstream cin1("BoardLoad.txt");
	ofstream cout1("PieceLoad.txt");
	this->dim.x = 24;
	this->dim.y = 15;
	Global::SqrDim.x = (float)window.getSize().x / (dim.x + 3);
	Global::SqrDim.y = (float)window.getSize().y / dim.y;
	star.setScale((float)Global::SqrDim.x / tstr.getSize().x, (float)Global::SqrDim.y / tstr.getSize().y);
	char input;
	this->pcs = new Piece **[dim.y];// 4 is the nop
	this->shp = new Shape**[dim.y];
	for (int i = 0;i < dim.y;i++)
	{
		this->shp[i] = new Shape * [dim.x];
		for (int j = 0;j < dim.x;j++)
		{
			p.ri = i;
			p.ci = j;
			cin1 >> input;
			switch (input)
			{
			case'-':
			case',':
				this->shp[i][j] = new Rectangle(sf::Color::White, sf::Color::White, p, input);
				break;
			case'?':
				this->shp[i][j] = new Rectangle(lightYellow, sf::Color::Black, p, input);
				break;
			case'.':
				this->shp[i][j] = new Rectangle(lightYellow, sf::Color::Black, p, input);
				break;
			case'#':
				this->shp[i][j] = new Rectangle(sf::Color::Cyan, sf::Color::Cyan, p, input);
				break;
			case'B':
			case'b':
			case'+':
				this->shp[i][j] = new Rectangle(sf::Color::Blue, sf::Color::Black, p, input);
				break;
			case'R':
			case'r':
			case'/':
				this->shp[i][j] = new Rectangle(sf::Color::Red, sf::Color::Black, p, input);
				break;
			case'Y':
			case'y':
			case'_':
				this->shp[i][j] = new Rectangle(sf::Color::Yellow, sf::Color::Black, p, input);
				break;
			case'G':
			case'g':
			case'*':
				this->shp[i][j] = new Rectangle(sf::Color::Green, sf::Color::Black, p, input);
				break;
			case'C':
			case'c':
			case'|':
				this->shp[i][j] = new Rectangle(sf::Color::Cyan, sf::Color::Black, p, input);
				break;
			case'O':
			case'o':
			case'&':
				this->shp[i][j] = new Rectangle(orange, sf::Color::Black, p, input);
				break;
			case'1':
				this->shp[i][j] = new Rectangle(sf::Color::Red, sf::Color::Red, p, input);
				break;
			case'2':
				this->shp[i][j] = new Rectangle(sf::Color::Green, sf::Color::Green, p, input);
				break;
			case'3':
				this->shp[i][j] = new Rectangle(sf::Color::Blue, sf::Color::Blue, p, input);
				break;
			case'4':
				this->shp[i][j] = new Rectangle(sf::Color::Yellow, sf::Color::Yellow, p, input);
				break;
			case'5':
				this->shp[i][j] = new Rectangle(sf::Color::Cyan, sf::Color::Cyan, p, input);
				break;
			case '6':
				this->shp[i][j] = new Rectangle(orange, orange, p, input);
				break;
			}
		}
	}
	char id;
	for (int i = 0;i < dim.y;i++)
	{
		this->pcs[i] = new Piece * [dim.x];
		for (int j = 0;j < dim.x;j++)
		{
			id = this->shp[i][j]->GetId();
			switch (nop)
			{
			case 1:
			case 2:
				if(id=='r' || id=='o')
					cout1 << id << " ";
				else
					cout1 << '-' << " ";
				break;
			case 3:
			case 4:
				if(id=='r' || id=='o' || id=='b' || id=='y')
					cout1 << id << " ";
				else
					cout1 << '-' << " ";
				break;
			case 5:
			case 6:
				if (id == 'r' || id == 'g' || id == 'b' || id == 'y' || id == 'c' || id == 'o')
					cout1 << id << " ";
				else
					cout1 << '-' << " ";
				break;
			}
		}
		cout1 << endl;
	}
	ifstream rdr("PieceLoad.txt");
	for (int i = 0;i < dim.y;i++)
	{
		for (int j = 0;j < dim.x;j++)
		{
			rdr >> input;
			p.ri = i;p.ci = j;
			switch (input)
			{
			case'r':
				this->pcs[i][j] = new RedPiece(p, Global::RIGHT, input);
				break;
			case'b':
				this->pcs[i][j] = new BluePiece(p, Global::DOWN, input);
				break;
			case'g':
				this->pcs[i][j] = new GreenPiece(p, Global::UP, input);
				break;
			case'y':
				this->pcs[i][j] = new YellowPiece(p, Global::UP, input);
				break;
			case'c':
				this->pcs[i][j] = new CyanPiece(p, Global::DOWN, input);
				break;
			case'o':
				this->pcs[i][j] = new OrangePiece(p, Global::LEFT, input);
				break;
			default:
				this->pcs[i][j] = nullptr;
				break;
			}
		}
	}
	
}
void Board::DrawBG(sf::RenderWindow& window)const
{
	window.draw(bg);
}
void Board::DrawStar(sf::RenderWindow& window, Position p)
{
	star.setPosition(p.ci * Global::SqrDim.x, p.ri * Global::SqrDim.y);
	window.draw(star);
}
void Board::DrawBoard(sf::RenderWindow& window)
{
	DrawBG(window);
	Position p;
	char c;
	for (int i = 0;i < dim.y;i++)
	{
		for (int j = 0;j < dim.x;j++)
		{
			p.ri = i, p.ci = j;
			c = this->shp[i][j]->GetId();
			this->shp[i][j]->DrawShape(window);
			if (c == '?')
				DrawStar(window, p);
		}
	}
	window.draw(ludo);
}
void Board::DrawPieces(sf::RenderWindow& window)const
{
	for (int i = 0;i < dim.y;i++)
	{
		for (int j = 0;j < dim.x;j++)
		{
			if (this->pcs[i][j] != nullptr)
				this->pcs[i][j]->DrawPiece(window);
		}
	}
}
void Board::UpdateBoard(sf::RenderWindow& window, Position s, Position d)
{
	this->pcs[s.ri][s.ci]->Move(window, d);
	this->pcs[d.ri][d.ci] = this->pcs[s.ri][s.ci];
	this->pcs[s.ri][s.ci] = nullptr;
}
void Board::UpdateBoard(sf::RenderWindow& window, Position s,int n)
{

}
bool Board::IsEmptySpace(Position p)const
{
	return true;
}
Piece* Board::GetPieceAt(Position p)const
{
	return this->pcs[p.ri][p.ci];
}
