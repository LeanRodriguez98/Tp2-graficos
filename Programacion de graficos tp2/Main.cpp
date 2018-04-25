#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
using namespace std;

#define X 600
#define Y 600

int main(int, char** argv) {

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", SDL_GetError(), NULL);
		SDL_Quit();
		return 1;
	}

	int gameOver;
	int typeEvent;
	const unsigned char *Keys;
	int  posx = 0;
	int  posy = 0;

	
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Event event;
	SDL_Texture *playerTexture;
	SDL_Rect srcR, destR;

	window = SDL_CreateWindow("NoSeMeOcureNingunNombre2", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, X, Y, SDL_WINDOW_SHOWN);

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);


	SDL_Surface *tmpSurface = IMG_Load("player.png");
	playerTexture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);

	Keys = SDL_GetKeyboardState(NULL);

	

	gameOver = 0;
	
	destR.h = 64;
	destR.w = 64;
	destR.x = posx;
	destR.y = posy;

	while (!gameOver)
	{

		

		if (SDL_PollEvent(&event))
		{
			typeEvent = event.type;
			if (typeEvent == SDL_QUIT)
			{
				gameOver = 1;
			}
			if (typeEvent == SDL_KEYDOWN)
			{
				if (Keys[SDL_SCANCODE_ESCAPE])
				{
					gameOver = 1;
				}				

			}

			if (Keys[SDL_SCANCODE_LEFT])
			{
				posx = posx - 10;
			}
			if (Keys[SDL_SCANCODE_RIGHT])
			{
				posx = posx + 10;

			}
			if (Keys[SDL_SCANCODE_UP])
			{
				posy = posy - 10;

			}
			if (Keys[SDL_SCANCODE_DOWN])
			{
				posy = posy + 10;

			}
			destR.x = posx;
			destR.y = posy;
			
		}

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, playerTexture, NULL, &destR);
		SDL_RenderPresent(renderer);
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	
	return 0;
}