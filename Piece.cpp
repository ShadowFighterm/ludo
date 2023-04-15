#include "Piece.h"
#include"Shape.h"
#include"Global.h"
Piece::Piece(Position p, int dir, char id)
{
	SetIsFirst(true);
	SetPosition(p);
	SetDir(dir);
	SetId(id);
	this->home = p;
	this->Scale.x = 0.02;
	this->Scale.y = 0.02;
	this->pos.x = (float)p.ci * Global::SqrDim.x + (Global::SqrDim.x / 8);
	this->pos.y = (float)p.ri * Global::SqrDim.y + (Global::SqrDim.y / 16);
}
void Piece::DrawPiece(sf::RenderWindow& window)const
{
	window.draw(pc);
}
void Piece::Move(sf::RenderWindow& window, Position p)
{
	this->p = p;
	this->pos.x = (float)p.ci * Global::SqrDim.x + (Global::SqrDim.x / 8);
	this->pos.y = (float)p.ri * Global::SqrDim.y + (Global::SqrDim.y / 16);
	this->pc.setPosition(this->pos);
	this->IsFirstMove = false;
}
bool Piece::IsRoundCompleted(Position p)const
{
	return Round.ri == p.ri && Round.ci == p.ci;
}
bool Piece::IsAtHome(Position p)const
{
	return p.ri == home.ri && p.ci == home.ci;
}
bool Piece::IsPieceWin(Position p)const
{
	return p.ri == win.ri && p.ci == win.ci;
}
void Piece::SetPiece(int n)
{
	pos.x = (float)p.ci * Global::SqrDim.x + (Global::SqrDim.x / 8);
	pos.x += n * 5;
	this->pc.setPosition(pos);
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
Position Piece::GetRound()const
{
	return this->Round;
}
Position Piece::GetHome()const
{
	return this->home;
}