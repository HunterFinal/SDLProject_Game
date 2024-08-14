// ----------------------------------------------------
// File         : shooter_2D.h
// Author       : MAI ZHICONG
// Summary      : shooter 2D game class
// Update Msg   : create file : 2024/08/14 16:10
// ----------------------------------------------------
#pragma once

#include "game_base.h"

// forward declaration(�O���錾)
struct SDL_Renderer;

// �p���ł��Ȃ��悤�ɂ���
class M2DShooter final: public GameBase
{
public:
    M2DShooter();
    M2DShooter(int width,int height);
    ~M2DShooter();

private:
    // copy disable(�R�s�[�֎~)
    M2DShooter(const M2DShooter& game) = delete;
    M2DShooter& operator=(const M2DShooter& game) = delete;

public:
    bool InitializeGame()   override;
    void UpdateGame()       override;
    void EndGame()          override;

protected:
    void processInput()     override;
    void updateMainLogic()  override;
    void render()           override;

private:
    //TODO
    SDL_Renderer* _pRenderer;   // temp back ground
    
};