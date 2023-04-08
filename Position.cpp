#include "Position.h"
Position::Position()
{
	this->ri = 0;
	this->ci = 0;
}
Position::Position(const Position& p)
{
	ri = p.ri;
	ci = p.ci;
}
Position::Position(int r, int c)
{
	ri = r;
	ci = c;
}