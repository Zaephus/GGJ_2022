
#pragma once
#include <SFML/Graphics.hpp>

#include "Constants.h"
#include "Vector2d.h"

using namespace sf;

class Rigidbody {

	private:
		float friction;
		float dt;

		void CalculateFriction();
		void SetCenterOfMass();

	public:

		Vector2d* position;
		Vector2d* size;
		Vector2d* velocity;
		Vector2d* acceleration;
		Vector2d* addedForce;

		Vector2d* centerOfMass;

		float mass;
		float mu;

		Rigidbody(float posX,float posY,float width,float height,float m,float c);
		~Rigidbody();

		void Update(Time t);

		void SetPosition(float posX,float posY);
		void SetSize(float width,float height);
		void SetMass(float m);

		void AddForce(Vector2d dir);

		void CalculateAcceleration();

		char CheckCollision(float x,float y,float w,float h);

};

