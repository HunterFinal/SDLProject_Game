#include "game_base.h"

#include <iostream>

#include "SDL.h"

GameBase::GameBase(const char* title, int width,int height)
    : _mainGameWindow(nullptr)
    , _bIsInitialized(0)
    , _bIsRunning(0)
{
    initSDLLib();
    createGameWindow(title,width,height);
    
}

GameBase::~GameBase()
{
    if(_mainGameWindow)
    {
        // ���C���Q�[���E�C���h�E������
        SDL_DestroyWindow(_mainGameWindow);
    }

    SDL_Quit();
}

void GameBase::initSDLLib()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		std::cout << SDL_GetError() << std::endl;
		exit(-1);
	}
}

void GameBase::createGameWindow(const char *title, int width,int height)
{
    // ���C���Q�[���E�C���h�E���쐬
    _mainGameWindow = SDL_CreateWindow( 
        title
        ,SDL_WINDOWPOS_CENTERED
        ,SDL_WINDOWPOS_CENTERED
        ,width
        ,height
        ,SDL_WINDOW_RESIZABLE
    );

    // �쐬���s������
    if(!_mainGameWindow)
    {
        std::cout << SDL_GetError() << std::endl;
        exit(-1);
    }
}
