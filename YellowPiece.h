#pragma once
#include<SFML/Graphics.hpp>
#include"Position.h"
#include"Piece.h"
class YellowPiece:public Piece
{
public:
	YellowPiece(Position pos, int dir, char id);
};

