#include "BluePiece.h"
BluePiece::BluePiece(Position p, int dir, char id)
	:Piece(p, dir, id)
{
	this->pc.setTexture(Global::ts[2]);
	this->pc.setScale(Scale);
	this->pc.setPosition(pos);
	this->Round = { 0, 16 };
	this->win = { 6,16 };
}
