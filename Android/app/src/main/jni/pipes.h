#pragma once
#include "App.h"
#include "Defines.h"

///klasa pipes zawiera wszystkie zdarzenia dotyczace rur-przeszkod
class pipes
{
public:
	///obiekt s_up klasy Sprite
	Sprite s_up; 
	///obiekt s_down klasy Sprite
	Sprite s_down; 
	///obiekt up klasy Texture
	Texture up;  
	///obiekt up klasy Texture
	Texture down; 
	///zmienna x typu int 
	int x = 600; 
	///zmienna y typu int
	int y = rand() % PIPES_RENDER_RND; 
	/// zmienna statyczna typu static unsigned 
	static unsigned new_x; 
	///konstruktor klasy pipes, laduje i ustawia tekstury rur
	pipes(); 
	///metoda movement klasy pipes odpowiadajaca za ruch rur
	void movement(); 
	///metoda reset klasy pipes resetujaca wspolrzedne rur
	void reset(); 
	///metoda draw klasy pipes rysujaca rury
	void draw(RenderWindow& window); 
	
};

