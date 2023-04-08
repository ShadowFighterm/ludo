#include "RedPiece.h"
#include"Global.h"
RedPiece::RedPiece(Position p, int dir, char id)
	:Piece(p, dir, id)
{
	this->pc.setTexture(Global::ts[0]);
	this->pc.setScale(Scale);
	this->pc.setPosition(pos);
	this->Round = { 7,0 };
}