#pragma once

// ライブラリを開く
#pragma comment(lib,"Library/SDL2.lib")
#pragma comment(lib,"Library/SDL2main.lib")

#include "SDL.h"

#include "shooter_2D.h"
#include "time.h"

#include <iostream>

int main(int argc, char** argv)
{
	using MSystemTimer = MSystem::MTime;
	IGame* game = new M2DShooter(1920,1080);

	MSystemTimer::CreateInstance(0.05f);
	MSystemTimer& t = MSystemTimer::GetInstance();

	// ゲームの初期化が成功したら更新処理
	if(game->InitializeGame())
	{
		while(game->IsRunning())
		{
			// Timer更新
			t.UpdateTime();
			// ゲーム更新処理
			game->UpdateGame();
		}
	}
	// ゲーム終了処理
	game->EndGame();

	//// 一時停止
	//{
	//	system("pause");
	//}

	//delete game;

	return 0;
}