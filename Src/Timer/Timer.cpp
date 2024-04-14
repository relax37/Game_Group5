// ���c
#include "DxLib.h"
#include "../Scene/Scene.h"
#include "Timer.h"
#include "../InputMouse/InputMouse.h"

Timer::Timer()
{
	// �^�C�}�[�̍��W
	TimerPosX = TimerPosY = 0;

	// �^�C�}�[�̃T�C�Y
	TimerWidth = 0;
	TimerHeight = 0;

	// �J�E���g�ϐ�
	CountNum = 0;
}
Timer::~Timer() { Fin(); }

// Timer�̏�����
void Timer::Init()
{
	// �^�C�}�[�̍��W
	TimerPosX = WINDOW_WIDTH / 2 - 200;
	TimerPosY = 75;

	// �^�C�}�[�̃T�C�Y
	TimerWidth = 200;
	TimerHeight = 70;

	// �J�E���g�ϐ�
	CountNum = 0;
}

// Timer�ʏ폈��
void Timer::Step()
{
	TimerWidth -= 2;

	// ���N���b�N��������Ă����
	if (IsMouseDown(MOUSE_INPUT_LEFT))
	{
			CountNum++;
		if (CountNum < 4)
		{
			TimerWidth += 8;
		}	
	}
	else 
	{
		CountNum = 0;
	}

	if (TimerWidth >= 400)
	{
		TimerWidth = 400;
	}

	if (TimerWidth <= 0)
	{
		// �Q�[���I�[�o�[�V�[���Ɉړ�
		g_CurrentSceneID = SCENE_ID_FIN_PLAY;
	}
}

// Timer�`�揈��
void Timer::Draw()
{
	// �^�C�}�[�w�i
	DrawBox(WINDOW_WIDTH / 2 - 205, 70, WINDOW_WIDTH / 2 + 205, 150, GetColor(230, 152, 101), true);
	DrawBox(WINDOW_WIDTH / 2 - 200, 75, WINDOW_WIDTH / 2 + 200, 145, GetColor(79, 41, 32), true);

	// �^�C�}�[�Q�[�W
	DrawBox(TimerPosX, TimerPosY, TimerPosX + TimerWidth, TimerPosY + TimerHeight, GetColor(255, 0, 0), true);
}

// Timer�I������
void Timer::Fin()
{
	// �^�C�}�[�̍��W
	TimerPosX = 0;
	TimerPosY = 0;

	// �^�C�}�[�̃T�C�Y
	TimerWidth = 0;
	TimerHeight = 0;

	// �J�E���g�ϐ�
	CountNum = 0;
}