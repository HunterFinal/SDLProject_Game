#pragma once

// ���C�u�������J��
#pragma comment(lib,"Library/SDL2.lib")
#pragma comment(lib,"Library/SDL2main.lib")

#include "SDL.h"

#include "shooter_2D.h"

#include "frameworkhelper.h"

#include <iostream>

int main(int argc, char** argv)
{
	using MFWK = MFramework::Framework; 
	MFWK::CreateInstance();
	MFWK::GetInstance()->InitFramework();

	IGame* game = new M2DShooter(1920,1080);


	// �Q�[���̏�����������������X�V����
	if(game->InitializeGame())
	{
		while(game->IsRunning())
		{
			MFWK::GetInstance()->UpdateFramework();
			// �Q�[���X�V����
			game->UpdateGame();
		}
	}
	// �Q�[���I������
	game->EndGame();

	MFWK::GetInstance()->ShutDownFramework();
	MFWK::ReleaseInstance();

	//// �ꎞ��~
	//{
	//	system("pause");
	//}

	//delete game;

	return 0;
}