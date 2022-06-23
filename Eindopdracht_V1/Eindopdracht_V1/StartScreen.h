
#pragma once

#include <SFML/Graphics.hpp>

#include "Constants.h"

using namespace std;
using namespace sf;

class StartScreen {

	private:

	Font font;

	Text textOne;
	Text textTwo;
	Text textThree;
	Text textFour;

	public:

	StartScreen();

	void Draw(RenderWindow& window);

};

