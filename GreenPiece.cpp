#include "GreenPiece.h"
GreenPiece::GreenPiece(Position p, int dir, char id)
	:Piece(p, dir, id) 
{
	this->pc.setTexture(Global::ts[1]);
	this->pc.setScale(Scale);
	this->pc.setPosition(pos);
	this->Round = { 14,17 };
}