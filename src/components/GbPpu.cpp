#include "GbPpu.h"

GbPpu::GbPpu(GbMem& _mem) : mem(_mem)
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
	u16 index = VRAM_START;
	for (int i = 0; i < TILES_NUMBER; i++)
	{
		u8 tile[16];
		for (int j = 0; j < 16; j++)
		{
			tile[j] = mem.ReadByte(index);
			index++;
		}
		for (int j = 0; j < PIXELS_FOR_TILE; j++)
		{
			u8 colorMask = GetColorMask(j, tile);
			SDL_SetRenderDrawColor(
				renderer, 
				pallete[colorMask][0],
				pallete[colorMask][1],
				pallete[colorMask][2],
				pallete[colorMask][3]
			);
			SDL_RenderFillRect(renderer, &pixels[i][j]);
			SDL_RenderRect(renderer, &pixels[i][j]);
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

		DrawTiles();
		
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
			pixels[i][j].x = ((i*BYTE)%WIDTH)+(j%BYTE);
			pixels[i][j].y = ((i/TILES_IN_SCREEN)*BYTE)+(j/BYTE);
			pixels[i][j].w = pixels[i][j].h = 1;
		}
	}
}

u8 GbPpu::GetColorMask(u8 j, u8 (&tile)[16])
{
	u8 line = j / 8;
	u8 lineOffest = line * 2;
	u8 offest = 7 - (j % 8);

	u8 lsb = (tile[lineOffest] >> offest) & 1;
	u8 msb = (tile[lineOffest + 1] >> offest) & 1;

	u8 res = (msb << 1) | lsb;

	return res;
}
