
#pragma once
#include <SFML/Graphics.hpp>
#include <array>

#include "Constants.h"
#include "Vector2d.h"
#include "Rigidbody.h"
#include "Car.h"

using namespace sf;
using namespace std;

class Player {

	private:
		Vector2d* position;
		Vector2d* size;
		sf::RectangleShape playerShape;

		Rigidbody* body;

		float speed = 0.3f;

	public:
		Player(float startX,float startY,float width,float height);
		~Player();

		void Update(Time t);
		void Draw(RenderWindow& window);

		void MoveLeft();
		void MoveRight();

		Vector2d GetPosition();
		Vector2d GetSize();
		
};