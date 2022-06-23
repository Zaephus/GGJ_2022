
#pragma once

#include <SFML/Graphics.hpp>

#include "Constants.h"

using namespace std;
using namespace sf;

class WinScreen {

	private:

		Font font;

		Text textOne;
		Text textTwo;

	public:

		WinScreen();

		void Draw(RenderWindow& window);

};

