#include "Ludo.h"
#include"Board.h"
#include"Piece.h"
#include"Shape.h"
#include"Player.h"
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
		{
			p2.setCharacterSize(40);
			p2.setFillColor(sf::Color::Green);
		}
		else
		{
			p2.setCharacterSize(30);
			p2.setFillColor(sf::Color::White);
		}
		if (p4.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window))))
		{
			p4.setCharacterSize(40);
			p4.setFillColor(sf::Color::Green);
		}
		else
		{
			p4.setCharacterSize(30);
			p4.setFillColor(sf::Color::White);
		}

		if (p6.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window))))
		{
			p6.setCharacterSize(40);
			p6.setFillColor(sf::Color::Green);
		}
		else
		{
			p6.setCharacterSize(30);
			p6.setFillColor(sf::Color::White);
		}

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
	Global::turnId = new char[nop];
	Global::dts = new sf::Texture[nop*6];
	Global::dts[0].loadFromFile("dice_1_red.png");
	Global::dts[1].loadFromFile("dice_2_red.png");
	Global::dts[2].loadFromFile("dice_3_red.png");
	Global::dts[3].loadFromFile("dice_4_red.png");
	Global::dts[4].loadFromFile("dice_5_red.png");
	Global::dts[5].loadFromFile("dice_6_red.png");
	switch (nop)
	{
	case 2:
		Global::turnId[0] = 'r';
		Global::turnId[1] = 'o';
		Global::dts[6].loadFromFile("dice_1_orange.png");
		Global::dts[7].loadFromFile("dice_2_orange.png");
		Global::dts[8].loadFromFile("dice_3_orange.png");
		Global::dts[9].loadFromFile("dice_4_orange.png");
		Global::dts[10].loadFromFile("dice_5_orange.png");
		Global::dts[11].loadFromFile("dice_6_orange.png");
		break;
	case 4:
		Global::turnId[0] = 'r';
		Global::turnId[1] = 'b';
		Global::turnId[2] = 'o';
		Global::turnId[3] = 'y';
		Global::dts[6].loadFromFile("dice_1_blue.png");
		Global::dts[7].loadFromFile("dice_2_blue.png");
		Global::dts[8].loadFromFile("dice_3_blue.png");
		Global::dts[9].loadFromFile("dice_4_blue.png");
		Global::dts[10].loadFromFile("dice_5_blue.png");
		Global::dts[11].loadFromFile("dice_6_blue.png");

		Global::dts[12].loadFromFile("dice_1_orange.png");
		Global::dts[13].loadFromFile("dice_2_orange.png");
		Global::dts[14].loadFromFile("dice_3_orange.png");
		Global::dts[15].loadFromFile("dice_4_orange.png");
		Global::dts[16].loadFromFile("dice_5_orange.png");
		Global::dts[17].loadFromFile("dice_6_orange.png");

		Global::dts[18].loadFromFile("dice_1_yellow.png");
		Global::dts[19].loadFromFile("dice_2_yellow.png");
		Global::dts[20].loadFromFile("dice_3_yellow.png");
		Global::dts[21].loadFromFile("dice_4_yellow.png");
		Global::dts[22].loadFromFile("dice_5_yellow.png");
		Global::dts[23].loadFromFile("dice_6_yellow.png");
		break;
	case 6:
		Global::turnId[0] = 'r';
		Global::turnId[1] = 'c';
		Global::turnId[2] = 'b';
		Global::turnId[3] = 'o';
		Global::turnId[4] = 'g';
		Global::turnId[5] = 'y';
		Global::dts[6].loadFromFile("dice_1_cyan.png");
		Global::dts[7].loadFromFile("dice_2_cyan.png");
		Global::dts[8].loadFromFile("dice_3_cyan.png");
		Global::dts[9].loadFromFile("dice_4_cyan.png");
		Global::dts[10].loadFromFile("dice_5_cyan.png");
		Global::dts[11].loadFromFile("dice_6_cyan.png");

		Global::dts[12].loadFromFile("dice_1_blue.png");
		Global::dts[13].loadFromFile("dice_2_blue.png");
		Global::dts[14].loadFromFile("dice_3_blue.png");
		Global::dts[15].loadFromFile("dice_4_blue.png");
		Global::dts[16].loadFromFile("dice_5_blue.png");
		Global::dts[17].loadFromFile("dice_6_blue.png");

		Global::dts[18].loadFromFile("dice_1_orange.png");
		Global::dts[19].loadFromFile("dice_2_orange.png");
		Global::dts[20].loadFromFile("dice_3_orange.png");
		Global::dts[21].loadFromFile("dice_4_orange.png");
		Global::dts[22].loadFromFile("dice_5_orange.png");
		Global::dts[23].loadFromFile("dice_6_orange.png");

		Global::dts[24].loadFromFile("dice_1_green.png");
		Global::dts[25].loadFromFile("dice_2_green.png");
		Global::dts[26].loadFromFile("dice_3_green.png");
		Global::dts[27].loadFromFile("dice_4_green.png");
		Global::dts[28].loadFromFile("dice_5_green.png");
		Global::dts[29].loadFromFile("dice_6_green.png");

		Global::dts[30].loadFromFile("dice_1_yellow.png");
		Global::dts[31].loadFromFile("dice_2_yellow.png");
		Global::dts[32].loadFromFile("dice_3_yellow.png");
		Global::dts[33].loadFromFile("dice_4_yellow.png");
		Global::dts[34].loadFromFile("dice_5_yellow.png");
		Global::dts[35].loadFromFile("dice_6_yellow.png");
		break;
	}
	int i = 0;
	ps = new Player*[nop];
	sf::RectangleShape box;
	sf::Text name, input;
	string sname, sinput;
	name.setCharacterSize(30);
	name.setPosition((float)window.getSize().x / 5, (float)window.getSize().y / 2 + 10);
	name.setFillColor(sf::Color::Black);
	name.setFont(Global::f);
	box.setPosition((float)window.getSize().x / 3, (float)window.getSize().y / 2);
	box.setFillColor(sf::Color::Transparent);
	box.setOutlineThickness(-(float)5);
	box.setSize(sf::Vector2f((float)window.getSize().x / 4, 60));
	box.setOutlineColor(sf::Color::Green);
	input.setFont(Global::f);
	input.setCharacterSize(30);
	input.setPosition((float)window.getSize().x / 3 + 10, (float)window.getSize().y / 2 + 10);
	input.setFillColor(sf::Color::Magenta);
	while (window.isOpen())
	{
		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			if (evnt.type == evnt.Closed)
				window.close();
			else if (evnt.type == sf::Event::TextEntered)
			{
				if (evnt.text.unicode >= 'a' && evnt.text.unicode <= 'z')
					sinput += static_cast<char>(evnt.text.unicode);
				else if (evnt.text.unicode == '\b' && !sinput.empty())
					sinput.pop_back();
				input.setString(sinput);
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			ps[i] = new Player(sinput, i, Global::turnId[i]);
			sinput.clear();
			input.setString(sinput);
			i++;
			sf::sleep(sf::seconds(0.5));
		}
		if (i == nop)
			break;
		sname = "Player " + to_string(i + 1) + " Name";
		name.setString(sname);
		window.clear();
		window.draw(menubg);
		window.draw(logo);
		window.draw(name);
		window.draw(box);
		window.draw(input);
		window.display();
	}
}
Ludo::Ludo(sf::RenderWindow& window)
{
	Global::SqrDim.x = (float)window.getSize().x / (24 + 3);
	Global::SqrDim.y = (float)window.getSize().y / 15;
	Global::ts = new sf::Texture[10];
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
	MainMenu(window);
	this->IsDesSel = false;
	this-> IsSocSel = false;
	this->HasRolled = false;
	this->ShowNumber = false;
	this->turn = 0;
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
		ps[turn]->GetDice().DrawMainDice(window);
		if (ShowNumber)
			ps[turn]->GetDice().DisplayNumbers(window, score);
		window.display();
	}
}
void Ludo::TurnCh()
{
	turn++;
	if (turn == nop)
		turn = 0;
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
	char id = b->GetPieceAt(rs).GetId();
	if (Global::turnId[turn] == id)
		return true;
	return false;
}
bool Ludo::IsValidDestin()const
{
	char id = b->GetShapeAt(d)->GetId();
	char tid = Global::turnId[turn];
	if (tid == 'r' && id == '/' || tid == 'g' && id == '*' ||tid == 'b' && id == '+' || tid == 'y' && id == '_' || tid == 'c' && id == '|' || tid == 'o' && id == '&')
		return true;
	return false;
}
bool Ludo::IsValidNum()const
{
	int i = s.ci - 24;
	return s.ri == 3 && i != score.size();
}
void Ludo::SelectPosition(sf::RenderWindow& window)
{
	static int i, count6;
	sf::Vector3f rsoc = rs;
	Position soc = s;
	Position des = d;
	Position p;
	Global::getRowColbyLeftClick(p.ri, p.ci, window);
	p.ri /= Global::SqrDim.y;
	p.ci /= Global::SqrDim.x;
	s = p;
	d = p;
	rs.x = p.ci, rs.y = p.ri;
	if (!HasRolled && ps[turn]->GetDice().IsDiceThrown(p))
	{
		ShowNumber = true;
		int s = 6;
		//int s = ps[turn]->RollDice();
		ps[turn]->GetDice().DisplayRoll(window, *b, s);
		score.push_back(s);
		if (s != 6)
		{
			HasRolled = true;
			count6 = 0;
		}
		else
			count6++;
		if (count6 == 3)
		{
			ShowNumber = false;
			HasRolled = false;
			score.clear();
			TurnCh();
		}
	}
	else if (HasRolled && !IsSocSel && InBound())
	{
		for (int k = 0;k < b->GetPiecesAt(s).size();k++)
		{
			rs.z = k;
			if (IsValidSource())
			{
				rsoc = rs;
				soc = p;
				IsSocSel = true;
				break;
			}
		}
	}
	else if (!IsNumSel && IsSocSel && IsValidNum())
	{
		IsNumSel = true;
		rs = rsoc;
		i = p.ci - 24;
		if (!b->GetPieceAt(rs).GetIsFirst())
			IsDesSel = true;
	}
	else if (!IsDesSel && IsSocSel && IsNumSel && InBound() && IsValidDestin())
	{
		des = p;
		IsDesSel = true;
		IsNumSel = false;
	}
	else
	{
		IsNumSel = false;
		IsDesSel = false;
		IsSocSel = false;
	}
	s = soc;
	rs = rsoc;
	d = des;
	if (IsSocSel && IsDesSel)
	{
		IsSocSel = false;
		IsDesSel = false;
		IsNumSel = false;
		if (b->GetPieceAt(rs).GetIsFirst())
			b->UpdateBoard(window, rs, d);
		else
			b->UpdateBoard(window, rs, score[i]);
		score.erase(score.begin() + i);
		if (score.size() == 0)
		{
			ShowNumber = false;
			HasRolled = false;
			TurnCh();
		}
	}
}
