#pragma once
#include"Position.h"
#include"Global.h"
#include<SFML/Graphics.hpp>
class Piece
{
protected:
	char id;
	bool IsFirstMove;
	sf::Sprite pc;
	sf::Vector2f Scale;
	sf::Vector2f pos;
	Position Round;
	Position p;
	int dir;
public:
	Piece(Position pos, int dir, char id);
	bool IsRoundCompleted(Position p)const;
	void DrawPiece(sf::RenderWindow& window)const;
	void Move(sf::RenderWindow& window, Position p);
	void SetId(char id);
	void SetPosition(Position p);
	void SetDir(int dir);
	void SetIsFirst(bool b);
	bool GetIsFirst()const;
	char GetId()const;
	Position GetPosition()const;
	int GetDir()const;
	Position GetRound()const;
};

