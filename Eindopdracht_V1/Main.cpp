
#include <SFML/Graphics.hpp>
#include <sstream>
#include <cstdlib>
#include <iostream>

#include "Constants.h"
#include "Player.h"
#include "Car.h"

using namespace std;
using namespace sf;

int main() {

    srand(time(NULL));

    Clock deltaClock;
    RenderWindow window(VideoMode(windowWidth,windowHeight),"Eindopdracht Game Dev ++");

    Player player = Player(250,600,25,60);
    Car car1 = Car(100,-100,40,60);
    Car car2 = Car(200,-300,40,60);
    Car car3 = Car(350,-600,40,60);

    while(window.isOpen()) {

        Time dt = deltaClock.restart();

        player.Update(dt);
        car1.Update(dt);
        car2.Update(dt);
        car3.Update(dt);

        Event event;
        while(window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }

        if(Keyboard::isKeyPressed(Keyboard::Left)) {
            player.MoveLeft();
        }
        else if(Keyboard::isKeyPressed(Keyboard::Right)) {
            player.MoveRight();
        }
        else if (Keyboard::isKeyPressed(Keyboard::Escape)) {
            window.close();
        }

        window.clear();
        player.Draw(window);
        car1.Draw(window);
        car2.Draw(window);
        car3.Draw(window);
        window.display();
    }

    return 0;
}