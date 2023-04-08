#pragma once
#include<SFML/Graphics.hpp>
#include"Position.h"
class Shape;
class Piece;
class Board
{
private:
	sf::Vector2f dim;
	sf::Sprite bg;
	sf::Sprite star;
	sf::Text ludo;
	Shape*** shp;
	Piece*** pcs;
	void DrawBG(sf::RenderWindow& window)const;
	void DrawStar(sf::RenderWindow& window, Position p);
public:
	Board(sf::RenderWindow& window, int nop);
	void DrawBoard(sf::RenderWindow& window);
	void DrawPieces(sf::RenderWindow& window)const;
	void UpdateBoard(sf::RenderWindow& window, Position s, Position d);
	void UpdateBoard(sf::RenderWindow& window, Position s, int n);
	bool IsEmptySpace(Position p)const;
	Piece* GetPieceAt(Position p)const;
	Shape* GetShapeAt(Position p)const;
	const sf::Vector2f& GetDim()const;
};

