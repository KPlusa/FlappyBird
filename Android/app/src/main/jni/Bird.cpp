#include "Bird.h"
#include "Defines.h"

Bird::Bird(RenderWindow& a, b2World&world) : window(a)
{
	tap.loadFromFile("Sounds/tap.wav");
	tap_sound.setBuffer(tap);
	BirdDef.type = b2_dynamicBody;
	BirdShape.SetAsBox(34, 24);
	sBird.setOrigin(34, 24);
	BirdDef.position.Set(x, y);
	BirdFixture.density = 0;
	BirdFixture.shape = &BirdShape;
	BirdFixture.friction = 0;
	BirdFixture.restitution = 0;
	BirdBody = world.CreateBody(&BirdDef);
	BirdBody->CreateFixture(&BirdFixture);
	sBird.setPosition(x, y);
	tbird.loadFromFile("Textures/bird.png");

}


void Bird::leftClick()
{
	if (alive == 1) tap_sound.play();
	b2Vec2 vel = BirdBody->GetLinearVelocity();
	vel.y = VEL_OF_TAP;
	BirdBody->SetLinearVelocity(vel);
	sBird.setRotation(-30);
	
}

void Bird::reset()
{
	BirdBody->SetTransform(b2Vec2(x, WINDOW_HEIGH / 2), BirdBody->GetAngle());
	y = WINDOW_HEIGH/2;
	alive = 1;
	counter = 0;
}
void Bird::draw()
{
	
	sBird.setPosition(x, y);
	window.draw(sBird);
}
void Bird::default_rotation()
{
	sBird.setRotation(0);
}

void Bird::animation()
{
	
	if (clock.getElapsedTime().asSeconds() > BIRD_DURATION)
	{
		if (Bird_source_rect.left == 136)
			Bird_source_rect.left = 0;
		else
			Bird_source_rect.left += 68;
		sBird.setTextureRect(Bird_source_rect);
		sBird.setPosition(100, WINDOW_HEIGH / 2);
		clock.restart();
	}
}

void Bird::movement()
{
	BirdPos = BirdBody->GetPosition();
	y = WINDOW_HEIGH - BirdPos.y;


	
}
