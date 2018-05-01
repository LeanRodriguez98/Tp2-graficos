#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <Windows.h>
using namespace std;





#define X 600
#define Y 600

int main(int, char** argv) {


	
	srand(time(NULL));

	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", SDL_GetError(), NULL);
		SDL_Quit();
		return 1;
	}
	/*if (Mix_OpenAudio(44100, MIX_DEFAULT_CHANNELS,2,2048) < 0)
	{
		cout << "Error: " << Mix_GetError() << endl;
		cin.get();
	}*/

	// no puedo cargar el audio, prove con una infinidad de archivos y siempre me da el error de que desconoce el formato.
	if (TTF_Init() < 0)
	{
		cout << "Error" << TTF_GetError() << endl;
		//cin.get();
	}
	int gameOver;
	int typeEvent;
	const unsigned char *Keys;
	

	int random = 0;
	int color = 0;
	int R = 0;	
	int G = 0;	
	int B = 0;
	int tempo = 5200;
	int timer = tempo;
	int reductor = 300;
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
	
	bool inicio = false;
	bool textPerdiste = false;
	bool restart = false;
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Event event;
	SDL_Texture *playerTexture;
	SDL_Texture *InicioTexture;
	SDL_Rect srcR, destR, inicioR;

	window = SDL_CreateWindow("Manten el ritmo", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, X, Y, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	TTF_Font *font = TTF_OpenFont("font.otf", 150);
	
	SDL_Color transparente = { 47,79,79,255 };
	SDL_Color blanco = { 255,255,255,255 };
	SDL_Color negro = { 0,0,0,255 };
	SDL_Color rojo = { 255,0,0,255 };
	SDL_Color verde = { 0,255,0,255 };
	SDL_Color azul = { 0,0,255,255 };
	SDL_Color amarillo = { 255,255,0,255 };
	SDL_Color cyan = {0,255,255,255};
	SDL_Color magenta = { 255,0,255,255 };


	SDL_Surface *textSurface = TTF_RenderText_Solid(font,"              ",transparente);
	SDL_Texture *text = SDL_CreateTextureFromSurface(renderer,textSurface);
	SDL_FreeSurface(textSurface);
	SDL_Rect textRect;
	textRect.x = 45;
	textRect.y = 400;

	SDL_QueryTexture(text, NULL, NULL, &textRect.w, &textRect.h);



	/*Mix_Music *fondo = Mix_LoadMUS("tema0.wav");
	Mix_Music *hit1 = Mix_LoadMUS("hit1.mp3");
	Mix_Music *hit2 = Mix_LoadMUS("hit2.mp3");
	Mix_Music *gong = Mix_LoadMUS("gong.mp3");*/





	

	Keys = SDL_GetKeyboardState(NULL);

	

	gameOver = 0;
	
	destR.h = 50 * 4;
	destR.w = 26 * 4;
	int  posx = X / 2 - destR.w /2;
	int  posy = Y / 2 - destR.h / 2 - 100;
	destR.x = posx;
	destR.y = posy;

	inicioR.h = Y;
	inicioR.w = X;
	inicioR.x = 0;
	inicioR.y = 0;

	SDL_Surface *tmpSurface = IMG_Load("i4.png");
	playerTexture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);

	SDL_Surface *inicioSurface = IMG_Load("inicio.png");
	InicioTexture = SDL_CreateTextureFromSurface(renderer, inicioSurface);
	SDL_FreeSurface(inicioSurface);

	//FreeConsole();
	
	while (!gameOver)
	{
		if (inicio == true)
		{


			/*if (!Mix_PlayingMusic())
			{
				Mix_PlayMusic(fondo, -1);
				cout << "culo" << endl;
			}*/



			timer++;
			if (timer >= tempo)
			{
				textSurface = nullptr;
				text = nullptr;
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
					SDL_Surface *tmpSurface = IMG_Load("d1.png");
					playerTexture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
					SDL_FreeSurface(tmpSurface);
				}
				if (color == 1)
				{
					R = 255;
					G = 255;
					B = 255;
					bool1 = false;
					cout << "abajo" << endl;
					SDL_Surface *tmpSurface = IMG_Load("i1.png");
					playerTexture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
					SDL_FreeSurface(tmpSurface);
				}
				if (color == 2)
				{
					R = 255;
					G = 0;
					B = 0;
					bool2 = false;
					cout << "izquierda" << endl;
					SDL_Surface *tmpSurface = IMG_Load("i2.png");
					playerTexture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
					SDL_FreeSurface(tmpSurface);
				}
				if (color == 3)
				{
					R = 0;
					G = 255;
					B = 0;
					bool3 = false;
					cout << "derecha" << endl;
					SDL_Surface *tmpSurface = IMG_Load("d2.png");
					playerTexture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
					SDL_FreeSurface(tmpSurface);
				}
				if (color == 4)
				{
					R = 0;
					G = 0;
					B = 255;
					bool4 = false;
					cout << "w" << endl;
					SDL_Surface *tmpSurface = IMG_Load("d3.png");
					playerTexture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
					SDL_FreeSurface(tmpSurface);
				}
				if (color == 5)
				{
					R = 255;
					G = 255;
					B = 0;
					bool5 = false;
					cout << "s" << endl;
					SDL_Surface *tmpSurface = IMG_Load("i3.png");
					playerTexture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
					SDL_FreeSurface(tmpSurface);
				}
				if (color == 6)
				{
					R = 0;
					G = 255;
					B = 255;
					bool6 = false;
					cout << "a" << endl;
					SDL_Surface *tmpSurface = IMG_Load("i4.png");
					playerTexture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
					SDL_FreeSurface(tmpSurface);
				}
				if (color == 7)
				{
					R = 255;
					G = 0;
					B = 255;
					bool7 = false;
					cout << "d" << endl;
					SDL_Surface *tmpSurface = IMG_Load("d4.png");
					playerTexture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
					SDL_FreeSurface(tmpSurface);
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
					

					cout << "perdiste el ritmo" << endl;
					loop = false;

					textSurface = nullptr;
					text = nullptr;

					SDL_Surface *textSurface = TTF_RenderText_Solid(font, "No seguiste el ritmo", negro);
					text = SDL_CreateTextureFromSurface(renderer, textSurface);
					SDL_FreeSurface(textSurface);

					textPerdiste = true;


				}
				if (Keys[SDL_SCANCODE_UP] && bool0 == false && loop == true)
				{

					bool0 = true;
					cout << "seguiste el ritmo" << endl;
					loop = false;


					SDL_Surface *textSurface = TTF_RenderText_Solid(font, "Seguiste el ritmo", blanco);
					text = SDL_CreateTextureFromSurface(renderer, textSurface);
					SDL_FreeSurface(textSurface);

				}


				if (Keys[SDL_SCANCODE_DOWN] && bool1 == true && loop == true)
				{
					

					cout << "perdiste el ritmo" << endl;
					loop = false;
					
					textSurface = nullptr;
					text = nullptr;

					SDL_Surface *textSurface = TTF_RenderText_Solid(font, "No seguiste el ritmo", blanco);
					text = SDL_CreateTextureFromSurface(renderer, textSurface);
					SDL_FreeSurface(textSurface);

					textPerdiste = true;


				}
				if (Keys[SDL_SCANCODE_DOWN] && bool1 == false && loop == true)
				{

					bool1 = true;
					cout << "seguiste el ritmo" << endl;
					loop = false;

					SDL_Surface *textSurface = TTF_RenderText_Solid(font, "Seguiste el ritmo", negro);
					text = SDL_CreateTextureFromSurface(renderer, textSurface);
					SDL_FreeSurface(textSurface);
				}



				if (Keys[SDL_SCANCODE_LEFT] && bool2 == true && loop == true)
				{
					

					cout << "perdiste el ritmo" << endl;
					loop = false;

					textSurface = nullptr;
					text = nullptr;

					SDL_Surface *textSurface = TTF_RenderText_Solid(font, "No seguiste el ritmo", rojo);
					text = SDL_CreateTextureFromSurface(renderer, textSurface);
					SDL_FreeSurface(textSurface);

					textPerdiste = true;


				}
				if (Keys[SDL_SCANCODE_LEFT] && bool2 == false && loop == true)
				{

					bool2 = true;
					cout << "seguiste el ritmo" << endl;
					loop = false;

					SDL_Surface *textSurface = TTF_RenderText_Solid(font, "Seguiste el ritmo", cyan);
					text = SDL_CreateTextureFromSurface(renderer, textSurface);
					SDL_FreeSurface(textSurface);

				}


				if (Keys[SDL_SCANCODE_RIGHT] && bool3 == true && loop == true)
				{
					

					cout << "perdiste el ritmo" << endl;
					loop = false;

					textSurface = nullptr;
					text = nullptr;

					SDL_Surface *textSurface = TTF_RenderText_Solid(font, "No seguiste el ritmo", verde);
					text = SDL_CreateTextureFromSurface(renderer, textSurface);
					SDL_FreeSurface(textSurface);

					textPerdiste = true;


				}
				if (Keys[SDL_SCANCODE_RIGHT] && bool3 == false && loop == true)
				{

					bool3 = true;
					cout << "seguiste el ritmo" << endl;
					loop = false;

					SDL_Surface *textSurface = TTF_RenderText_Solid(font, "Seguiste el ritmo", magenta);
					text = SDL_CreateTextureFromSurface(renderer, textSurface);
					SDL_FreeSurface(textSurface);
				}


				if (Keys[SDL_SCANCODE_W] && bool4 == true && loop == true)
				{
					

					cout << "perdiste el ritmo" << endl;
					loop = false;

					textSurface = nullptr;
					text = nullptr;

					SDL_Surface *textSurface = TTF_RenderText_Solid(font, "No seguiste el ritmo", azul);
					text = SDL_CreateTextureFromSurface(renderer, textSurface);
					SDL_FreeSurface(textSurface);

					textPerdiste = true;



				}
				if (Keys[SDL_SCANCODE_W] && bool4 == false && loop == true)
				{

					bool4 = true;
					cout << "seguiste el ritmo" << endl;
					loop = false;

					SDL_Surface *textSurface = TTF_RenderText_Solid(font, "Seguiste el ritmo", amarillo);
					text = SDL_CreateTextureFromSurface(renderer, textSurface);
					SDL_FreeSurface(textSurface);
				}



				if (Keys[SDL_SCANCODE_S] && bool5 == true && loop == true)
				{
					

					cout << "perdiste el ritmo" << endl;
					loop = false;

					textSurface = nullptr;
					text = nullptr;

					SDL_Surface *textSurface = TTF_RenderText_Solid(font, "No seguiste el ritmo", amarillo);
					text = SDL_CreateTextureFromSurface(renderer, textSurface);
					SDL_FreeSurface(textSurface);

					textPerdiste = true;


				}
				if (Keys[SDL_SCANCODE_S] && bool5 == false && loop == true)
				{

					bool5 = true;
					cout << "seguiste el ritmo" << endl;
					loop = false;

					SDL_Surface *textSurface = TTF_RenderText_Solid(font, "Seguiste el ritmo", azul);
					text = SDL_CreateTextureFromSurface(renderer, textSurface);
					SDL_FreeSurface(textSurface);


				}


				if (Keys[SDL_SCANCODE_A] && bool6 == true && loop == true)
				{
					

					cout << "perdiste el ritmo" << endl;
					loop = false;

					textSurface = nullptr;
					text = nullptr;

					SDL_Surface *textSurface = TTF_RenderText_Solid(font, "No seguiste el ritmo", cyan);
					text = SDL_CreateTextureFromSurface(renderer, textSurface);
					SDL_FreeSurface(textSurface);

					textPerdiste = true;


				}
				if (Keys[SDL_SCANCODE_A] && bool6 == false && loop == true)
				{

					bool6 = true;
					cout << "seguiste el ritmo" << endl;
					loop = false;

					SDL_Surface *textSurface = TTF_RenderText_Solid(font, "Seguiste el ritmo", rojo);
					text = SDL_CreateTextureFromSurface(renderer, textSurface);
					SDL_FreeSurface(textSurface);

				}



				if (Keys[SDL_SCANCODE_D] && bool7 == true && loop == true)
				{

					cout << "perdiste el ritmo" << endl;
					loop = false;

					textSurface = nullptr;
					text = nullptr;

					SDL_Surface *textSurface = TTF_RenderText_Solid(font, "No seguiste el ritmo", magenta);
					text = SDL_CreateTextureFromSurface(renderer, textSurface);
					SDL_FreeSurface(textSurface);

					textPerdiste = true;

				}
				if (Keys[SDL_SCANCODE_D] && bool7 == false && loop == true)
				{

					bool7 = true;
					cout << "seguiste el ritmo" << endl;
					loop = false;

					SDL_Surface *textSurface = TTF_RenderText_Solid(font, "Seguiste el ritmo", verde);
					text = SDL_CreateTextureFromSurface(renderer, textSurface);
					SDL_FreeSurface(textSurface);

				}
			}

			if ((timer == tempo - 1) && (bool0 == false || bool1 == false || bool2 == false || bool3 == false || bool4 == false || bool5 == false || bool6 == false || bool7 == false))
			{
				cout << "no aguantaste el ritmo" << endl;

				textSurface = nullptr;
				text = nullptr;

				SDL_Surface *textSurface = TTF_RenderText_Solid(font, "No aguantaste el ritmo", transparente);
				text = SDL_CreateTextureFromSurface(renderer, textSurface);
				SDL_FreeSurface(textSurface);

				
				textPerdiste = true;

			}

			if (tempo <= 100)
			{
				
				cout << "ganaste" << endl;

				SDL_Surface *textSurface = TTF_RenderText_Solid(font, "Tienes un gran ritmo", transparente);
				text = SDL_CreateTextureFromSurface(renderer, textSurface);
				SDL_FreeSurface(textSurface);

				textPerdiste = true;
			}
		}
		else
		{
			if (Keys[SDL_SCANCODE_Z])
			{
				inicio = true;
				timer = tempo;

			}
			if (Keys[SDL_SCANCODE_X])
			{
				gameOver = -1;
			}

			if (SDL_PollEvent(&event))
			{
				


				typeEvent = event.type;
				if (typeEvent == SDL_QUIT)
				{
					gameOver = -1;
				}
				if (typeEvent == SDL_KEYDOWN)
				{
					if (Keys[SDL_SCANCODE_ESCAPE])
					{
						gameOver = -1;
					}
				}
			}
		}


		SDL_SetRenderDrawColor(renderer, R, G, B, 0);
		SDL_RenderClear(renderer);
		if (inicio == true)
		{
			SDL_RenderCopy(renderer, playerTexture, NULL, &destR);
			SDL_RenderCopy(renderer, text, NULL, &textRect);

		}
		else
		{
			SDL_RenderCopy(renderer, InicioTexture, NULL, &inicioR);			
		}

		if (inicio == true && textPerdiste == true)
		{
			SDL_RenderCopy(renderer, text, NULL, &textRect);
			
			textPerdiste = false;
			restart = true;
		}

		SDL_RenderPresent(renderer);

		if (restart == true)
		{
			inicio = false;
			restart = false;
			
			SDL_Delay(3000);
		}
	}
	
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_DestroyTexture(text);
	SDL_Quit();

	

	
	return 0;
}