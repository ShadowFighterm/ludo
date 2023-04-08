#include<iostream>
#include<SFML/Graphics.hpp>
#include<fstream>
#include"Global.h"
#include"Ludo.h"
using namespace std;
int main()
{
	sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "LUDO");
	Ludo l(window);
	l.Play(window);
}