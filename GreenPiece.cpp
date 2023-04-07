#include "GreenPiece.h"
GreenPiece::GreenPiece(Position p, int dir, char id)
	:Piece(p, dir, id) 
{
	this->tpc.loadFromFile("green_piece.png");
	this->pc.setTexture(tpc);
	this->pc.setScale(Scale);
	this->pc.setPosition(pos);
}