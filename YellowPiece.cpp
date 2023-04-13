#include "YellowPiece.h"
YellowPiece::YellowPiece(Position p, int dir, char id)
	:Piece(p, dir, id)
{
	this->pc.setTexture(Global::ts[3]);
	this->pc.setScale(Scale);
	this->pc.setPosition(pos);
	this->Round = { 14,7 };
	this->win = { 8,7 };
}
