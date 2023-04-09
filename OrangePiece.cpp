#include "OrangePiece.h"
OrangePiece::OrangePiece(Position p, int dir, char id)
	:Piece(p, dir, id)
{
	this->pc.setTexture(Global::ts[5]);
	this->pc.setScale(Scale);
	this->pc.setPosition(pos);
	this->Round = { 7,23 };
}
