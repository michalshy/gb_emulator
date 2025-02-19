#ifndef __GBPPU_H__
#define __GBPPU_H__

#include "../GbStructs.h"
#include "../help/Logger.h"
#include "GbMem.h"
#include <SDL3/SDL.h>
#include <stdio.h>


class GbPpu
{
	//SCREEN
	GbMem& VRAM;
	SDL_Window* window;
	SDL_Surface* surface;
	SDL_Renderer* renderer;
	u8 pallete[PALLETE_SIZE][PALLETE_SIZE] = {
		{140, 173, 40, 255},
		{108, 148, 33, 255},
		{66, 107, 41, 255},
		{33, 66, 49, 255}
	};
	SDL_FRect pixels[TILES_NUMBER][PIXELS_FOR_TILE];
	bool mInit;
public:
	GbPpu(GbMem& _VRAM);
	bool Init();
	void DrawTiles();
	void Render();
protected:
	void SetPositions();
};

#endif // __GBPPU_H__

