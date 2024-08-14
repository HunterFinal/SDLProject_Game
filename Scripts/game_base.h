// ----------------------------------------------------
// File         : game_base.h
// Author       : MAI ZHICONG
// Summary      : game base class
// Update Msg   : create file : 2024/08/14 2:20
// ----------------------------------------------------
#pragma once

#include "m_type_define.h"

#include "IGame.h"

// forward declaration(前方宣言)
struct SDL_Window;

class GameBase : public IGame
{
    using GameWindow = SDL_Window;

public:
    GameBase(const char* title,int width,int height);
    virtual ~GameBase();

public:
    virtual bool InitializeGame()   = 0;
    virtual void UpdateGame()       = 0;
    virtual void EndGame()          = 0;

protected:
    virtual void processInput()     = 0;    // インプット処理
    virtual void updateMainLogic()  = 0;    // メインロジック処理
    virtual void render()           = 0;    // 画面に描画

private:
    // SDLライブラリを初期化
    void initSDLLib();
    // メインゲームウインドウ作成
    void createGameWindow(const char* title, int width, int height);

protected:
    GameWindow* _mainGameWindow;    // Game main window
    uint8 _bIsInitialized : 1;      // is game initialized?
    uint8 _bIsRunning : 1;          // is game running?
};