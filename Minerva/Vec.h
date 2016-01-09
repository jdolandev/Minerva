#pragma once
#include <cmath>

#ifndef __VECTOR_H_
#define __VECTOR_H_

namespace Minerva {

	//VECTOR 2
	template <class T> 
	class Vec2 {
	public:
		T x, y;
		
		Vec2() : x(0), y(0) {}
		Vec2(T x, T y) : x(x), y(y) {}
		Vec2(const Vec2& v) : v(v.x), y(v.y) {}

		Vec2& operator=(const Vec2& v) {
			x = v.x;
			y = v.y;
			return *this;
		}

		Vec2 operator+(Vec2& v) {
			return Vec2(x + v.x, y + v.y);
		}
		
		Vec2 operator-(Vec2& v) {
			return Vec2(x - v.x, y - v.y);
		}

		Vec2 operator+=(Vec2& v) {
			x += v.x;
			y += v.y;
			return *this;
		}

		Vec2 operator-=(Vec2& v) {
			x -= v.x;
			y -= v.y;
			return *this;
		}

		Vec2 operator+(double s) {
			return Vec2(x + s, y + s);
		}

		Vec2 operator-(double s) {
			return Vec2(x - s, y - s);
		}

		Vec2 operator*(double s) {
			return Vec2(x * s, y * s);
		}

		Vec2 operator/(double s) {
			return Vec2(x / s, y / s);
		}

		float length() const {
			return std::sqrt(x * x + y * y);
		}

		Vec2& normalize() {
			if (length() == 0) return *this;
			*this *= (1.0 / length());
			return *this;
		}

		static float dot(Vec2 v1, Vec2 v2) {
			return v1.x * v2.x + v1.y * v2.y;
		}

		static float cross_product(Vec2 v1, Vec2 v2) {
			return (v1.x * v2.y) - (v1.y * v2.x);
		}
	};

	typedef Vec2<int> Vec2i;
	typedef Vec2<float> Vec2f;
	typedef Vec2<double> Vec2d;

	//VECTOR 3
	template <class T>
	class Vec3 {
	public:
		Vec3() : x(0), y(0), z(0) {}
		Vec3(T x, T y, T z) : x(x), y(y), z(z) {}
		Vec3(const Vec2<T>& v, T z) : x(v.x), y(v.y), z(z) {}
		T x, y, z;
	};

	typedef Vec3<int> Vec3i;
	typedef Vec3<float> Vec3f;
	typedef Vec3<double> Vec3d;
}
#endif