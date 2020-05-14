#pragma once
#include "App.h"
#include "Defines.h"

///klasa Bird zawiera wszystkie zdarzenia dotyczace ptaka
class Bird
{
public:
	///referencja obiektu window klasy RenderWindow
	RenderWindow& window; 
	///obiekt tap klasy SoundBuffer
	SoundBuffer tap; 
	///obiekt tap_sound klasy Sound
	Sound tap_sound;
	
	///obiekt tbird klasy Texture
	Texture tbird; 
	///zmienna alive typu bool
    bool alive=1; 
	/// zmienna counter typu int
	int counter = 0; 
	///obiekt Bird_source_rect klasy IntRect
	IntRect Bird_source_rect = { 0, 0, 68, 48 }; 
	///obiekt sBird klasy Sprite
	Sprite sBird = {tbird, Bird_source_rect}; 
	///wskaznik na obiekt klasy b2Body
	b2Body* BirdBody; 
	///obiekt klasy b2BodyDef
	b2BodyDef BirdDef;
	///obiekt klasy b2Vec2
	b2Vec2 BirdPos;
	///obiekt klasy b2FixtureDef
	b2FixtureDef BirdFixture; 
	///obiekt klasy b2PolygonShape
	b2PolygonShape BirdShape;
	///zmienna x typu int
	int x = 100; 
	///zmienna y typu int
	int y = WINDOW_HEIGH / 2; 
	///obiekt clock klasy Clock
	Clock clock; 
	
	///konstruktor klasy Bird, laduje i ustawia dzwiek, i tekstury, tworzy cialo ptaka i ustawia srodek ciezkosci ciala ptaka
	Bird(RenderWindow&, b2World&); 
	///metoda movement klasy Bird odpowiedzialna za ruch ptaka
	void movement(); 
	///metoda reset klasy Bird resetujaca wspolrzedne ptaka
	void reset(); 
	///metoda leftClick klasy Bird odpowiadajaca za wzoszenie sie lotu ptaka oraz odtwarzajaca dzwiek
	void leftClick();
	///metoda draw klasy Bird rysujaca rury
	void draw(); 
	///metoda draw klasy Bird, odpowiadajaca za domyslna rotacje ciala ptaka
	void default_rotation(); 
	///metoda draw klasy Bird, odpowiadajaca za animacje ptaka 
	void animation(); 
	
};

