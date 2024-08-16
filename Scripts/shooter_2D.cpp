#include "shooter_2D.h"

#include "SDL.h"    // include SDL_Renderer and SDL_Event

#include "window_params.h"

M2DShooter::M2DShooter()
    : GameBase("M2DShooter",GAME_DEFAULT_WIDTH,GAME_DEFAULT_HEIGHT)
    , _pRenderer(nullptr)
{
}

M2DShooter::M2DShooter(int width, int height)
    : GameBase("M2DShooter",width,height)
    , _pRenderer(nullptr)
{
}

M2DShooter::~M2DShooter()
{
}

// TODO need more implementation
bool M2DShooter::InitializeGame()
{
    // TODO temp code
    _pRenderer = SDL_CreateRenderer(
        _mainGameWindow,
        -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
        );

    // 初期化失敗
    if(!_pRenderer)
    {
        return false;
    }

    _bIsInitialized = true;
    _bIsRunning = true;

    return _bIsInitialized && _bIsRunning;
}

void M2DShooter::UpdateGame()
{
    processInput();
    updateMainLogic();
    render();
}

void M2DShooter::EndGame()
{
    // 初期化されていない場合は実行しない
    if(!_bIsInitialized)
        return;

    _bIsInitialized = false;

    if(_pRenderer)
    {
        SDL_DestroyRenderer(_pRenderer);
    }

}

void M2DShooter::processInput()
{
}

void M2DShooter::updateMainLogic()
{
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
        switch(event.type)
        {
            // SDL_QUIT
            case SDL_QUIT:
            {
                _bIsRunning = false;
                break;
            }
        }
    }
}

void M2DShooter::render()
{
    // TODO temp code
    // レンダラーがないと描画しない
    if(!_pRenderer)
        return;

    /*
        TODO:描画するステップ
        1:バックバッファを単色でクリアする（塗りつぶす）
        2:シーンを描画
        3:フロントとバックを交換
    */

   // 描画色を指定する
    SDL_SetRenderDrawColor(
        _pRenderer,
        0,    // R
        0,    // G
        255,      // B
        255    // A    
    );


    // バックバッファを設定された描画色でクリアする
    SDL_RenderClear(_pRenderer);
    
    // 次に描画したいものの色を設定
    SDL_SetRenderDrawColor(
        _pRenderer,
        255,    // R
        255,    // G
        255,      // B
        255    // A    
    );
    const int THICKNESS = 15;
    SDL_Rect wall1
    {
        0,
        0,
        1920,
        THICKNESS
    };

    SDL_Rect ball
    {
        960 - THICKNESS / 2,
        540 - THICKNESS / 2,
        THICKNESS,
        THICKNESS
    };

    // TODO need implement
    // シーンを描画
    SDL_RenderFillRect(_pRenderer,&wall1);

    SDL_RenderFillRect(_pRenderer,&ball);

    // フロントバッファとバックバッファを交換
    SDL_RenderPresent(_pRenderer);
}
