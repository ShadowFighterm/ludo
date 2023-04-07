#pragma once
#include<SFML/Graphics.hpp>
#include"Position.h"
#include"Piece.h"
class GreenPiece:public Piece
{
public:
	GreenPiece(Position pos, int dir, char id);
};

