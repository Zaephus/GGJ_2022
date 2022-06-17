
#include <cmath>

#include "Vector2d.h"

using namespace std;

Vector2d::Vector2d(float f1,float f2) {
	x = f1;
	y = f2;
}

Vector2d::~Vector2d() {
	
}

bool Vector2d::Equals(Vector2d v2) {
	if(x == v2.x && y == v2.y) {
		return true;
	}
	else {
		return false;
	}
}

void Vector2d::Normalize() {
	x = x/GetMagnitude();
	y = y/GetMagnitude();
}

Vector2d Vector2d::Normalized() {
	Vector2d temp = Vector2d(x,y);
	temp.Normalize();
	return temp;
}

void Vector2d::Set(float f1, float f2) {
	x = f1;
	y = f2;
}

std::string Vector2d::ToString() {
	return "[" + to_string(x) + "," + to_string(y) + "]";
}

float Vector2d::GetMagnitude() {
	return sqrt((x*x) + (y*y));
}

void Vector2d::Add(Vector2d v2) {
	x = x + v2.x;
	y = y + v2.y;
}

void Vector2d::Sub(Vector2d v2) {
	x = x - v2.x;
	y = y - v2.y;
}

void Vector2d::Mult(float s) {
	x*s;
	y*s;
}