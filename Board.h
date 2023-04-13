#pragma once
#include<SFML/Graphics.hpp>
#include"Position.h"
#include<vector>
using namespace std;
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
	vector<vector<vector<Piece>>> pcs;
	void DrawBG(sf::RenderWindow& window)const;
	void DrawStar(sf::RenderWindow& window, Position p);
	bool IsValidPath(Position p)const;
	void SetPieces();
public:
	Board(sf::RenderWindow& window, int nop);
	int GetPieceCount(char id)const;
	void DrawBoard(sf::RenderWindow& window)const;
	void DrawPieces(sf::RenderWindow& window)const;
	void UpdateBoard(sf::RenderWindow& window, sf::Vector3f s, Position d);
	void UpdateBoard(sf::RenderWindow& window, sf::Vector3f s, int n);
	bool IsEmptySpace(Position p)const;
	vector<Piece> GetPiecesAt(Position p);
	Piece GetPieceAt(sf::Vector3f p)const;
	Shape* GetShapeAt(Position p)const;
	const sf::Vector2f& GetDim()const;
};

