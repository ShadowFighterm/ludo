#include "BluePiece.h"
BluePiece::BluePiece(Position p, int dir, char id)
	:Piece(p, dir, id)
{
	this->tpc.loadFromFile("blue_piece.png");
	this->pc.setTexture(tpc);
	this->pc.setScale(Scale);
	this->pc.setPosition(pos);
}
