#ifndef __GBPPU_H__
#define __GBPPU_H__

#include "GbStructs.h"
#include <SDL3/SDL.h>
#include <stdio.h>

class GbPpu
{
	//SCREEN
	u8 SCREEN[WIDTH][HEIGHT];
	SDL_Window* window;

	SDL_Surface* surface;
	SDL_Renderer* renderer;

	bool mInit;

public:
	GbPpu();
	bool Init();
	void Render();
};

#endif // __GBPPU_H__

