#pragma once
#ifndef __SPRITEBATCH_H_
#define __SPRITEBATCH_H_

#include <SDL_image.h>

namespace Minerva {
	class SpriteBatch
	{
	public:
		void Draw();
		SpriteBatch();
		~SpriteBatch();
	};
}
#endif	/* SpriteBatch */