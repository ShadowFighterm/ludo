#include "CyanPiece.h"
CyanPiece::CyanPiece(Position p, int dir, char id)
	:Piece(p, dir, id)
{
	this->pc.setTexture(Global::ts[4]);
	this->pc.setScale(Scale);
	this->pc.setPosition(pos);
	this->Round = { 0,7 };
	this->win = { 6,7 };
}