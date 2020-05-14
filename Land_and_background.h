#pragma once
#include"App.h"
///klasa Land_and_background zawiera wszystkie zdarzenia dotyczace ladu i tla 
class Land_and_background
{
public:
	///referencja obiektu klasy RenderWindow
	RenderWindow& window;
	///obiekt sLand klasy Sprite
	Sprite sLand;
	///obiekt sBackground klasy Sprite
	Sprite sBackground;
	///obiekt Land klasy Texture
	Texture Land;
	///obiekt Backgroud klasy Texture
	Texture Backround;
	///obiekt s2Land klasy Sprite
	Sprite s2Land;
	///obiekt pos klasy Vector2f pobiera pozycje ladu
	Vector2f pos = sLand.getPosition();
	///obiekt pos klasy Vector2f pobiera pozycje ladu2
	Vector2f pos_2 = s2Land.getPosition();
	///kostruktor klasy Land_and_background, laduje i ustawia pozycje tekstur
	Land_and_background(RenderWindow&);
	///metoda draw_background klasy Land_and_background, rysuje tlo
	void draw_background();
	///metoda draw_lands klasy Land_and_background, rysuje lady
	void draw_lands();
	///metoda moving_lands Land_and_background, odpowiada za ruch ladu
	void moving_lands();
};

	


