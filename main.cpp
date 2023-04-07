#include<iostream>
#include<SFML/Graphics.hpp>
#include<fstream>
#include"Global.h"
#include"Ludo.h"
using namespace std;
int main()
{
	sf::RenderWindow window(sf::VideoMode(1200, 800), "Ludo", sf::Style::Close | sf::Style::Titlebar);
	Ludo l(window);
	l.Play(window);
}