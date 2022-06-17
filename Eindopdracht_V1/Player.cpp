
#include <iostream>

#include "Player.h"

using namespace std;

Player::Player(float startX, float startY,float width,float height) {

	position = new Vector2d(startX,startY);

	size = new Vector2d(width,height);

	body = new Rigidbody(startX,startY,width,height,1,0.8f);

	playerShape.setPosition(sf::Vector2f(position->x,position->y));
	playerShape.setSize(sf::Vector2f(size->x,size->y));

}

Player::~Player() {
	delete(position);
	delete(size);
	delete(body);
}

void Player::Update(Time t) {
	position->Set(body->position->x,body->position->y);
	body->Update(t);
	playerShape.setPosition(sf::Vector2f(position->x, position->y));
}

void Player::Draw(sf::RenderWindow& window) {
	playerShape.setFillColor(sf::Color::Cyan);
	window.draw(playerShape);
}

void Player::MoveLeft() {
	body->AddForce(Vector2d(-2000,0));
}

void Player::MoveRight() {
	body->AddForce(Vector2d(2000,0));
}