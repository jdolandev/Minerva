#pragma once
#include <math.h>

#define M_PI 3.14159

namespace Minerva {
	namespace MathFx {
		//Linear Interpolation
		inline float Lerp(float start, float end, float value) {
			return ((1.0f - value) * start) + (value * end);
		}

		inline float Sinerp(float start, float end, float value) {
			return Lerp(start, end, sin(value * M_PI * 0.5f));
		}
	}
}