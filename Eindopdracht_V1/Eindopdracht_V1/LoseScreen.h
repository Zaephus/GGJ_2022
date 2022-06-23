
#pragma once

#include <SFML/Graphics.hpp>

#include "Constants.h"

using namespace std;
using namespace sf;

class LoseScreen {

	private:

	Font font;

	Text textOne;
	Text textTwo;

	public:

	LoseScreen();

	void Draw(RenderWindow& window);

};

