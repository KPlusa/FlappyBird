#pragma once
#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <fstream>
#include "Defines.h"

///przestrzen nazw sf
using namespace sf; 
///przestrzen nazw std
using namespace std; 
///klasa App
class App 
{
public:
	/// obiekt klasy b2World
	b2World world; 
	///obiekt klasy RenderWindow
	RenderWindow window; 
	///obiekt klasy Event
	Event event; 
	///obiekt klasy SoundBuffer
	SoundBuffer success_buffer;  
	///obiekt klasy SoundBuffer
	SoundBuffer fail_buffer; 
	///obiekt klasy Sound
	Sound success; 
	///obiekt klasy Sound
	Sound fail; 
	///zmienna timeStep, do symulacji swiata
	float timeStep = 1/ 10.0f; 
	///zmienna velIt, do symulacji swiata
	int velIt = 8; 
	///zmienna posIt, do symulacji swiata
	int posIt = 3; 
	///obiekt font klasy Font
	Font font; 
	///obiekt gameoverklasy Text
	Text gameover; 
	///obiekt score klasy Text
	Text score; 
	///obiekt start klasy Text
	Text start; 
	///obiekt best_score klasy Text
	Text best_score;
	///obiekt startRect klasy FloatRect
	FloatRect startRect;
	///obiekt scoreRect klasy FloatRect
	FloatRect scoreRect; 
	///obiekt gameoverRect klasy FloatRect
	FloatRect gameoverRect;
	///zmienna a typu int 
	int a; 
	///zmienna score_ typu int
	int score_; 
	///zmienna counter typu int
	int counter = 0; 
	///zmienna current_obstacle_x typu int 
	int current_obstacle_x; 
	///zmienna current_obstacle_y typu int 
	int current_obstacle_y;
	///zmienna song typu bool
	bool song = 1; 
	///zmienna song typu bool
	bool init = 1; 
	///zmienna aktywnosci aplikacji
	bool active = 1; 
	public:
		///domyslny konstruktor 
		App(); 
		/***
*Konstruktor klasy App
*wykonujacy program,
* dodanie grawitacji 9.8 m/s^2
**/
		App(const App&) : world(b2Vec2(0.f,-9.8f)) {};

};

