#include "pipes.h"
unsigned pipes::new_x = 600;

pipes::pipes()
{
	up.loadFromFile("Textures/up.png");
	down.loadFromFile("Textures/down.png");
	s_down.setTexture(down);
	s_up.setTexture(up);

	
}
void pipes::movement()
{
	x -= PIPES_MOVEMENT;
}

void pipes::reset()
{
	x = new_x; y = rand() % PIPES_RENDER_RND; new_x += 400; if (x == 1400)new_x = 600;
}

void pipes::draw(sf::RenderWindow& window)
{
	s_up.setOrigin(0, y);
	s_up.setPosition(x, 0); 
	s_down.setPosition(x, WINDOW_HEIGH - y);
	window.draw(s_up);
	window.draw(s_down);
}