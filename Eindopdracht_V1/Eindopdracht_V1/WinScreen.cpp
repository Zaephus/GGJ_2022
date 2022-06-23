
#include <string>

#include "WinScreen.h"

WinScreen::WinScreen() {

	if(!font.loadFromFile("Calibri Regular.ttf")) {
		//error
	}

	string stringOne = "You won!";

	textOne.setFont(font);
	textOne.setCharacterSize(64);
	textOne.setFillColor(Color::White);
	textOne.setString(stringOne);
	textOne.setPosition(Vector2f(200,150));
	textOne.setStyle(Text::Bold);

	string stringTwo = "Press escape to exit";

	textTwo.setFont(font);
	textTwo.setCharacterSize(24);
	textTwo.setFillColor(Color::White);
	textTwo.setString(stringTwo);
	textTwo.setPosition(Vector2f(200,450));
	textTwo.setStyle(Text::Bold);

}

void WinScreen::Draw(RenderWindow& window) {
	window.draw(textOne);
	window.draw(textTwo);
}