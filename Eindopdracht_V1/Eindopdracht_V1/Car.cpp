
#include <iostream>

#include "Car.h"

Car::Car(float startX, float startY, float width, float height) {

	position = new Vector2d(startX,startY);

	size = new Vector2d(width,height);

	body = new Rigidbody(startX,startY,width,height,1,0.8f);

	speed = new Vector2d(0.01f,0.2f);

	carShape.setPosition(sf::Vector2f(position->x,position->y));
	carShape.setSize(sf::Vector2f(size->x,size->y));

	isMovingLeft = false;
	isMovingRight = true;

	speedMultiplier = 0;

}

Car::~Car() {
	delete(position);
	delete(size);
	delete(body);
}

void Car::Update(Time t) {

	position->Set(body->position->x,body->position->y);
	body->Update(t);
	MoveDown();
	carShape.setPosition(sf::Vector2f(position->x,position->y));

	if(isMovingLeft && body->CheckCollision(0,-1000,10,windowHeight + 1200) == 'r') {
		isMovingLeft = false;
		isMovingRight = true;
	}

	if(isMovingRight && body->CheckCollision(windowWidth,-1000,10,windowHeight + 1200) == 'l') {
		isMovingRight = false;
		isMovingLeft = true;
	}

	if(isMovingRight) {
		MoveRight();
	}
	if(isMovingLeft) {
		MoveLeft();
	}

}

void Car::Draw(sf::RenderWindow& window) {
	carShape.setFillColor(sf::Color::Red);
	window.draw(carShape);
}

Vector2d Car::GetPosition() {
	return *position;
}

void Car::ResetPosition() {
	body->position->x = 0 + rand() % ((windowWidth - 0) + 1);
	body->position->y = -200 + rand() % ((-100 - -200) + 1);
}

void Car::MoveLeft() {
	isMovingLeft = true;
	body->AddForce(Vector2d(-(1000 + speedMultiplier),0));
}

void Car::MoveRight() {
	isMovingRight = true;
	body->AddForce(Vector2d((1000 + speedMultiplier),0));
}

void Car::MoveUp() {
	body->AddForce(Vector2d(0,-(2000 + speedMultiplier)));
}

void Car::MoveDown() {
	body->AddForce(Vector2d(0,(2000 + speedMultiplier)));
}