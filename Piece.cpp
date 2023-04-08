#include "Piece.h"
#include"Shape.h"
#include"Global.h"
Piece::Piece(Position p, int dir, char id)
{
	SetIsFirst(true);
	SetPosition(p);
	SetDir(dir);
	SetId(id);
	this->Scale.x = 0.1;
	this->Scale.y = 0.1;
	this->pos.x = (float)p.ci * Global::SqrDim.x + (Global::SqrDim.x / 4);
	this->pos.y = (float)p.ri * Global::SqrDim.y + (Global::SqrDim.y / 8);
}
void Piece::DrawPiece(sf::RenderWindow& window)const
{
	window.draw(pc);
}
void Piece::Move(sf::RenderWindow& window, Position p)
{
	this->p = p;
	this->pos.x = (float)p.ci * Global::SqrDim.x + (Global::SqrDim.x / 4);
	this->pos.y = (float)p.ri * Global::SqrDim.y;
	this->pc.setPosition(this->pos);
}
void Piece::SetPosition(Position p)
{
	this->p = p;
}
void Piece::SetDir(int dir)
{
	this->dir = dir;
}
void Piece::SetIsFirst(bool b)
{
	this->IsFirstMove = b;
}
void Piece::SetId(char id)
{
	this->id = id;
}
bool Piece::GetIsFirst()const
{
	return this->IsFirstMove;
}
char Piece::GetId()const
{
	return this->id;
}
Position Piece::GetPosition()const
{
	return this->p;
}
int Piece::GetDir()const
{
	return this->dir;
}