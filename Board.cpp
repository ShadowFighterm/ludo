#include "Board.h"
#include<iostream>
#include"Rectangle.h"
#include<fstream>
#include"Shape.h"
#include"Global.h"
#include"RedPiece.h"
#include"BluePiece.h"
#include"YellowPiece.h"
#include"GreenPiece.h"
#include"CyanPiece.h"
#include"OrangePiece.h"
using namespace std;
Board::Board(sf::RenderWindow& window, int nop)
{
	this->dim.x = 24;
	this->dim.y = 15;
	win1.setTexture(Global::ts[10]);
	win1.setPosition((float)6 * Global::SqrDim.x, (float)6 * Global::SqrDim.y);
	win1.setScale((float)(3 * Global::SqrDim.x) / Global::ts[10].getSize().x, (float)(3 * Global::SqrDim.y) / Global::ts[10].getSize().y);
	win2.setTexture(Global::ts[11]);
	win2.setScale((float)(3 * Global::SqrDim.x) / Global::ts[11].getSize().x, (float)(3 * Global::SqrDim.y) / Global::ts[11].getSize().y);
	win2.setPosition((float)15 * Global::SqrDim.x, (float)6 * Global::SqrDim.y);
	ludo.setCharacterSize(30);
	ludo.setFillColor(sf::Color::Black);
	ludo.setFont(Global::f);
	ludo.setString("* L U D O *");
	ludo.setPosition((float)(Global::SqrDim.x * dim.x) / 2 - Global::SqrDim.x, (float)window.getSize().y / 2 - (Global::SqrDim.y/4));
	bg.setTexture(Global::ts[7]);
	bg.setScale((float)window.getSize().x / Global::ts[7].getSize().x, (float)window.getSize().y / Global::ts[7].getSize().y);
	star.setTexture(Global::ts[6]);
	star.setScale((float)Global::SqrDim.x / Global::ts[6].getSize().x, (float)Global::SqrDim.y / Global::ts[6].getSize().y);
	sf::Color lightYellow(255, 255, 204);
	sf::Color orange(255, 165, 0);
	sf::Color goldenRod(218, 165, 32);
	sf::Color khaki(240, 230, 140);
	sf::Color slateGray(112, 128, 144);
	Position p;
	ifstream cin1("BoardLoad.txt");
	ofstream cout1("PieceLoad.txt");
	char input;
	this->pcs.resize(dim.y);
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
				this->shp[i][j] = new Rectangle(khaki, sf::Color::Black, p, input);
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
			case'`':
				this->shp[i][j] = new Rectangle(sf::Color::Blue, sf::Color::Black, p, input);
				break;
			case'R':
			case'r':
			case'/':
			case')':
				this->shp[i][j] = new Rectangle(sf::Color::Red, sf::Color::Black, p, input);
				break;
			case'Y':
			case'y':
			case'_':
			case'~':
				this->shp[i][j] = new Rectangle(sf::Color::Yellow, sf::Color::Black, p, input);
				break;
			case'G':
			case'g':
			case'*':
			case'>':
				this->shp[i][j] = new Rectangle(sf::Color::Green, sf::Color::Black, p, input);
				break;
			case'C':
			case'c':
			case'|':
			case'!':
				this->shp[i][j] = new Rectangle(sf::Color::Cyan, sf::Color::Black, p, input);
				break;
			case'O':
			case'o':
			case'&':
			case'<':
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
			default:
				cout << input << "not found";
			}
		}
	}
	char id;
	
	for (int i = 0;i < dim.y;i++)
	{
		for (int j = 0;j < dim.x;j++)
		{
			id = this->shp[i][j]->GetId();
			switch (nop)
			{
			case 2:
				if(id=='r' || id=='o')
					cout1 << id << " ";
				else
					cout1 << '-' << " ";
				break;
			case 4:
				if(id=='r' || id=='o' || id=='b' || id=='y')
					cout1 << id << " ";
				else
					cout1 << '-' << " ";
				break;
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
		this->pcs[i].resize(dim.x);
		for (int j = 0;j < dim.x;j++)
		{
			rdr >> input;
			p.ri = i;p.ci = j;
			switch (input)
			{
			case'r':
				this->pcs[i][j].push_back(RedPiece(p, Global::RIGHT, input));
				break;
			case'b':
				this->pcs[i][j].push_back(BluePiece(p, Global::DOWN, input));
				break;
			case'g':
				this->pcs[i][j].push_back(GreenPiece(p, Global::UP, input));
				break;
			case'y':
				this->pcs[i][j].push_back(YellowPiece(p, Global::UP, input));
				break;
			case'c':
				this->pcs[i][j].push_back(CyanPiece(p, Global::DOWN, input));
				break;
			case'o':
				this->pcs[i][j].push_back(OrangePiece(p, Global::LEFT, input));
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
void Board::DrawBoard(sf::RenderWindow& window)const
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
		}
	}
	window.draw(ludo);
	window.draw(win1);
	window.draw(win2);
}
bool Board::IsOnBoard(Position p)const
{
	return IsValidPath(p);
}
int Board::GetPieceCountOnBoard(char id)const
{
	int count = 0;
	for(int i=0;i<dim.y;i++ )
	{
		for (int j = 0;j < dim.x;j++)
		{
			for (int k = 0;k < pcs[i][j].size();k++)
			{
				if (pcs[i][j][k].GetId() == id && IsOnBoard({i,j}))
					count++;
			}
		}
	}
	return count;
}
int Board::GetPieceCountAtHome(char id)const
{
	int count = 0;
	for (int i = 0;i < dim.y;i++)
	{
		for (int j = 0;j < dim.x;j++)
		{
			for (int k = 0;k < pcs[i][j].size();k++)
			{
				if (pcs[i][j][k].GetId() == id && pcs[i][j][k].IsAtHome({ i,j }))
					count++;
			}
		}
	}
	return count;
}
void Board::DrawPieces(sf::RenderWindow& window)const
{
	for (int i = 0;i < dim.y;i++)
	{
		for (int j = 0;j < dim.x;j++)
		{
			if (this->pcs[i][j].size() != 0)
			{
				for (int k = 0;k < this->pcs[i][j].size();k++)
				{
					this->pcs[i][j][k].DrawPiece(window);
				}
			}
		}
	}
}
void Board::UpdateBoard(sf::RenderWindow& window, sf::Vector3f s, Position d)
{
	this->pcs[s.y][s.x][s.z].Move(window, d);
	this->pcs[d.ri][d.ci].push_back(this->pcs[s.y][s.x][s.z]);
	this->pcs[s.y][s.x].erase(this->pcs[s.y][s.x].begin() + s.z);
	SetPieces();
}
bool Board::IsCheckpoint(Position p)const
{
	char sid = shp[p.ri][p.ci]->GetId();
	if (sid == '/' || sid == '*' || sid == '+' || sid == '_' || sid == '|' || sid == '&' || sid == ')' || sid == '!' || sid == '?' || sid == '`' || sid == '<' || sid == '>' || sid == '~')
		return true;
	return false;
}
bool Board::IsValidPath(Position p)const
{
	char sid = shp[p.ri][p.ci]->GetId();
	return sid == '.' || sid == '?' || sid == '/' || sid == '*' || sid == '+' || sid == '_' || sid == '|' || sid == '&' || sid == 'R' || sid == 'G' || sid == 'B' || sid == 'Y' || sid == 'C' || sid == 'O' || sid == '<' || sid == '>' || sid == '~' || sid == '`' || sid == '!' || sid == ')';
}
bool Board::CanPieceWin(sf::Vector3f& s, int n)const
{
	int count = 0;
	Position d;
	d.ri = s.y, d.ci = s.x;
	Piece p = pcs[s.y][s.x][s.z];
	while (count != n)
	{
		switch (p.GetDir())
		{
		case Global::UP:
			d.ri--;
			if (d.ri != -1 && IsValidPath(d))
			{
				count++;
				if (p.IsRoundCompleted(d))
					p.SetDir(Global::RIGHT);
			}
			else
			{
				if (d.ri == -1 || shp[d.ri][d.ci]->GetId() != '#')
					d.ri++;
				if (d.ci - 1 != -1 && IsValidPath({ d.ri,d.ci - 1 }))
					p.SetDir(Global::LEFT);
				else if (IsValidPath({ d.ri,d.ci + 1 }))
					p.SetDir(Global::RIGHT);
				else
				{
					if (count + 1 == n && p.IsPieceWin(d))
						return true;
					else
						return false;
				}
			}
			break;
		case Global::DOWN:
			d.ri++;
			if (d.ri != dim.y && IsValidPath(d))
			{
				count++;
				if (p.IsRoundCompleted(d))
					p.SetDir(Global::LEFT);
			}
			else
			{
				if (d.ri == dim.y || shp[d.ri][d.ci]->GetId() != '#')
					d.ri--;
				if (d.ci + 1 != dim.x && IsValidPath({ d.ri,d.ci + 1 }))
					p.SetDir(Global::RIGHT);
				else if (IsValidPath({ d.ri,d.ci - 1 }))
					p.SetDir(Global::LEFT);
				else
				{
					if (count + 1 == n && p.IsPieceWin(d))
						return true;
					else
						return false;
				}
			}
			break;
		case Global::LEFT:
			d.ci--;
			if (d.ci != -1 && IsValidPath(d))
			{
				count++;
				if (pcs[s.y][s.x][s.z].IsRoundCompleted(d))
					p.SetDir(Global::UP);
			}
			else
			{
				if (d.ci == -1 || shp[d.ri][d.ci]->GetId() != '#')
					d.ci++;
				if (IsValidPath({ d.ri - 1,d.ci }))
					p.SetDir(Global::UP);
				else if (d.ri + 1 != dim.y && IsValidPath({ d.ri + 1,d.ci }))
					p.SetDir(Global::DOWN);
				else
				{
					if (count + 1 == n && p.IsPieceWin(d))
						return true;
					else
						return false;
				}
			}
			break;
		case Global::RIGHT:
			d.ci++;
			if (d.ci != dim.x && IsValidPath(d))
			{
				count++;
				if (pcs[s.y][s.x][s.z].IsRoundCompleted(d))
					p.SetDir(Global::DOWN);
			}
			else
			{
				if (d.ci == dim.x || shp[d.ri][d.ci]->GetId() != '#')
					d.ci--;
				if (d.ri - 1 != -1 && IsValidPath({ d.ri - 1,d.ci }))
					p.SetDir(Global::UP);
				else if (IsValidPath({ d.ri + 1,d.ci }))
					p.SetDir(Global::DOWN);
				else
				{
					if (count + 1 == n && p.IsPieceWin(d))
						return true;
					else
						return false;
				}
			}
			break;
		}
	}
	return true;
}
bool Board::IsPathClear(sf::Vector3f&s, int n)const
{
	bool jota = false;
	int count = 0;
	Position d;
	d.ri = s.y, d.ci = s.x;
	if (n % 2 == 0 && pcs[s.y][s.x].size() == 2 && !IsCheckpoint(d))
		jota = true;
	Piece p = pcs[s.y][s.x][s.z];
	while (count != n)
	{
		switch (p.GetDir())
		{
		case Global::UP:
			d.ri--;
			if (d.ri != -1 && IsValidPath(d))
			{
				count++;
				if (p.IsRoundCompleted(d))
					p.SetDir(Global::RIGHT);
			}
			else
			{
				if (d.ri == -1 || shp[d.ri][d.ci]->GetId() != '#')
					d.ri++;
				if (d.ci - 1 != -1 && IsValidPath({ d.ri,d.ci - 1 }))
					p.SetDir(Global::LEFT);
				else if (IsValidPath({ d.ri,d.ci + 1 }))
					p.SetDir(Global::RIGHT);
				else
					return true;
			}
			break;
		case Global::DOWN:
			d.ri++;
			if (d.ri != dim.y && IsValidPath(d))
			{
				count++;
				if (p.IsRoundCompleted(d))
					p.SetDir(Global::LEFT);
			}
			else
			{
				if (d.ri == dim.y || shp[d.ri][d.ci]->GetId() != '#')
					d.ri--;
				if (d.ci + 1 != dim.x && IsValidPath({ d.ri,d.ci + 1 }))
					p.SetDir(Global::RIGHT);
				else if (IsValidPath({ d.ri,d.ci - 1 }))
					p.SetDir(Global::LEFT);
				else
					return true;
			}
			break;
		case Global::LEFT:
			d.ci--;
			if (d.ci != -1 && IsValidPath(d))
			{
				count++;
				if (pcs[s.y][s.x][s.z].IsRoundCompleted(d))
					p.SetDir(Global::UP);
			}
			else
			{
				if (d.ci == -1 || shp[d.ri][d.ci]->GetId() != '#')
					d.ci++;
				if (IsValidPath({ d.ri - 1,d.ci }))
					p.SetDir(Global::UP);
				else if (d.ri + 1 != dim.y && IsValidPath({ d.ri + 1,d.ci }))
					p.SetDir(Global::DOWN);
				else
					return true;
			}
			break;
		case Global::RIGHT:
			d.ci++;
			if (d.ci != dim.x && IsValidPath(d))
			{
				count++;
				if (pcs[s.y][s.x][s.z].IsRoundCompleted(d))
					p.SetDir(Global::DOWN);
			}
			else
			{
				if (d.ci == dim.x || shp[d.ri][d.ci]->GetId() != '#')
					d.ci--;
				if (d.ri - 1 != -1 && IsValidPath({ d.ri - 1,d.ci }))
					p.SetDir(Global::UP);
				else if (IsValidPath({ d.ri + 1,d.ci }))
					p.SetDir(Global::DOWN);
				else
					return true;
			}
			break;
		}
		if (!jota)
		{
			if (pcs[d.ri][d.ci].size() >= 2 && !IsCheckpoint(d) && pcs[s.y][s.x][s.z].GetId() != pcs[d.ri][d.ci][0].GetId())
				return false;
		}
		else
		{
			if (count!=n && pcs[d.ri][d.ci].size() >= 2 && !IsCheckpoint(d) && pcs[s.y][s.x][s.z].GetId() != pcs[d.ri][d.ci][0].GetId())
				return false;
		}
	}
	if (jota && !IsCheckpoint(d) && pcs[d.ri][d.ci].size() >= 3 && pcs[s.y][s.x][s.z].GetId() != pcs[d.ri][d.ci][0].GetId())
		return false;
	return true;
}
void Board::UpdateBoard(sf::RenderWindow& window, Player&p, const vector<int>&score, sf::Vector3f s, int n)
{
	bool jota = false;
	int count = 0;
	Position d;
	d.ri = s.y, d.ci = s.x;
	if (n % 2 == 0 && pcs[s.y][s.x].size() == 2 && !IsCheckpoint(d))
		jota = true;
	while (window.isOpen())
	{
		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			if (evnt.type == evnt.Closed)
				window.close();
		}
		switch (pcs[s.y][s.x][s.z].GetDir())
		{
		case Global::UP:
			d.ri--;
			if (d.ri != -1 && IsValidPath(d) || d.ri!=-1 && pcs[s.y][s.x][s.z].IsPieceWin(d))
			{
				if (jota)
				{
					pcs[s.y][s.x][0].Move(window, d);
					pcs[s.y][s.x][1].Move(window, d);
					count += 2;
					if (pcs[s.y][s.x][s.z].IsRoundCompleted(d))
					{
						pcs[s.y][s.x][0].SetDir(Global::RIGHT);
						pcs[s.y][s.x][1].SetDir(Global::RIGHT);
					}
				}
				else
				{
					pcs[s.y][s.x][s.z].Move(window, d);
					count++;
					if (pcs[s.y][s.x][s.z].IsRoundCompleted(d))
						pcs[s.y][s.x][s.z].SetDir(Global::RIGHT);
				}
			}
			else
			{
				if (d.ri == -1 || shp[d.ri][d.ci]->GetId() != '#')
					d.ri++;
				if (jota)
				{
					if (d.ci - 1 != -1 && IsValidPath({ d.ri,d.ci - 1 }))
					{
						pcs[s.y][s.x][0].SetDir(Global::LEFT);
						pcs[s.y][s.x][1].SetDir(Global::LEFT);
					}
					else if (IsValidPath({ d.ri,d.ci + 1 }))
					{
						pcs[s.y][s.x][0].SetDir(Global::RIGHT);
						pcs[s.y][s.x][1].SetDir(Global::RIGHT);
					}
				}
				else
				{
					if (d.ci - 1 != -1 && IsValidPath({ d.ri,d.ci - 1 }))
						pcs[s.y][s.x][s.z].SetDir(Global::LEFT);
					else if (IsValidPath({ d.ri,d.ci + 1 }))
						pcs[s.y][s.x][s.z].SetDir(Global::RIGHT);
				}
			}
			break;
		case Global::DOWN:
			d.ri++;
			if (d.ri != dim.y && IsValidPath(d) || d.ri!=dim.y && pcs[s.y][s.x][s.z].IsPieceWin(d))
			{
				if (jota)
				{
					pcs[s.y][s.x][0].Move(window, d);
					pcs[s.y][s.x][1].Move(window, d);
					count+=2;
					if (pcs[s.y][s.x][s.z].IsRoundCompleted(d))
					{
						pcs[s.y][s.x][0].SetDir(Global::LEFT);
						pcs[s.y][s.x][1].SetDir(Global::LEFT);
					}
				}
				else
				{
					pcs[s.y][s.x][s.z].Move(window, d);
					count++;
					if (pcs[s.y][s.x][s.z].IsRoundCompleted(d))
						pcs[s.y][s.x][s.z].SetDir(Global::LEFT);
				}
			}
			else
			{
				if (d.ri == dim.y || shp[d.ri][d.ci]->GetId() != '#')
					d.ri--;
				if (jota)
				{
					if (d.ci + 1 != dim.x && IsValidPath({ d.ri,d.ci + 1 }))
					{
						pcs[s.y][s.x][0].SetDir(Global::RIGHT);
						pcs[s.y][s.x][1].SetDir(Global::RIGHT);
					}
					else if (IsValidPath({ d.ri,d.ci - 1 }))
					{
						pcs[s.y][s.x][0].SetDir(Global::LEFT);
						pcs[s.y][s.x][1].SetDir(Global::LEFT);
					}
				}
				else
				{
					if (d.ci + 1 != dim.x && IsValidPath({ d.ri,d.ci + 1 }))
						pcs[s.y][s.x][s.z].SetDir(Global::RIGHT);
					else if (IsValidPath({ d.ri,d.ci - 1 }))
						pcs[s.y][s.x][s.z].SetDir(Global::LEFT);
				}
			}
			break;
		case Global::LEFT:
			d.ci--;
			if (d.ci != -1 && IsValidPath(d) || d.ci!=-1 && pcs[s.y][s.x][s.z].IsPieceWin(d))
			{
				if (jota)
				{
					pcs[s.y][s.x][0].Move(window, d);
					pcs[s.y][s.x][1].Move(window, d);
					count+=2;
					if (pcs[s.y][s.x][s.z].IsRoundCompleted(d))
					{
						pcs[s.y][s.x][0].SetDir(Global::UP);
						pcs[s.y][s.x][1].SetDir(Global::UP);
					}
				}
				else
				{
					pcs[s.y][s.x][s.z].Move(window, d);
					count++;
					if (pcs[s.y][s.x][s.z].IsRoundCompleted(d))
						pcs[s.y][s.x][s.z].SetDir(Global::UP);
				}
			}
			else
			{
				if (d.ci == -1 || shp[d.ri][d.ci]->GetId() != '#')
					d.ci++;
				if (jota)
				{
					if (IsValidPath({ d.ri - 1,d.ci }))
					{
						pcs[s.y][s.x][0].SetDir(Global::UP);
						pcs[s.y][s.x][1].SetDir(Global::UP);
					}
					else if (d.ri + 1 != dim.y && IsValidPath({ d.ri + 1,d.ci }))
					{
						pcs[s.y][s.x][0].SetDir(Global::DOWN);
						pcs[s.y][s.x][1].SetDir(Global::DOWN);
					}
				}
				else
				{
					if (IsValidPath({ d.ri - 1,d.ci }))
						pcs[s.y][s.x][s.z].SetDir(Global::UP);
					else if (d.ri + 1 != dim.y && IsValidPath({ d.ri + 1,d.ci }))
						pcs[s.y][s.x][s.z].SetDir(Global::DOWN);
				}
			}
			break;
		case Global::RIGHT:
			d.ci++;
			if (d.ci != dim.x && IsValidPath(d) || d.ci != dim.x && pcs[s.y][s.x][s.z].IsPieceWin(d))
			{
				if (jota)
				{
					pcs[s.y][s.x][0].Move(window, d);
					pcs[s.y][s.x][1].Move(window, d);
					count+=2;
					if (pcs[s.y][s.x][s.z].IsRoundCompleted(d))
					{
						pcs[s.y][s.x][0].SetDir(Global::DOWN);
						pcs[s.y][s.x][1].SetDir(Global::DOWN);
					}
				}
				else
				{
					pcs[s.y][s.x][s.z].Move(window, d);
					count++;
					if (pcs[s.y][s.x][s.z].IsRoundCompleted(d))
						pcs[s.y][s.x][s.z].SetDir(Global::DOWN);
				}
			}
			else
			{
				if (d.ci == dim.x || shp[d.ri][d.ci]->GetId() != '#')
					d.ci--;
				if (jota)
				{
					if (d.ri - 1 != -1 && IsValidPath({ d.ri - 1,d.ci }))
					{
						pcs[s.y][s.x][0].SetDir(Global::UP);
						pcs[s.y][s.x][1].SetDir(Global::UP);
					}
					else if (IsValidPath({ d.ri + 1,d.ci }))
					{
						pcs[s.y][s.x][0].SetDir(Global::DOWN);
						pcs[s.y][s.x][1].SetDir(Global::DOWN);
					}
				}
				else
				{
					if (d.ri - 1 != -1 && IsValidPath({ d.ri - 1,d.ci }))
						pcs[s.y][s.x][s.z].SetDir(Global::UP);
					else if (IsValidPath({ d.ri + 1,d.ci }))
						pcs[s.y][s.x][s.z].SetDir(Global::DOWN);
				}
			}
			break;
		}
		window.clear();
		DrawBoard(window);
		DrawPieces(window);
		p.GetDice().DrawMainDice(window);
		p.GetDice().DisplayNumbers(window, score);
		window.display();
		sf::sleep(sf::seconds(0.1));
		if (count == n)
		{
			if (!IsCheckpoint(d) && !IsEmptySpace(d) && pcs[d.ri][d.ci][0].GetId() != pcs[s.y][s.x][s.z].GetId())
			{
				if (jota)
				{
					pcs[d.ri][d.ci][0].Move(window, pcs[d.ri][d.ci][0].GetHome());
					pcs[d.ri][d.ci][1].Move(window, pcs[d.ri][d.ci][1].GetHome());
					pcs[d.ri][d.ci][0].SetIsFirst(true);
					pcs[d.ri][d.ci][1].SetIsFirst(true);
					pcs[pcs[d.ri][d.ci][0].GetHome().ri][pcs[d.ri][d.ci][0].GetHome().ci].push_back(pcs[d.ri][d.ci][0]);
					pcs[pcs[d.ri][d.ci][1].GetHome().ri][pcs[d.ri][d.ci][1].GetHome().ci].push_back(pcs[d.ri][d.ci][1]);
					pcs[d.ri][d.ci].erase(pcs[d.ri][d.ci].begin() + 0);
					pcs[d.ri][d.ci].erase(pcs[d.ri][d.ci].begin() + 0);
					p.SetHasRolled(false);
				}
				else
				{
					pcs[d.ri][d.ci][0].Move(window, pcs[d.ri][d.ci][0].GetHome());
					pcs[d.ri][d.ci][0].SetIsFirst(true);
					pcs[pcs[d.ri][d.ci][0].GetHome().ri][pcs[d.ri][d.ci][0].GetHome().ci].push_back(pcs[d.ri][d.ci][0]);
					pcs[d.ri][d.ci].erase(pcs[d.ri][d.ci].begin() + 0);
					p.SetHasRolled(false);
				}
			}
			if (jota)
			{
				this->pcs[d.ri][d.ci].push_back(this->pcs[s.y][s.x][0]);
				this->pcs[d.ri][d.ci].push_back(this->pcs[s.y][s.x][1]);
				this->pcs[s.y][s.x].erase(this->pcs[s.y][s.x].begin() + 0);
				this->pcs[s.y][s.x].erase(this->pcs[s.y][s.x].begin() + 0);
				if (pcs[d.ri][d.ci][pcs[d.ri][d.ci].size() - 1].IsPieceWin(d))
				{
					pcs[d.ri][d.ci].erase(pcs[d.ri][d.ci].begin() + 0);
					pcs[d.ri][d.ci].erase(pcs[d.ri][d.ci].begin() + 0);
				}
			}
			else
			{
				this->pcs[d.ri][d.ci].push_back(this->pcs[s.y][s.x][s.z]);
				this->pcs[s.y][s.x].erase(this->pcs[s.y][s.x].begin() + s.z);
				if (pcs[d.ri][d.ci][pcs[d.ri][d.ci].size() - 1].IsPieceWin(d))
					pcs[d.ri][d.ci].erase(pcs[d.ri][d.ci].begin() + (pcs[d.ri][d.ci].size() - 1));
			}
			SetPieces();
			break;
		}
	}
}
bool Board::IsEmptySpace(Position p)const
{
	return this->pcs[p.ri][p.ci].size() == 0;
}
void Board::SetPieces()
{
	for (int i = 0;i < dim.y;i++)
	{
		for (int j = 0;j < dim.x;j++)
		{
			for (int k = 0;k < pcs[i][j].size();k++)
			{
				pcs[i][j][k].SetPiece(k);
			}
		}
	}
}
Piece Board::GetPieceAt(sf::Vector3f p)const
{
	return this->pcs[p.y][p.x][p.z];
}
vector<Piece> Board::GetPiecesAt(Position p)
{
	return this->pcs[p.ri][p.ci];
}
Shape* Board::GetShapeAt(Position p)const
{
	return this->shp[p.ri][p.ci];
}
const sf::Vector2f& Board::GetDim()const
{
	return this->dim;
}
void Board::DeleteBoard()
{
	for (int i = 0;i < dim.y;i++)
	{
		for (int j = 0;j < dim.x;j++)
		{
			pcs[i][j].clear();
		}
		pcs[i].clear();
	}
	for (int i = 0;i < dim.y;i++)
	{
		for (int j = 0;j < dim.x;j++)
		{
			delete shp[i][j];
		}
		delete[]shp[i];
	}
}
Board::~Board()
{
	DeleteBoard();
}
