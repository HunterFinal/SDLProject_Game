#pragma once

// ���C�u�������J��
#pragma comment(lib,"Library/SDL2.lib")
#pragma comment(lib,"Library/SDL2main.lib")

#include "SDL.h"

#include "shooter_2D.h"

int main(int argc, char** argv)
{
	
	IGame* game = new M2DShooter(1920,1080);

	// �Q�[���̏�����������������X�V����
	if(game->InitializeGame())
	{
		// �Q�[���X�V����
		game->UpdateGame();
	}
	// �Q�[���I������
	game->EndGame();

	// �ꎞ��~
	{
		system("pause");
	}

	delete game;

	return 0;
}