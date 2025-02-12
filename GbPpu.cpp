#include "GbPpu.h"

GbPpu::GbPpu()
{
	mInit = false;
	for (auto& pixel : SCREEN)
	{
		pixel = 0;
	}

	window = NULL;
	surface = NULL;
	renderer = NULL;
	bitmapTex = NULL;
	bitmapSurface = NULL;

	//Intialize
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		mInit = true;
	}
}

void GbPpu::Init()
{
	//Create window
	window = SDL_CreateWindow("GameBoy_michin", WIDTH, HEIGHT, 0);
	//Create renderer
	renderer = SDL_CreateRenderer(window, NULL);
	if (window == NULL || renderer == NULL)
	{
		mInit = false;
	}
}

void GbPpu::Render()
{
	if(mInit)
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_EVENT_QUIT:
				mInit = false;
				break;
			}
		}

		SDL_RenderClear(renderer);
		SDL_RenderTexture(renderer, bitmapTex, NULL, NULL);
		SDL_RenderPresent(renderer);
	}
	else
	{
		SDL_DestroyTexture(bitmapTex);
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
	}
}
