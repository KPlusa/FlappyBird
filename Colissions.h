#pragma once
#include "Bird.h"
#include "pipes.h"
#include "Land_and_background.h"

///klasa Colissions zawiera wszystkie zdarzenia dotyczace kolizji i aktualizacji zdarze
class Colissions
{
public:
	///zmienna score__ tyou int
	int score__;
	///zmuienna score_ typu int 
	int score_;
	///referencja obiektu bird klasy Bird
	Bird& bird;
	///referecja obiektow first, second, third klasy pipes
	pipes& first, & second, & third;
	///referencja  obiektu success klasy Sound
	Sound& success;
	///referencja obiektu land klasy Land_and_background
	Land_and_background& land;
	///referencja obiektu window klasy RenderWindow
	RenderWindow& window;
	///referencja obiektu best_score klasy Text
	Text& best_score;


	///konstruktor klasy Colissions
	Colissions(Bird& a, pipes& b, pipes& c, pipes& d, Sound& e, Land_and_background& f, RenderWindow& g, Text& h) :bird(a), first(b), second(c), third(d), success(e), land(f), window(g), best_score(h) {}
	///zmienna current_obstacle_x typu int
	int current_obstacle_x;
	///zmienna current_obstacle_y typu int
	int current_obstacle_y;

	///metoda klasy Colissions, odpowiada za kolizje ptaka z przeszkodami
	void col()
	{

		if (bird.counter % 3 == 0) { current_obstacle_x = first.x; current_obstacle_y = first.y; }
		if (bird.counter % 3 == 1) { current_obstacle_x = second.x; current_obstacle_y = second.y; }
		if (bird.counter % 3 == 2) { current_obstacle_x = third.x; current_obstacle_y = third.y; }



		if (bird.BirdPos.x + BIRD_WIDTH / 2 >= current_obstacle_x && ((bird.BirdPos.y - BIRD_HEIGH / 2 <= current_obstacle_y) || (bird.BirdPos.y + BIRD_HEIGH / 2 >= current_obstacle_y + 190))) {

			bird.alive = 0;

		}
		else if (bird.BirdPos.y > WINDOW_HEIGH + 100 || bird.BirdPos.y < land.sLand.getGlobalBounds().height)
			bird.alive = 0;
		

	}
	///metoda klasy Colissions, odpowiada za aktualizacje zdarzen
	void update()
	{
		for (auto i : { &first,&second,&third })
		{
			if (i->x < -136) //szerokosc rury
			{
				i->x = WINDOW_WIDTH; i->y = rand() % PIPES_RENDER_RND;


			}
			if (i->x == -BIRD_WIDTH && bird.alive == 1) // wspolrzedne rury kiedy dodaje punkt
			{

				bird.counter++;
				success.play();


			}
		}
		score__ = bird.counter;

	}
	///metoda klasy Colissions, odpowiada za zapisywanie i odczytywanie z pliku najlepszego wyniku
	void best_score_()
	{
		ifstream best_score_file_r;
		ofstream best_score_file;
		best_score_file_r.open("best_score.txt");
		if (best_score_file_r.is_open())
		{
			best_score_file_r >> score_;
			best_score_file_r.close();
		}
		best_score_file.open("best_score.txt");

		if (best_score_file.is_open())
		{
			if (score_ <= score__ && bird.alive == 0)
			{
				best_score_file << score__;
				window.draw(best_score);
				best_score_file.close();
			}
			else {
				best_score_file << score_;
				best_score_file.close();
			}
		}

	}





};

