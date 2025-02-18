#ifndef __GBPPU_H__
#define __GBPPU_H__

#include "../GbStructs.h"
#include "../help/Logger.h"
#include <SDL3/SDL.h>
#include <stdio.h>


class GbPpu
{
	//SCREEN
	u8 SCREEN[WIDTH][HEIGHT];
	SDL_Window* window;

	SDL_Surface* surface;
	SDL_Renderer* renderer;
	
	u8 pallete[PALLETE_SIZE][PALLETE_SIZE] = {
		{140, 173, 40, 255},
		{108, 148, 33, 255},
		{66, 107, 41, 255},
		{33, 66, 49, 255}
	};
	
	bool mInit;

public:
	GbPpu();
	bool Init();
	void Render();
};

#endif // __GBPPU_H__

