
#include <SFML/Graphics.hpp>
#include <sstream>
#include <cstdlib>
#include <iostream>
#include <array>

#include "Constants.h"
#include "GameManager.h"
#include "StartScreen.h"
#include "WinScreen.h"
#include "LoseScreen.h"

using namespace std;
using namespace sf;

int main() {

    srand(time(NULL));

    bool onGame = false;
    bool onStartScreen = true;
    bool onWinScreen = false;
    bool onLoseScreen = false;

    GameManager gameManager = GameManager();
    StartScreen startScreen = StartScreen();
    WinScreen winScreen = WinScreen();
    LoseScreen loseScreen = LoseScreen();

    Clock deltaClock;
    RenderWindow window(VideoMode(windowWidth,windowHeight),"Eindopdracht Game Dev ++");

    while(window.isOpen()) {

        if(!onStartScreen) {
            if(gameManager.score >= 20) {
                onGame = false;
                onStartScreen = false;
                onLoseScreen = false;
                onWinScreen = true;
            }
            else if(gameManager.score <= 0) {
                onGame = false;
                onStartScreen = false;
                onWinScreen = false;
                onLoseScreen = true;
            }
            else {
                onWinScreen = false;
                onLoseScreen = false;
                onStartScreen = false;
                onGame = true;
            }
        }

        Time dt = deltaClock.restart();

        Event event;
        while(window.pollEvent(event)) {
            if(event.type == Event::Closed)
                window.close();
        }

        if(Keyboard::isKeyPressed(Keyboard::Escape)) {
            window.close();
        }
        
        window.clear();

        
        if(onStartScreen) {
            startScreen.Draw(window);
            if(Keyboard::isKeyPressed(Keyboard::Space)) {
                onStartScreen = false;
                onWinScreen = false;
                onLoseScreen = false;
                onGame = true;
            }
        }
        else if(onGame) {
            gameManager.Update(dt);
            gameManager.Draw(window);
        }
        else if(onWinScreen) {
            winScreen.Draw(window);
        }
        else if(onLoseScreen) {
            loseScreen.Draw(window);
        }
        
        window.display();

    }

    return 0;
}