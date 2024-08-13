#include "game_base.h"

#include <iostream>

#include "SDL.h"
#include "window_params.h"

GameBase::GameBase()
    : _mainGameWindow(nullptr)
    , _bIsInitialized(0)
{
    initSDLLib();
    createGameWindow("Game",GAME_DEFAULT_WIDTH,GAME_DEFAULT_HEIGHT);
    
}

GameBase::GameBase(const char* title, int width,int height)
    : _mainGameWindow(nullptr)
    , _bIsInitialized(0)
{
    initSDLLib();
    createGameWindow(title,width,height);
    
}

GameBase::~GameBase()
{
    if(_mainGameWindow)
    {
        // ゲームウインドウを消滅
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
    // SDLウィンドウ作成
    _mainGameWindow = SDL_CreateWindow( title
                                        ,SDL_WINDOWPOS_CENTERED
                                        ,SDL_WINDOWPOS_CENTERED
                                        ,width
                                        ,height
                                        ,SDL_WINDOW_RESIZABLE);

    // ウィンドウ作成失敗したら
    if(!_mainGameWindow)
    {
        std::cout << SDL_GetError() << std::endl;
        exit(-1);
    }
}
