
#include <string>

#include "StartScreen.h"

StartScreen::StartScreen() {

	if(!font.loadFromFile("Calibri Regular.ttf")) {
		//error
	}

	string stringOne = "Main Menu";

	textOne.setFont(font);
	textOne.setCharacterSize(82);
	textOne.setFillColor(Color::White);
	textOne.setString(stringOne);
	textOne.setPosition(Vector2f(150,100));
	textOne.setStyle(Text::Bold);

	string stringTwo = "Press space to start";

	textTwo.setFont(font);
	textTwo.setCharacterSize(24);
	textTwo.setFillColor(Color::White);
	textTwo.setString(stringTwo);
	textTwo.setPosition(Vector2f(200,450));
	textTwo.setStyle(Text::Bold);

	string stringThree = "You win at 20 score";

	textThree.setFont(font);
	textThree.setCharacterSize(24);
	textThree.setFillColor(Color::White);
	textThree.setString(stringThree);
	textThree.setPosition(Vector2f(650,250));
	textThree.setStyle(Text::Bold);

	string stringFour = "You lose at 0";

	textFour.setFont(font);
	textFour.setCharacterSize(24);
	textFour.setFillColor(Color::White);
	textFour.setString(stringFour);
	textFour.setPosition(Vector2f(650,300));
	textFour.setStyle(Text::Bold);

}

void StartScreen::Draw(RenderWindow& window) {
	window.draw(textOne);
	window.draw(textTwo);
	window.draw(textThree);
	window.draw(textFour);
}