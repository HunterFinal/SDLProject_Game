// ----------------------------------------------------
// File         : game_base.h
// Author       : MAI ZHICONG
// Summary      : game base class
// Update Msg   : create file : 2024/08/14 2:20
// ----------------------------------------------------
#pragma once

#include "m_type_define.h"

#include "IGame.h"

// forward declaration(�O���錾)
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
    virtual void processInput()     = 0;    // �C���v�b�g����
    virtual void updateMainLogic()  = 0;    // ���C�����W�b�N����
    virtual void render()           = 0;    // ��ʂɕ`��

private:
    // SDL���C�u������������
    void initSDLLib();
    // ���C���Q�[���E�C���h�E�쐬
    void createGameWindow(const char* title, int width, int height);

protected:
    GameWindow* _mainGameWindow;    // Game main window
    uint8 _bIsInitialized : 1;      // is game initialized?
    uint8 _bIsRunning : 1;          // is game running?
};