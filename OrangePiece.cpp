#include "OrangePiece.h"
OrangePiece::OrangePiece(Position p, int dir, char id)
	:Piece(p, dir, id)
{
	this->tpc.loadFromFile("orange_piece.png");
	this->pc.setTexture(tpc);
	this->pc.setScale(Scale);
	this->pc.setPosition(pos);
}
