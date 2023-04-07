#pragma once
#include<SFML/Graphics.hpp>
#include"Position.h";
#include"Piece.h"
class BluePiece:public Piece
{
public:
	BluePiece(Position pos, int dir, char id);
};

