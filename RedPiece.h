#pragma once
#include<SFML/Graphics.hpp>
#include"Piece.h"
#include"Position.h"
class RedPiece:public Piece
{
public:
	RedPiece(Position pos, int dir, char id);
};

