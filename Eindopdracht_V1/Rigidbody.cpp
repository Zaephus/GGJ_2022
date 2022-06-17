
#include "Rigidbody.h"

#include <iostream>
using namespace std;

Rigidbody::Rigidbody(float posX,float posY,float width,float height,float m,float c) {
	position = new Vector2d(posX,posY);
	size = new Vector2d(width,height);
	velocity = new Vector2d(0,0);
	acceleration = new Vector2d(0,0);
	addedForce = new Vector2d(0,0);
	
	centerOfMass = new Vector2d(0,0);

	mass = m;
	mu = c;

	CalculateFriction();
	SetCenterOfMass();
}

Rigidbody::~Rigidbody() {
	delete(position);
	delete(size);
	delete(velocity);
	delete(acceleration);
	delete(addedForce);
	delete(centerOfMass);
}

void Rigidbody::Update(Time t) {

	dt = t.asSeconds();

	position->Add(Vector2d(velocity->x*dt,velocity->y*dt));
	velocity->Add(Vector2d(acceleration->x*dt,acceleration->y*dt));
	CalculateAcceleration();

}

void Rigidbody::SetPosition(float posX,float posY) {
	position->Set(posX,posY);
}

void Rigidbody::SetSize(float width,float height) {
	size->Set(width,height);
}

void Rigidbody::SetMass(float m) {
	mass = m;
	CalculateFriction();
}

void Rigidbody::CalculateFriction() {
	friction = mu*mass*9.81f;
}

void Rigidbody::SetCenterOfMass() {
	centerOfMass->Set(position->x + (size->x/2),position->y + (size->y/2));
}

void Rigidbody::AddForce(Vector2d force) {
	addedForce->Add(Vector2d(force.x,force.y));
}

void Rigidbody::CalculateAcceleration() {
	float ax = (addedForce->x - (friction*velocity->x))/mass;
	float ay = (addedForce->y - (friction*velocity->y))/mass;
	acceleration->Set(ax,ay);
	addedForce->Set(0,0);
}

char Rigidbody::CheckCollision(float x,float y,float w,float h) {

	char side = 'x';

	if(position->y + size->y >= y && position->y < y + h && position->x + size->x >= x && position->x <= x + w) {
		if(position->y + size->y < y + velocity->y && position->x + size->x > x && position->x < x + w) {
			side = 't';
		}
		else if(position->y > y + h + velocity->y && position->x + size->x > x && position->x < x + w) {
			side = 'b';
		}
		else if(position->x > x + w + velocity->x && position->y + size->y > y && position->y < y + h) {
			side = 'r';
		}
		else if(position->x + size->x < x + velocity->x && position->y + size->y > y && position->y < y + h) {
			side = 'l';
		}
		else {
			side = 'x';
		}

		return side;

	}

}