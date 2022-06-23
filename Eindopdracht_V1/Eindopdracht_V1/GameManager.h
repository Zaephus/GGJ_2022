
#pragma once

#include <SFML/Graphics.hpp>
#include <sstream>
#include <cstdlib>
#include <iostream>
#include <array>

#include "Constants.h"
#include "Player.h"
#include "Car.h"

using namespace std;
using namespace sf;

class GameManager {

	private:
		
		Player* player = new Player(450,500,75,20);
		array<Car*,enemyAmount> cars = { new Car(100,-100,40,60),new Car(200,-300,40,60),new Car(350,-600,40,60),new Car(600,-150,40,60) };

		Font font;

		Text scoreText;
		
	public:

		int score;

		GameManager();
		~GameManager();

		void Update(Time dt);
		void Draw(RenderWindow& window);

};