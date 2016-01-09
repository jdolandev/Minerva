#pragma once

namespace Minerva {
	struct Rect
	{
		Rect(int x, int y, int h, int w);
		~Rect();
		int x, y, w, h;
	};
}
