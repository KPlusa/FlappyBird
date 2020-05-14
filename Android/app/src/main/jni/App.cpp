#include "App.h"
#include "Colissions.h"
#include "Land_and_background.h"
#include "Bird.h"
#include "pipes.h"




App::App() : world(b2Vec2(0.f, -9.8f))
{
    ///ustawia punkt startowy, ktory jest stosowany do generowania serii pseudo losowych liczb calkowitych
    srand(time(0));
    ///tworzy okienko o wymiarach zdefiniowanych w pliku defines.h
    window.create(VideoMode(WINDOW_WIDTH, WINDOW_HEIGH), "");
    window.setFramerateLimit(360);///ustawia limit FPS
    window.setKeyRepeatEnabled(false);///wylacza mozliwosc powtarzania klawisza w przypadku przytrzymania 
    success_buffer.loadFromFile("Sounds/success.wav"); ///laduje dzwiek z pliku success.wav
    success.setBuffer(success_buffer);///ustawia bufor dzwieku zaladowanego z pliku do Obiektu klasy Sound (success)
    //---------------------------------
    fail_buffer.loadFromFile("Sounds/fail.wav"); ///laduje dzwiek z pliku fail.wav
    fail.setBuffer(fail_buffer);///ustawia bufor dzwieku zaladowanego z pliku do Obiektu klasy Sound (fail)
    font.loadFromFile("fonts/font.ttf");///laduje czcionke z pliku font.tft

    //---------------------------------
    score.setFont(font);///ustawia czcionke do obiektu klasy Text (score)
    score.setPosition(WINDOW_WIDTH / 2, 150); ///ustawia pozycje tekstu
    score.setOutlineThickness(4); ///ustawia grubosc konturu
    score.setCharacterSize(80); ///ustawia wielkosc czcionki

    //---------------------------------
    gameover.setFont(font); ///ustawia czcionke do obiektu klasy Text (gameover)
    gameover.setOutlineColor(Color(255, 255, 255)); ///ustawia kolor konturu
    gameover.setOutlineThickness(2);///ustawia grubosc konturu
    gameover.setFillColor(Color(0, 0, 0));///ustawia kolor wypelnienia
    gameover.setCharacterSize(80);///ustawia wielkosc czcionki
    gameover.setString("Game Over!");///ustawia tekst
    gameoverRect = gameover.getLocalBounds();///sluzy do wyposrodkowania tekstu
    gameover.setOrigin(gameoverRect.left + gameoverRect.width / 2.0f, 0);///ustawia srodek tekstu gameover
    gameover.setPosition(Vector2f(WINDOW_WIDTH / 2.0f, 200));///ustawia pozycje tekstu gameover
    //---------------------------------
    start.setFont(font); ///ustawia czcionke do obiektu klasy Text (start)
    start.setOutlineThickness(3);///ustawia grubosc konturu
    start.setCharacterSize(80);///ustawia wielkosc czcionki
    start.setString("Tap to play"); ///ustawia tekst
    startRect = start.getLocalBounds();///sluzy do wyposrodkowania tekstu
    start.setOrigin(startRect.left + startRect.width / 2.0f, startRect.top + startRect.height / 2.0f);///ustawia srodek tekstu start
    start.setPosition(Vector2f(WINDOW_WIDTH / 2.0f, WINDOW_HEIGH / 2.0f));///ustawia pozycje tekstu start

    Land_and_background land_and_background(window);///tworzy obiekt klasy Land_and_background
    Bird bird(window, world);///obiekt klasy Bird
    pipes first, second, third; ///obiekty klasy pipes
    second.x = first.x + 400; ///ustawia wspolrzedne x obiektu
    third.x = first.x + 800;///ustawia wspolrzedne x obiektu
    Colissions objects(bird, first, second, third, success, land_and_background, window, best_score); ///obiekt klasy Colissions

    Color background = Color::White; ///kolor tla

    
    
    while (window.isOpen()) ///petla -okno jest otwarte 
    {
        objects.col(); 
        objects.update(); 
        
        while (active ? window.pollEvent(event) : window.waitEvent(event))///petla od zdarzen wywolywanych przez uzytkownika
        {
            bird.default_rotation(); ///domyslna rotacje ptaka

            switch (event.type)/// kontrukcja switch do obslugi zdarzen pobraych od uzytkownika
            {
            case Event::Closed:
                window.close();
                break;
            case Event::KeyPressed:
                if (event.key.code == Keyboard::Escape)
                    window.close();
                break;
            case Event::LostFocus:
                background = Color::Black;
                break;
            case Event::GainedFocus:
               background = Color::White;
                break;
            case Event::MouseLeft:
                active = false;
                break;
            case Event::MouseEntered:
                active = true;
                break;
            case Event::TouchBegan:
                if (event.touch.finger == 0 && bird.alive == 1)
                {
                    bird.leftClick();
                }
                else if (event.touch.finger == 0 && bird.alive == 0)
                {
                    for (auto i : { &first,&second,&third }) i->reset();
                    bird.reset();
                }
                break;
            default:
                while (init)
                {

                    land_and_background.draw_background();
                    land_and_background.draw_lands();
                    bird.draw();
                    bird.animation();
                    window.draw(start);
                    window.display();
                    if (Touch::isDown(0))
                    {
                        init = false;
                        break;
                    }
                }
                break;
                    
            }
        }

        window.clear(); ///odswieza ekran

        land_and_background.draw_background(); 
        for (auto i : { &first,&second,&third }) i->draw(window);
        land_and_background.draw_lands();
        bird.draw();
       
      
        score.setString(to_string(bird.counter)); 
        window.draw(score);///ustawia zmienna counter jako tekst

        world.Step(timeStep, velIt, posIt);///symulacja stworzonego smiata

        

       /** jesli ptak zyje to wywoluje animacje i ruch ptaka, ruch ladu i rur
        *	jesli nie wypisuje na ekran tekst ustawiony w gameover i odtwarza dzwiek konca gry
        **/
      if (bird.alive==true)
        {
            bird.animation();
            bird.movement();
            for (auto i : { &first,&second,&third }) i->movement();
        }
     else
        {

          window.draw(gameover);
          if (song == 1) {
              fail.play();
              song = 0;
          }


        }


        objects.best_score_();

           window.display();///wyswietla aplikacje
    }
}

	
	
	




