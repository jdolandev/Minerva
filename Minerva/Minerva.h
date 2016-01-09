#pragma once

#include <iostream>
#include <fstream>
#include <time.h>
#include <math.h>

//SDL/OpenGL includes
#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>

//Minerva Includes
#include "SpriteBatch.h"
#include "Vec.h"
#include "Mathfx.h"

#define FPS 60

// REMEMBER: Xi - ANiMA

namespace Minerva 
{
	int Minerva_Init();		//Initialize all subsystems

	class MWindow {
	public:
		MWindow(char* title, int w, int h, bool cap);
		~MWindow();
		void UpdateFunction(void(*function)(Minerva::MWindow*));
		void DrawFunction(void(*function)(Minerva::MWindow*));
		
		void run();
		inline SDL_Window* getWindow() { return window; }
		inline SDL_Renderer* getRenderer() { return renderer; }

		void update(Minerva::MWindow*);
		void draw(Minerva::MWindow*);
		bool isRunning = false;
	private:
		SDL_Window* window;
		SDL_Renderer* renderer;
		void(*Update)(Minerva::MWindow*) = nullptr;
		void(*Draw)(Minerva::MWindow*) = nullptr;
		Uint32 start;
		bool cap;
	};

	void Minerva_Quit();
}