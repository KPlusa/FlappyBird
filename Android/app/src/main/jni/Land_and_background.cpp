#include "Land_and_background.h"
Land_and_background::Land_and_background(RenderWindow& a) :window(a)
{
	Backround.loadFromFile("Textures/background.png");
	sBackground.setTexture(Backround);
	sBackground.setPosition(0, 0);
	Land.loadFromFile("Textures/ground.png");
	sLand.setTexture(Land);
	s2Land.setTexture(Land);
	sLand.setPosition(0, window.getSize().y - sLand.getGlobalBounds().height);
	s2Land.setPosition(WINDOW_WIDTH, window.getSize().y - sLand.getGlobalBounds().height);
}

void Land_and_background::draw_background()
{
	window.draw(sBackground);
}

void Land_and_background::draw_lands()
{
	window.draw(sLand);
	window.draw(s2Land);
}

