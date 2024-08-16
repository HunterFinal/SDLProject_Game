#pragma once

// ���C�u�������J��
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

	// �Q�[���̏�����������������X�V����
	if(game->InitializeGame())
	{
		while(game->IsRunning())
		{
			// Timer�X�V
			t.UpdateTime();
			// �Q�[���X�V����
			game->UpdateGame();
		}
	}
	// �Q�[���I������
	game->EndGame();

	//// �ꎞ��~
	//{
	//	system("pause");
	//}

	//delete game;

	return 0;
}