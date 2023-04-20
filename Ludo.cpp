#include "Ludo.h"
#include"Board.h"
#include"Piece.h"
#include"Shape.h"
#include"Player.h"
#include"Global.h"
#include<iostream>
using namespace std;
bool Ludo::IsWin()const
{
	char pid = Global::turnId[turn];
	return b->GetPieceCountOnBoard(pid) == 0 && b->GetPieceCountAtHome(pid) == 0;
}
void Ludo::WinningScreen(sf::RenderWindow& window)const
{
	sf::Sprite menubg;
	string msg;
	msg = ps[turn]->GetName().getString() + "\n Wins!!";
	sf::Text winner;
	winner.setFont(Global::f1);
	winner.setCharacterSize(80);
	winner.setString(msg);
	winner.setPosition((float)window.getSize().x / 2 - (window.getSize().x / 16), (float)window.getSize().y / 3);
	menubg.setTexture(Global::ts[9]);
	menubg.setScale((float)window.getSize().x / Global::ts[9].getSize().x, (float)window.getSize().y / Global::ts[9].getSize().y);
	while (window.isOpen())
	{
		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			if (evnt.type == evnt.Closed)
				window.close();
		}
		window.clear();
		window.draw(menubg);
		window.draw(winner);
		window.display();
	}
}
void Ludo::Pause(sf::RenderWindow& window)
{
	sf::Sprite bg;
	sf::Sprite paused;
	sf::Text restart, resume;
	paused.setTexture(Global::ts[13]);
	paused.setPosition((float)window.getSize().x / 3 + (window.getSize().x / 32), (float)window.getSize().y / 8);
	paused.setScale(0.4, 0.3);
	bg.setTexture(Global::ts[9]);
	bg.setScale((float)window.getSize().x / Global::ts[9].getSize().x, (float)window.getSize().y / Global::ts[9].getSize().y);
	restart.setCharacterSize(30);
	restart.setFont(Global::f);
	restart.setString("Restart");
	restart.setPosition((float)window.getSize().x / 2 - 70, (float)window.getSize().y / 3 + 120);
	resume.setCharacterSize(30);
	resume.setFont(Global::f);
	resume.setString("Resume");
	resume.setPosition((float)window.getSize().x / 2 - 70, (float)window.getSize().y / 3 + 50);
	while (window.isOpen())
	{
		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			if (evnt.type == evnt.Closed)
				window.close();
		}
		if (restart.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window))))
		{
			restart.setCharacterSize(40);
			restart.setFillColor(sf::Color::Green);
		}
		else
		{
			restart.setCharacterSize(30);
			restart.setFillColor(sf::Color::White);
		}
		if (resume.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window))))
		{
			resume.setCharacterSize(40);
			resume.setFillColor(sf::Color::Green);
		}
		else
		{
			resume.setCharacterSize(30);
			resume.setFillColor(sf::Color::White);
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (restart.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window))))
			{
				sf::sleep(sf::seconds(0.5));
				b->DeleteBoard();
				init(window);
				Play(window);
			}
			if (resume.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window))))
				break;
		}
		window.clear();
		window.draw(bg);
		window.draw(paused);
		window.draw(restart);
		window.draw(resume);
		window.display();
	}
}
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
	p2.setFont(Global::f3);
	p2.setString("2 Player");
	p2.setCharacterSize(30);
	p2.setPosition((float)window.getSize().x / 2 - 70, (float)window.getSize().y / 3 + 50);
	p4.setCharacterSize(30);
	p4.setFont(Global::f3);
	p4.setString("4 Player");
	p4.setPosition((float)window.getSize().x / 2 - 70, (float)window.getSize().y / 3 + 120);
	p6.setCharacterSize(30);
	p6.setFont(Global::f3);
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
			p2.setFillColor(sf::Color::Color(173, 234, 24));
		}
		else
		{
			p2.setCharacterSize(30);
			p2.setFillColor(sf::Color::White);
		}
		if (p4.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window))))
		{
			p4.setCharacterSize(40);
			p4.setFillColor(sf::Color::Color(173, 234, 24));
		}
		else
		{
			p4.setCharacterSize(30);
			p4.setFillColor(sf::Color::White);
		}

		if (p6.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window))))
		{
			p6.setCharacterSize(40);
			p6.setFillColor(sf::Color::Color(173, 234, 24));
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
	Global::dts = new sf::Texture[nop * 6];
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
	sf::Color clr;
	name.setCharacterSize(30);
	name.setPosition((float)window.getSize().x / 5, (float)window.getSize().y / 2 + 10);
	name.setFillColor(sf::Color::Yellow);
	name.setOutlineColor(sf::Color::Black);
	name.setStyle(sf::Text::Bold);
	name.setFont(Global::f3);
	box.setPosition((float)window.getSize().x / 3, (float)window.getSize().y / 2);
	box.setFillColor(sf::Color::Transparent);
	box.setOutlineThickness(-(float)5);
	box.setSize(sf::Vector2f((float)window.getSize().x / 4, 60));
	box.setOutlineColor(sf::Color::Green);
	input.setFont(Global::f1);
	input.setCharacterSize(30);
	input.setPosition((float)window.getSize().x / 3 + 10, (float)window.getSize().y / 2 + 10);
	input.setFillColor(sf::Color::Cyan);
	while (window.isOpen())
	{
		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			if (evnt.type == evnt.Closed)
				window.close();
			else if (evnt.type == sf::Event::TextEntered)
			{
				if (evnt.text.unicode >= 'a' && evnt.text.unicode <= 'z'|| evnt.text.unicode >= 'A' && evnt.text.unicode <= 'Z')
					sinput += static_cast<char>(evnt.text.unicode);
				else if (evnt.text.unicode == '\b' && !sinput.empty())
					sinput.pop_back();
				input.setString(sinput);
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			switch (Global::turnId[i])
			{
			case 'r':
				clr = sf::Color::Red;
				break;
			case 'b':
				clr = sf::Color::Blue;
				break;
			case 'g':
				clr = sf::Color::Green;
				break;
			case 'y':
				clr = sf::Color::Yellow;
				break;
			case 'c':
				clr = sf::Color::Cyan;
				break;
			case 'o':
				clr.r = 255;
				clr.g = 165;
				clr.b = 0;
				break;
			}
			ps[i] = new Player(input, i, clr);
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
void Ludo::ShowSocMsg(sf::RenderWindow& window)const
{
	sf::Text smsg;
	smsg.setFont(Global::f1);
	smsg.setFillColor(sf::Color::Blue);
	smsg.setCharacterSize(30);
	smsg.setPosition((float)(b)->GetDim().x * Global::SqrDim.x + 5,(float) 7 * Global::SqrDim.y);
	smsg.setString("Piece Selected\n Now Select \nThe Number");
	window.draw(smsg);
}
void Ludo::ShowNumMsg(sf::RenderWindow& window)const
{
	sf::Text nmsg;
	nmsg.setFont(Global::f1);
	nmsg.setFillColor(sf::Color::Blue);
	nmsg.setCharacterSize(30);
	nmsg.setPosition((float)b->GetDim().x * Global::SqrDim.x + 5,(float) 7 * Global::SqrDim.y);
	nmsg.setString("Number Selected\n Now Select \n Destination \n From Board");
	window.draw(nmsg);
}
void Ludo::SocHighlight()
{
	sf::Color slateGray(112, 128, 144);
	sf::Color goldenRod(218, 165, 32);
	b->GetShapeAt(s)->SetFillClr(slateGray);
}
void Ludo::SocUnhighlight()
{
	sf::Color lightYellow(255, 255, 204);
	sf::Color orange(255, 165, 0);
	sf::Color khaki(240, 230, 140);
	char sid = b->GetShapeAt(s)->GetId();
	switch (sid)
	{
	case'r':
	case'R':
	case')':
	case'/':
		b->GetShapeAt(s)->SetFillClr(sf::Color::Red);
		break;
	case'b':
	case'B':
	case'+':
	case'`':
		b->GetShapeAt(s)->SetFillClr(sf::Color::Blue);
		break;
	case'g':
	case'G':
	case'*':
	case'>':
		b->GetShapeAt(s)->SetFillClr(sf::Color::Green);
		break;
	case'y':
	case'Y':
	case'_':
	case'~':
		b->GetShapeAt(s)->SetFillClr(sf::Color::Yellow);
		break;
	case'o':
	case'O':
	case'&':
	case'<':
		b->GetShapeAt(s)->SetFillClr(orange);
		break;
	case'c':
	case'C':
	case'|':
	case'!':
		b->GetShapeAt(s)->SetFillClr(sf::Color::Cyan);
		break;
	case'.':
		b->GetShapeAt(s)->SetFillClr(lightYellow);
		break;
	case'?':
		b->GetShapeAt(s)->SetFillClr(khaki);
		break;
	}
}
void Ludo::init(sf::RenderWindow& window)
{
	MainMenu(window);
	d = { 2,2 };
	this->IsDesSel = false;
	this->IsSocSel = false;
	this->IsNumSel = false;
	this->turn = 0;
	this->b = new Board(window, nop);
	pause.setTexture(Global::ts[12]);
	pause.setScale((float)Global::SqrDim.x / Global::ts[12].getSize().x, (float)Global::SqrDim.y / Global::ts[12].getSize().y);
	pause.setPosition((float)(b->GetDim().x + 2) * Global::SqrDim.x, 0);
}
Ludo::Ludo(sf::RenderWindow& window)
{
	Global::SqrDim.x = (float)window.getSize().x / (24 + 3);
	Global::SqrDim.y = (float)window.getSize().y / 15;
	Global::ts = new sf::Texture[14];
	Global::f.loadFromFile("arial.ttf");
	Global::f1.loadFromFile("vinque.otf");
	Global::f2.loadFromFile("Plante.ttf");
	Global::f3.loadFromFile("High Fighter.ttf");
	
	Global::ts[0].loadFromFile("red_piece.png");
	Global::ts[1].loadFromFile("green_piece.png");
	Global::ts[2].loadFromFile("blue_piece.png");
	Global::ts[3].loadFromFile("yellow_piece.png");
	Global::ts[4].loadFromFile("cyan_piece.png");
	Global::ts[5].loadFromFile("orange_piece.png");
	Global::ts[6].loadFromFile("star.png");
	Global::ts[7].loadFromFile("background.jpg");
	Global::ts[8].loadFromFile("logo.png");
	Global::ts[9].loadFromFile("Background1.jpg");
	Global::ts[10].loadFromFile("win_1.png");
	Global::ts[11].loadFromFile("win_2.png");
	Global::ts[12].loadFromFile("pause.png");
	Global::ts[13].loadFromFile("paused.png");
	init(window);
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
				break;
			case evnt.MouseButtonPressed:
				if (pause.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window))))
					Pause(window);
				else
					SelectPosition(window);
			}
		}
		window.clear();
		b->DrawBoard(window);
		b->DrawPieces(window);
		ps[turn]->GetDice().DrawMainDice(window);
		ps[turn]->GetDice().DisplayNumbers(window, score);
		ps[turn]->DisplayName(window);
		if (IsSocSel && !IsNumSel)
		{
			ShowSocMsg(window);
			SocHighlight();
		}
		if (IsNumSel && !IsDesSel)
			ShowNumMsg(window);
		window.draw(pause);
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
	return s.ri == 3 && i != score.size() && i >= 0;
}

bool Ludo::CanMove()const
{
	sf::Vector3f v;
	char tid = Global::turnId[turn];
	for (int i = 0;i < b->GetDim().y;i++)
	{
		v.y = i;
		for (int j = 0;j < b->GetDim().x;j++)
		{
			v.x = j;
			for (int k = 0;k < b->GetPiecesAt({i,j}).size();k++)
			{
				v.z = k;
				if (b->GetPieceAt(v).GetId() == tid && b->IsOnBoard({ i,j }))
				{
					for (int si = 0;si < score.size();si++)
					{
						if (b->IsPathClear(v, score[si]) && b->CanPieceWin(v, score[si]))
							return true;
					}
				}
			}
		}
	}
	for (int i = 0;i < score.size();i++)
	{
		if (score[i] == 6 && b->GetPieceCountAtHome(tid) != 0)
			return true;
	}
	return false;
}
bool Ludo::CanMoveAuto()const
{
	int count = 0;
	sf::Vector3f v;
	char tid = Global::turnId[turn];
	for (int i = 0;i < b->GetDim().y;i++)
	{
		v.y = i;
		for (int j = 0;j < b->GetDim().x;j++)
		{
			v.x = j;
			if (!b->IsEmptySpace({ i,j }))
			{
				for (int k = 0; k < b->GetPiecesAt({ i,j }).size();k++)
				{
					v.z = k;
					if (tid == b->GetPieceAt(v).GetId() && !b->GetPieceAt(v).IsAtHome({ i,j }))
					{
						count++;
						if (count == 2)
							return false;
					}


				}
			}
		}
	}
	for (int i = 0;i < score.size();i++)
	{
		if (score[i] == 6)
			return false;
	}
	if (score.size() != 1)
		return false;
	return true;
}
void Ludo::FindSocAuto()
{
	sf::Vector3f v;
	char tid = Global::turnId[turn];
	for (int i = 0;i < b->GetDim().y;i++)
	{
		v.y = i;
		for (int j = 0;j < b->GetDim().x;j++)
		{
			v.x = j;
			if (!b->IsEmptySpace({ i,j }))
			{
				for (int k = 0; k < b->GetPiecesAt({ i,j }).size();k++)
				{
					v.z = k;
					if (tid == b->GetPieceAt(v).GetId() && !b->GetPieceAt(v).IsAtHome({ i,j }))
					{
						s = { i,j };
						rs = v;
						return;
					}
				}
			}
		}
	}
}
void Ludo::MoveAuto(sf::RenderWindow & window)
{
	Position soc = s;
	FindSocAuto();
	char pid = b->GetPieceAt(rs).GetId();
	if (b->CanPieceWin(rs, score[0]) && b->IsPathClear(rs, score[0]))
	{
		IsSocSel = false;
		IsDesSel = false;
		IsNumSel = false;
		b->UpdateBoard(window, *ps[turn], score, rs, score[0]);
		score.erase(score.begin() + 0);
		if (IsWin())
			WinningScreen(window);
		ps[turn]->SetHasRolled(false);
		TurnCh();
	}
	else if(score[0]!= 6 || b->GetPieceCountAtHome(pid) == 0)
	{
		s = soc;
		score.clear();
		ps[turn]->SetHasRolled(false);
		if (IsWin())
			WinningScreen(window);
		TurnCh();
	}
}
void Ludo::SelectPosition(sf::RenderWindow& window)
{
	static int i, count6;
	bool Update = true;
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
	if (!ps[turn]->GetHasRolled() && ps[turn]->GetDice().IsDiceThrown(p))
	{
		//int s = 6;
		int s = ps[turn]->RollDice();
		ps[turn]->GetDice().DisplayRoll(window, *b, s);
		score.push_back(s);
		if (s != 6)
		{
			ps[turn]->SetHasRolled(true);
			count6 = 0;
		}
		else
			count6++;
		if (count6 == 3)
		{
			count6 = 0;
			ps[turn]->SetHasRolled(false);
			score.clear();
			TurnCh();
		}
	}
	else if (ps[turn]->GetHasRolled() && !IsSocSel && InBound())
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
	else if (!IsDesSel && IsSocSel && IsNumSel && InBound() && IsValidDestin() && score[i] == 6)
	{
		des = p;
		IsDesSel = true;
		IsNumSel = false;
	}
	else
	{
		s = soc;
		IsNumSel = false;
		IsDesSel = false;
		IsSocSel = false;
		SocUnhighlight();
	}
	s = soc;
	rs = rsoc;
	d = des;
	if (IsSocSel && IsDesSel)
	{
		IsSocSel = false;
		IsDesSel = false;
		IsNumSel = false;
		SocUnhighlight();
		count6 = 0;
		if (b->GetPieceAt(rs).GetIsFirst())
			b->UpdateBoard(window, rs, d);
		else if (b->CanPieceWin(rs, score[i]) && b->IsPathClear(rs, score[i]))
			b->UpdateBoard(window, *ps[turn], score , rs, score[i]);
		else
			Update = false;
		if(Update)
			score.erase(score.begin() + i);
		if (IsWin())
			WinningScreen(window);
		if (score.size() == 0 && ps[turn]->GetHasRolled())
		{
			ps[turn]->SetHasRolled(false);
			TurnCh();
		}
	}
	if (ps[turn]->GetHasRolled() && !IsSocSel && !CanMove())
	{
		window.clear();
		b->DrawBoard(window);
		b->DrawPieces(window);
		ps[turn]->GetDice().DisplayNumbers(window, score);
		ps[turn]->GetDice().DrawMainDice(window);
		window.display();
		sf::sleep(sf::seconds(0.5));
		score.clear();
		ps[turn]->SetHasRolled(false);
		if (IsWin())
			WinningScreen(window);
		TurnCh();
	}
	if (ps[turn]->GetHasRolled() && !IsSocSel && CanMoveAuto())
	{
		window.clear();
		b->DrawBoard(window);
		b->DrawPieces(window);
		ps[turn]->GetDice().DisplayNumbers(window, score);
		ps[turn]->GetDice().DrawMainDice(window);
		window.display();
		sf::sleep(sf::seconds(0.5));
		MoveAuto(window);
		count6 = 0;
	}
}
