#include "CyanPiece.h"
CyanPiece::CyanPiece(Position p, int dir, char id)
	:Piece(p, dir, id)
{
	this->tpc.loadFromFile("cyan_piece.png");
	this->pc.setTexture(tpc);
	this->pc.setScale(Scale);
	this->pc.setPosition(pos);
}