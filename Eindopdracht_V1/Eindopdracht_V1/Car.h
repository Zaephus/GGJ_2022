
#pragma once
#include <SFML/Graphics.hpp>

#include "Constants.h"
#include "Vector2d.h"
#include "Rigidbody.h"

using namespace sf;

class Car {

	private:
		Vector2d* position;
		Vector2d* size;
		Vector2d* speed;

		sf::RectangleShape carShape;

		bool isMovingRight;
		bool isMovingLeft;

	public:

		int speedMultiplier;
		
		Rigidbody* body;

		Car(float startX,float startY,float width,float height);
		~Car();

		void Update(Time t);
		void Draw(sf::RenderWindow& window);

		Vector2d GetPosition();
		void ResetPosition();

		void MoveLeft();
		void MoveRight();
		void MoveUp();
		void MoveDown();

};

