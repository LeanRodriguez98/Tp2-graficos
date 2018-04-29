#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <SDL.h>
#include <SDL_image.h>
using namespace std;

#define X 600
#define Y 600

int main(int, char** argv) {
	srand(time(NULL));
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", SDL_GetError(), NULL);
		SDL_Quit();
		return 1;
	}

	int gameOver;
	int typeEvent;
	const unsigned char *Keys;
	

	int random = 0;
	int color = 0;
	int R = 0;	
	int G = 0;	
	int B = 0;
	int tempo = 5550;
	int timer = tempo;
	int reductor = 50;
	bool Breductor = false;

	bool bool0 = true;
	bool bool1 = true;
	bool bool2 = true;
	bool bool3 = true;
	bool bool4 = true;
	bool bool5 = true;
	bool bool6 = true;
	bool bool7 = true;

	bool loop = false;
	
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
	int  posx = X / 2 - destR.w /2;
	int  posy = Y / 2 - destR.h / 2;
	destR.x = posx;
	destR.y = posy;

	while (!gameOver)
	{
		/*while (Breductor == false)
		{
			if (Keys[SDL_SCANCODE_Z])
			{
				reductor = 50;
				Breductor = true;
				cout << "h" << endl;

			}
			if (Keys[SDL_SCANCODE_X])
			{
				reductor = 100;
				Breductor = true;
				cout << "h" << endl;

			}
			if (Keys[SDL_SCANCODE_C])
			{
				reductor = 150;
				Breductor = true;
				cout << "h" << endl;

			}
		}*/
		timer++;
		if (timer >= tempo)
		{
			do
			{
				random = rand() % 8;
			} while (random == color);

			color = random;

			if (color == 0)
			{
				R = 0;
				G = 0;
				B = 0;
				bool0 = false;
				cout << "arriba" << endl;
			}
			if (color == 1)
			{
				R = 255;
				G = 255;
				B = 255;
				bool1 = false;
				cout << "abajo" << endl;
			}
			if (color == 2)
			{
				R = 255;
				G = 0;
				B = 0;			
				bool2 = false;
				cout << "izquierda" << endl;
			}
			if (color == 3)
			{
				R = 0;
				G = 255;
				B = 0;
				bool3 = false;
				cout << "derecha" << endl;
			}
			if (color == 4)
			{
				R = 0;
				G = 0;
				B = 255;
				bool4 = false;
				cout << "w" << endl;
			}
			if (color == 5)
			{
				R = 255;
				G = 255;
				B = 0;
				bool5 = false;
				cout << "s" << endl;
			}
			if (color == 6)
			{
				R = 0;
				G = 255;
				B = 255;
				bool6 = false;
				cout << "a" << endl;
			}
			if (color == 7)
			{
				R = 255;
				G = 0;
				B = 255;
				bool7 = false;
				cout << "d" << endl;
			}

			timer = 0;
			tempo -= reductor;
			cout << random << endl;
			cout << endl;
			cout << endl;
			cout << endl;

			loop = true;
		}

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

			if (Keys[SDL_SCANCODE_UP] && bool0 == true && loop == true)
			{
				gameOver = -1;
				cout << "perdiste el ritmo" << endl;
				loop = false;
			}
			if (Keys[SDL_SCANCODE_UP] && bool0 == false && loop == true)
			{
				posy = posy - 10;
				bool0 = true;
				cout << "seguiste el ritmo" << endl;
				loop = false;

			}

			
			if (Keys[SDL_SCANCODE_DOWN] && bool1 == true && loop == true)
			{
				gameOver = -1;
				cout << "perdiste el ritmo" << endl;
				loop = false;

			}
			if (Keys[SDL_SCANCODE_DOWN] && bool1 == false && loop == true)
			{
				posy = posy + 10;
				bool1 = true;
				cout << "seguiste el ritmo" << endl;
				loop = false;

			}

		

			if (Keys[SDL_SCANCODE_LEFT] && bool2 == true && loop == true)
			{
				gameOver = -1;
				cout << "perdiste el ritmo" << endl;
				loop = false;

			}
			if (Keys[SDL_SCANCODE_LEFT] && bool2 == false && loop == true)
			{
				posx = posx - 10;
				bool2 = true;
				cout << "seguiste el ritmo" << endl;
				loop = false;

			}

		
			if (Keys[SDL_SCANCODE_RIGHT] && bool3 == true && loop == true)
			{
				gameOver = -1;
				cout << "perdiste el ritmo" << endl;
				loop = false;

			}
			if (Keys[SDL_SCANCODE_RIGHT] && bool3 == false && loop == true)
			{
				posx = posx + 10;
				bool3 = true;
				cout << "seguiste el ritmo" << endl;
				loop = false;

			}

		
			if (Keys[SDL_SCANCODE_W] && bool4 == true && loop == true)
			{
				gameOver = -1;
				cout << "perdiste el ritmo" << endl;
				loop = false;

			}
			if (Keys[SDL_SCANCODE_W] && bool4 == false && loop == true)
			{
				posy = posy - 10;
				bool4 = true;
				cout << "seguiste el ritmo" << endl;
				loop = false;

			}

			

			if (Keys[SDL_SCANCODE_S] && bool5 == true && loop == true)
			{
				gameOver = -1;
				cout << "perdiste el ritmo" << endl;
				loop = false;

			}
			if (Keys[SDL_SCANCODE_S] && bool5 == false && loop == true)
			{
				posy = posy + 10;
				bool5 = true;
				cout << "seguiste el ritmo" << endl;
				loop = false;

			}

			
			if (Keys[SDL_SCANCODE_A] && bool6 == true && loop == true)
			{
				gameOver = -1;
				cout << "perdiste el ritmo" << endl;
				loop = false;

			}
			if (Keys[SDL_SCANCODE_A] && bool6 == false && loop == true)
			{
				posx = posx - 10;
				bool6 = true;
				cout << "seguiste el ritmo" << endl;
				loop = false;

			}

			

			if (Keys[SDL_SCANCODE_D] && bool7 == true && loop == true)
			{
				gameOver = -1;
				cout << "perdiste el ritmo" << endl;
				loop = false;

			}
			if (Keys[SDL_SCANCODE_D] && bool7 == false && loop == true)
			{
				posx = posx + 10;
				bool7 = true;
				cout << "seguiste el ritmo" << endl;
				loop = false;

			}
			
		

			
			destR.x = posx;
			destR.y = posy;
			if (destR.x <= 0)
			{
				destR.x = 0;
				posx = 0;
			}
			if (destR.x + destR.w >= X)
			{
				destR.x = X - destR.w;
				posx = X - destR.w;
			}
			if (destR.y <= 0)
			{
				destR.y = 0;
				posy = 0;
			}
			if (destR.y + destR.h >= Y)
			{
				destR.y = Y - destR.h;
				posy = Y - destR.h;
			}
			
		}	

		if ((timer == tempo-1) && (bool0 == false || bool1 == false || bool2 == false || bool3 == false || bool4 == false || bool5 == false || bool6 == false || bool7 == false))
		{
			gameOver = -1;// cambiar por pantalla de game over
			cout << "no aguantaste el ritmo" << endl;
		}

		if (tempo <= 50)
		{
			gameOver = -1;
			cout << "ganaste" << endl;
		}

		SDL_SetRenderDrawColor(renderer, R, G, B, 0);
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, playerTexture, NULL, &destR);
		SDL_RenderPresent(renderer);
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	cin.get();

	
	return 0;
}