#pragma once

// ライブラリを開く
#pragma comment(lib,"Library/SDL2.lib")
#pragma comment(lib,"Library/SDL2main.lib")

#include "SDL.h"

#include "shooter_2D.h"

int main(int argc, char** argv)
{
	
	IGame* game = new M2DShooter(1920,1080);

	// ゲームの初期化が成功したら更新処理
	if(game->InitializeGame())
	{
		// ゲーム更新処理
		game->UpdateGame();
	}
	// ゲーム終了処理
	game->EndGame();

	// 一時停止
	{
		system("pause");
	}

	delete game;

	return 0;
}