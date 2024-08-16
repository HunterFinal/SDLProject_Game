// ----------------------------------------------------
// File         : IGame.h
// Author       : MAI ZHICONG
// Summary      : Game Interface
// Update Msg   : create file : 2024/08/14 19:04
// ----------------------------------------------------

#pragma once

class IGame
{
public:
    // Initialize game
    virtual bool InitializeGame()   = 0;
    // Update game main loop
    virtual void UpdateGame()       = 0;
    // Terminate game
    virtual void EndGame()          = 0;
    // Is game running?
    virtual bool IsRunning()        = 0;

public:
    virtual ~IGame(){}
};
