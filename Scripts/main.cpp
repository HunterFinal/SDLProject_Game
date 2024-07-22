#include <iostream>
#include "SDL.h"

int main(int argc, char** argv)
{
	
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		std::cout << SDL_GetError() << std::endl;
		return 1;
	}

	SDL_Window* window = nullptr;
	window = SDL_CreateWindow("Test", 1600,0, 640, 480, SDL_WINDOW_SHOWN);

	if (window == nullptr)
	{
		std::cout << SDL_GetError() << std::endl;
		return 1;
	}


	system("pause");



	SDL_Quit();


	return 0;
}