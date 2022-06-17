
#pragma once

#include <string>

#include "Constants.h"

class Vector2d {

	private:

	public:

		float x;
		float y;

		Vector2d(float f1,float f2);
		~Vector2d();

		bool Equals(Vector2d v2);
		void Normalize();
		Vector2d Normalized();
		void Set(float f1,float f2);
		std::string ToString();
		float GetMagnitude();

		void Add(Vector2d v2);
		void Sub(Vector2d v2);
		void Mult(float s);
		
};