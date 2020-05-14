#include "Defines.h"
#include "Bird.h"
#include "pipes.h"
#include "Colissions.h"
#include "Land_and_background.h"
#include "App.h"




App::App() : world(b2Vec2(0.f, -9.8f)) 
{

	srand(time(0)); 
	
	window.create(VideoMode(WINDOW_WIDTH, WINDOW_HEIGH), ""); ///tworzy okno o wymiarach podanych w defines.h
	window.setFramerateLimit(360); ///ustawia limit FPS
	window.setKeyRepeatEnabled(false); ///wylacza mozliwosc powtarzania klawisza w przypadku przytrzymania 

	///laduje, ustawia dzwieki i teksty
	success_buffer.loadFromFile("Sounds/success.wav"); 
	success.setBuffer(success_buffer);

	fail_buffer.loadFromFile("Sounds/fail.wav"); 

	fail.setBuffer(fail_buffer);

	font.loadFromFile("fonts/font.ttf");

	//----------------------------------
	score.setFont(font);
	score.setPosition(WINDOW_WIDTH / 2, 150); 
	score.setOutlineThickness(4);
	score.setCharacterSize(80); 

	//---------------------------------
	gameover.setFont(font); 
	gameover.setOutlineColor(Color(255, 255, 255));
	gameover.setOutlineThickness(2);
	gameover.setFillColor(Color(0, 0, 0));
	gameover.setCharacterSize(80);
	gameover.setString("Game Over!");
	gameoverRect = gameover.getLocalBounds();
	gameover.setOrigin(gameoverRect.left + gameoverRect.width / 2.0f, 0);
	gameover.setPosition(Vector2f(WINDOW_WIDTH / 2.0f, 200));
	//-----------------------------------
	start.setFont(font);
	start.setOutlineThickness(3);
	start.setCharacterSize(80);
	start.setString("Left Click to play");
	startRect = start.getLocalBounds();
	start.setOrigin(startRect.left + startRect.width / 2.0f, startRect.top + startRect.height / 2.0f);
	start.setPosition(Vector2f(WINDOW_WIDTH / 2.0f, WINDOW_HEIGH / 2.0f));
	//-----------------------------------
	best_score.setFont(font);
	best_score.setPosition(200, 300);
	best_score.setOutlineThickness(2);
	best_score.setFillColor(Color(255, 255, 0));
	best_score.setCharacterSize(80);
	best_score.setString("Best Score!");
	///tworzy obiekty klas
	Land_and_background land_and_background(window);
	Bird bird(window, world);
	pipes first, second, third;
	second.x = first.x + 400;
	third.x = first.x + 800;
	Colissions objects(bird, first, second, third, success, land_and_background, window, best_score);


	///petla -okno jest otwarte
	while (window.isOpen())
	{
		objects.col();
		objects.update();

		while (init == 1)///petla jednorazowa
		{
			bird.animation();
			land_and_background.moving_lands();
			land_and_background.draw_background();
			land_and_background.draw_lands();
			bird.draw();
			window.draw(start);
			window.display();
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				init = 0;
				break;
			}


		}
		///petla od zdarzen wywolywanych przez uzytkownika
		while (window.pollEvent(event))
		{

			bird.default_rotation();
			if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape))
				window.close();




			if (event.type == Event::MouseButtonPressed)
			{
				if ((event.mouseButton.button == Mouse::Left) && bird.alive == 1)
				{
					bird.leftClick();

				}
				else if ((event.mouseButton.button == Mouse::Left) && bird.alive == 0)
				{

					for (auto i : { &first,&second,&third }) i->reset();
					bird.reset();
				}


			}


		}
		window.clear();///czysci ekran




		land_and_background.draw_background();
		for (auto i : { &first,&second,&third }) i->draw(window);
		land_and_background.draw_lands();


		bird.draw();
		score.setString(to_string(bird.counter));
		window.draw(score);


		world.Step(timeStep, velIt, posIt);///symulacja stworzonego smiata




		/** jesli ptak zyje to wywoluje animacje i ruch ptaka, ruch ladu i rur
		*	jesli nie wypisuje na ekran tekst ustawiony w gameover i odtwarza dzwiek konca gry
		**/
		if (bird.alive) 
		{
			bird.animation(); 
			bird.movement(); 
			for (auto i : { &first,&second,&third }) i->movement(); 
			land_and_background.moving_lands(); 
		}
		else 
		{

			window.draw(gameover);
			if (song == 1) {
				fail.play();
				song = 0;
			}
			bird.draw();


		}


		objects.best_score_();
		window.display();///wyswietla aplikacje

	}
}







