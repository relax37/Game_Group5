// ���c
#include "DxLib.h"
#include "../Scene/Scene.h"
#include "Twig.h"
#include "../Collision/Collision.h"

Twig::Twig()
{
	// �}�̉摜�n���h��
	TwigImgHandle = 0;

	for (int TwigIndex = 0; TwigIndex < TWIG_LEFT_MAX_NUM; TwigIndex++)
	{
		// �}�̍��W
		TwigLeftPosX[TwigIndex] = 0;
		TwigLeftPosY[TwigIndex] = 0;

		// �`�攻��
		isDrawLeft[TwigIndex] = 0;
	}

	for (int TwigIndex = 0; TwigIndex < TWIG_RIGHT_MAX_NUM; TwigIndex++)
	{
		// �}�̍��W
		TwigRightPosX[TwigIndex] = 0;
		TwigRightPosY[TwigIndex] = 0;

		// �`�攻��
		isDrawRight[TwigIndex] = 0;
	}

	// �����_���ϐ�
	Random = 0;

	// �J�E���g�ϐ�
	CountNum = 0;
}
Twig::~Twig() { Fin(); }

//�v���C�V�[���̏�����
void Twig::Init()
{
	// �}�̉摜�n���h��
	TwigImgHandle = LoadGraph(TWIG_IMG_PATH);

	for (int TwigIndex = 0; TwigIndex < TWIG_LEFT_MAX_NUM; TwigIndex++)
	{
		Random = GetRand(1);

		// �`�攻��
		if (Random == 1)
		{
			isDrawLeft[TwigIndex] = true;
		}
		else
		{
			isDrawLeft[TwigIndex] = false;
		}
	}

	// �}�̍��W
	TwigLeftPosX[0] = WINDOW_WIDTH / 3 + 50;
	TwigLeftPosY[0] = (WINDOW_HEIGHT - 156) - 69 * 3;

	TwigLeftPosX[1] = WINDOW_WIDTH / 3 + 50;
	TwigLeftPosY[1] = (WINDOW_HEIGHT - 156) - 69 * 4;

	TwigLeftPosX[2] = WINDOW_WIDTH / 3 + 50;
	TwigLeftPosY[2] = (WINDOW_HEIGHT - 156) - 69 * 9;

	TwigLeftPosX[3] = WINDOW_WIDTH / 3 + 50;
	TwigLeftPosY[3] = (WINDOW_HEIGHT - 156) - 69 * 10;

	TwigLeftPosX[4] = WINDOW_WIDTH / 3 + 50;
	TwigLeftPosY[4] = (WINDOW_HEIGHT - 156) - 69 * 11;

	TwigLeftPosX[5] = WINDOW_WIDTH / 3 + 50;
	TwigLeftPosY[5] = (WINDOW_HEIGHT - 156) - 69 * 12;

	TwigLeftPosX[6] = WINDOW_WIDTH / 3 + 50;
	TwigLeftPosY[6] = (WINDOW_HEIGHT - 156) - 69 * 13;

	TwigLeftPosX[7] = WINDOW_WIDTH / 3 + 50;
	TwigLeftPosY[7] = (WINDOW_HEIGHT - 156) - 69 * 14;

	for (int TwigIndex = 0; TwigIndex < TWIG_RIGHT_MAX_NUM; TwigIndex++)
	{
		Random = GetRand(1);

		// �`�攻��
		if (Random == 1)
		{
			isDrawRight[TwigIndex] = true;
		}
		else
		{
			isDrawRight[TwigIndex] = false;
		}
	}

	// �}�̍��W
	TwigRightPosX[0] = WINDOW_WIDTH - WINDOW_WIDTH / 3 - 50;
	TwigRightPosY[0] = (WINDOW_HEIGHT - 156);

	TwigRightPosX[1] = WINDOW_WIDTH - WINDOW_WIDTH / 3 - 50;
	TwigRightPosY[1] = (WINDOW_HEIGHT - 156) - 69;

	TwigRightPosX[2] = WINDOW_WIDTH - WINDOW_WIDTH / 3 - 50;
	TwigRightPosY[2] = (WINDOW_HEIGHT - 156) - 69 * 6;

	TwigRightPosX[3] = WINDOW_WIDTH - WINDOW_WIDTH / 3 - 50;
	TwigRightPosY[3] = (WINDOW_HEIGHT - 156) - 69 * 7;

	TwigRightPosX[4] = WINDOW_WIDTH - WINDOW_WIDTH / 3 - 50;
	TwigRightPosY[4] = (WINDOW_HEIGHT - 156) - 69 * 16;

	TwigRightPosX[5] = WINDOW_WIDTH - WINDOW_WIDTH / 3 - 50;
	TwigRightPosY[5] = (WINDOW_HEIGHT - 156) - 69 * 17;

	// �J�E���g�ϐ�
	CountNum = 0;
}

//�v���C�V�[���ʏ폈��
void Twig::Step()
{
	// �}(��)�̈ړ�����
	MoveLeftTwig();

	// �}(�E)�̈ړ�����
	MoveRightTwig();

	// �N���b�N����
	Click();
}

//�v���C�V�[���`�揈��
void Twig::Draw()
{
	for (int TwigIndex = 0; TwigIndex < TWIG_LEFT_MAX_NUM; TwigIndex++)
	{
		if (isDrawLeft[TwigIndex] == true)
		{
			// �}�̉摜�`��
			DrawRotaGraph(TwigLeftPosX[TwigIndex], TwigLeftPosY[TwigIndex], 1.0f, 0.0f, TwigImgHandle, true, false);
		}

	}

	for (int TwigIndex = 0; TwigIndex < TWIG_RIGHT_MAX_NUM; TwigIndex++)
	{
		if (isDrawRight[TwigIndex] == true)
		{
			// �}�̉摜�`��
			DrawRotaGraph(TwigRightPosX[TwigIndex], TwigRightPosY[TwigIndex], 1.0f, 0.0f, TwigImgHandle, true, true);
		}

	}
}

//�v���C�V�[���I������
void Twig::Fin()
{
	// �}�̉摜�n���h��
	DeleteGraph(TwigImgHandle);

	for (int TwigIndex = 0; TwigIndex < TWIG_LEFT_MAX_NUM; TwigIndex++)
	{
		// �}�̍��W
		TwigLeftPosX[TwigIndex] = 0;
		TwigLeftPosY[TwigIndex] = 0;

		// �`�攻��
		isDrawLeft[TwigIndex] = 0;
	}

	for (int TwigIndex = 0; TwigIndex < TWIG_RIGHT_MAX_NUM; TwigIndex++)
	{
		// �}�̍��W
		TwigRightPosX[TwigIndex] = 0;
		TwigRightPosY[TwigIndex] = 0;

		// �`�攻��
		isDrawRight[TwigIndex] = 0;
	}

	// �����_���ϐ�
	Random = 0;

	// �J�E���g�ϐ�
	CountNum = 0;
}

// �}(��)�̈ړ�����
void Twig::MoveLeftTwig()
{
	// LeftTwig1
	for (int TwigIndex = 0; TwigIndex < TWIG_LEFT_MAX_NUM; TwigIndex++)
	{
		if (TwigLeftPosY[TwigIndex] >= WINDOW_HEIGHT - 156)
		{
			Random = GetRand(1);

			TwigLeftPosY[TwigIndex] = (WINDOW_HEIGHT - 156) - 69 * 19;

			if (Random == 1)
			{
				isDrawLeft[TwigIndex] = true;
			}
			else
			{
				isDrawLeft[TwigIndex] = false;
			}
		}
	}


	// LeftTwig2

	// LeftTwig3

	// LeftTwig4

	// LeftTwig5

	// LeftTwig6

	// LeftTwig7

	// LeftTwig8
}

// �}(�E)�̈ړ�����
void Twig::MoveRightTwig()
{
	// RightTwig1
	for (int TwigIndex = 0; TwigIndex < TWIG_RIGHT_MAX_NUM; TwigIndex++)
	{
		if (TwigRightPosY[TwigIndex] >= WINDOW_HEIGHT - 156)
		{
			Random = GetRand(1);

			TwigRightPosY[TwigIndex] = (WINDOW_HEIGHT - 156) - 69 * 19;

			if (Random == 1)
			{
				isDrawRight[TwigIndex] = true;
			}
			else
			{
				isDrawRight[TwigIndex] = false;
			}
		}
	}

	// RightTwig2

	// RightTwig3

	// RightTwig4

	// RightTwig5

	// RightTwig6
}

// ���E��ʃN���b�N����
void Twig::Click()
{
	// ���N���b�N��������Ă����
	if (IsMouseDown(MOUSE_INPUT_LEFT))
	{
		CountNum++;

		if (CountNum <= 1)
		{
			for (int TwigIndex = 0; TwigIndex < TWIG_LEFT_MAX_NUM; TwigIndex++)
			{
				// �}�̍��W
				TwigLeftPosY[TwigIndex] += 69;
			}

			for (int TwigIndex = 0; TwigIndex < TWIG_RIGHT_MAX_NUM; TwigIndex++)
			{
				// �}�̍��W
				TwigRightPosY[TwigIndex] += 69;
			}
		}
	}
	else
	{
		CountNum = 0;
	}
}
