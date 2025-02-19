#include "GbPpu.h"

GbPpu::GbPpu(GbMem& _VRAM) : VRAM(_VRAM)
{
	mInit = false;

	window = NULL;
	surface = NULL;
	renderer = NULL;

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

bool GbPpu::Init()
{
	//Create window
	window = SDL_CreateWindow("GameBoy_michin", WIDTH, HEIGHT, 0);
	//Create renderer
	renderer = SDL_CreateRenderer(window, NULL);
	if (window == NULL || renderer == NULL)
	{
		mInit = false;
	}
	else
	{
		mInit = true;
	}

	if (mInit)
	{
		SetPositions();
	}

	return mInit;
}

void GbPpu::DrawTiles()
{
	int index = VRAM_START;
	for (int i = 0; i < TILES_NUMBER; i++)
	{
		for (int j = 0; j < PIXELS_FOR_TILE; j++)
		{
			
		}
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
		/* Let's draw a single rectangle (square, really). */
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);

		SetPositions();
		/*rect.x = rect.y = 0;
		rect.h = rect.w = TILE_SIZE_RES;
		SDL_RenderClear(renderer);
		SDL_SetRenderDrawColor(renderer, pallete[0][0], pallete[0][1], pallete[0][2], pallete[0][3]);
		SDL_RenderFillRect(renderer, &rect);
		SDL_RenderRect(renderer, &rect);*/
		
		SDL_RenderPresent(renderer);
	}
	else
	{
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
	}
}

void GbPpu::SetPositions()
{
	for (int i = 0; i < TILES_NUMBER; i++)
	{
		for (int j = 0; j < PIXELS_FOR_TILE; j++)
		{
			pixels[i][j].x = ((i*8)%WIDTH)+(j%8);
			pixels[i][j].y = ((i*8)%HEIGHT);
			pixels[i][j].w = pixels[i][j].h = 1;
			SDL_SetRenderDrawColor(renderer, pallete[0][0], pallete[0][1], pallete[0][2], pallete[0][3]);
			SDL_RenderFillRect(renderer, &pixels[i][j]);
			SDL_RenderRect(renderer, &pixels[i][j]);
		}
	}
}
