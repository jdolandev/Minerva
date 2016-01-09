#include "Minerva.h"

SDL_Texture* m_pTexture;
SDL_Rect m_sourceRect;
SDL_Rect m_destRect;

time_t timer;

int frames;

void setUp(Minerva::MWindow* window)
{
	frames = 0;
	SDL_Surface* pTempSurface = IMG_Load("img/animate.png");
	m_pTexture = SDL_CreateTextureFromSurface(window->getRenderer(), pTempSurface);
	SDL_FreeSurface(pTempSurface);
	m_destRect.x = m_sourceRect.x = 0;
	m_destRect.y = m_sourceRect.y = 0;
	m_destRect.w = m_sourceRect.w = 32;
	m_destRect.h = m_sourceRect.h = 32;
}

void update(Minerva::MWindow* window)
{
	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		if (e.type == SDL_QUIT) {
			window->isRunning = false;
		}
		if (e.type == SDL_KEYDOWN) {
			window->isRunning = false;
		}
	}
}

float degtorad(float degrees) {
	return degrees * 3.14159 / 180;
}

void draw(Minerva::MWindow* window)
{
	SDL_SetRenderDrawColor(window->getRenderer(), 255, 255, 255, 255);
	Minerva::Vec2i mouse;
	SDL_GetMouseState(&mouse.x, &mouse.y);
	
	float p1x =	mouse.x + (cos(degtorad(frames) * 5) * 16.0f);
	float p1y = mouse.y + (sin(degtorad(frames) * 5) * 16.0f);
	float p2x = mouse.x + (cos(degtorad(frames + 120) * 5) * 16.0f);
	float p2y = mouse.y + (sin(degtorad(frames + 120) * 5) * 16.0f);
	float p3x = mouse.x + (cos(degtorad(frames + 240) * 5) * 16.0f);
	float p3y = mouse.y + (sin(degtorad(frames + 240) * 5) * 16.0f);

	SDL_RenderDrawPoint(window->getRenderer(), p1x, p1y);
	SDL_RenderDrawPoint(window->getRenderer(), p2x, p2y);
	SDL_RenderDrawPoint(window->getRenderer(), p3x, p3y);
	SDL_SetRenderDrawColor(window->getRenderer(), 0, 0, 0, 255);
	frames++;
	SDL_QueryTexture(m_pTexture, NULL, NULL, &m_sourceRect.w, &m_sourceRect.h);
	SDL_RendererFlip flip = SDL_FLIP_VERTICAL;
	SDL_RenderCopyEx(window->getRenderer(), m_pTexture, &m_sourceRect, &m_destRect, frames, NULL, flip);
}

int main(int argc, char* argv[])
{
	Minerva::MWindow a = Minerva::MWindow("Dracul", 640, 480, true);
	setUp(&a);
	a.UpdateFunction( update );
	a.DrawFunction( draw );
	a.run();
	Minerva::Minerva_Quit();
	return 0;
}