// ----------------------------------------------------
// File         : game_base.h
// Author       : MAI ZHICONG
// Summary      : game base class
// Update Msg   : create file : 2024/08/14 2:20
// ----------------------------------------------------

#pragma once

//TODO temp
using uint8 = uint8_t;

// forward declaration(前方宣言)
class SDL_Window;

using GameWindow = SDL_Window;

class GameBase
{
public:
    GameBase();
    GameBase(const char* title,int width,int height);
    ~GameBase();

protected:
    virtual void Initialize()   = 0;
    virtual void UpdateGame()   = 0;
    virtual void EndGame()      = 0;

private:
    void initSDLLib();
    void createGameWindow(const char* title, int width, int height);
private:
    GameWindow* _mainGameWindow;    // Game main window
    uint8 _bIsInitialized : 1;      // Is game initialized?
};