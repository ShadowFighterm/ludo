#include "RedPiece.h"
#include"Global.h"
RedPiece::RedPiece(Position p, int dir, char id)
	:Piece(p, dir, id)
{
	this->tpc.loadFromFile("red_piece.png");
	this->pc.setTexture(tpc);
	this->pc.setScale(Scale);
	this->pc.setPosition(pos);
}