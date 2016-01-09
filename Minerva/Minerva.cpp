#include "Minerva.h"

static Uint32 next_time;

// Used to initialize all Minerva subsystems
// Basically a shorthand for SDL
int Minerva::Minerva_Init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		fprintf(stderr, "\nFatal error when starting Minerva: %s\n", SDL_GetError());
		return 1;		//Oh no motherfucker, there was a problem!!
	}
	else {
		return 0;		//Everything initialized successfully
	}
}

//Honestly just does nothing aside from quit SDL
void Minerva::Minerva_Quit()
{
	SDL_Quit();
}

Uint32 time_left(void)
{
	Uint32 now;

	now = SDL_GetTicks();
	if (next_time <= now)
		return 0;
	else
		return next_time - now;
}

void Minerva::MWindow::run()
{
	next_time = SDL_GetTicks() + 1000 / FPS;
	while (isRunning) {
		if (cap) {
			SDL_Delay(time_left());
			next_time += 1000 / FPS;
		}
		if (Update != nullptr) {
			Update(this);
		} else {
			fprintf(stderr, "\nFatal error, no main Update Loop!");
			Minerva_Quit();
		}
		if (Draw != nullptr) {
			SDL_RenderClear(renderer);
			Draw(this);
			SDL_RenderPresent(renderer);
		} else {
			fprintf(stderr, "\nFatal Error, no main Draw Loop!");
			Minerva_Quit();
		}
		
	}
}

Minerva::MWindow::MWindow(char* title, int w, int h, bool _cap) 
{
	cap = _cap;
	start = SDL_GetTicks();
	window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_SHOWN);	// The window you'll be loading
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);			// The renderer
	isRunning = true;
}

Minerva::MWindow::~MWindow()
{
}
void Minerva::MWindow::update(Minerva::MWindow*)
{
	Update(this);
}

void Minerva::MWindow::draw(Minerva::MWindow*)
{
	Draw(this);
}

//Sets the main update function
void Minerva::MWindow::UpdateFunction(void(*function)(Minerva::MWindow*))
{
	Update = function;
}

//Sets the main draw function
void Minerva::MWindow::DrawFunction(void(*function)(Minerva::MWindow*))
{
	Draw = function;
}