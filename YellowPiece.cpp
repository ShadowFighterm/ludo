#include "YellowPiece.h"
YellowPiece::YellowPiece(Position p, int dir, char id)
	:Piece(p, dir, id)
{
	this->tpc.loadFromFile("yellow_piece.png");
	this->pc.setTexture(tpc);
	this->pc.setScale(Scale);
	this->pc.setPosition(pos);
}
