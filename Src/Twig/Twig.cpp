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

	// �J�E���g�ϐ�2
	CountNum2 = 0;
}
Twig::~Twig() { Fin(); }

//�v���C�V�[���̏�����
void Twig::Init()
{
	// �}�̉摜�n���h��
	TwigImgHandle = LoadGraph(TWIG_IMG_PATH);

	for (int TwigIndex = 0; TwigIndex < TWIG_LEFT_MAX_NUM; TwigIndex++)
	{
		Random = GetRand(RANDOM_NUM);

		// �`�攻��
		if (Random >= 1)
		{
			isDrawLeft[TwigIndex] = true;
		}
		else
		{
			isDrawLeft[TwigIndex] = false;
		}

		// �}��X���W
		TwigLeftPosX[TwigIndex] = WINDOW_WIDTH / 3 + 53;
	}

	// �}��Y���W
	TwigLeftPosY[0] = (WINDOW_HEIGHT - 156) - 69 * 3;
	TwigLeftPosY[1] = (WINDOW_HEIGHT - 156) - 69 * 4;
	TwigLeftPosY[2] = (WINDOW_HEIGHT - 156) - 69 * 9;
	TwigLeftPosY[3] = (WINDOW_HEIGHT - 156) - 69 * 10;
	TwigLeftPosY[4] = (WINDOW_HEIGHT - 156) - 69 * 11;
	TwigLeftPosY[5] = (WINDOW_HEIGHT - 156) - 69 * 12;
	TwigLeftPosY[6] = (WINDOW_HEIGHT - 156) - 69 * 13;
	TwigLeftPosY[7] = (WINDOW_HEIGHT - 156) - 69 * 14;

	for (int TwigIndex = 0; TwigIndex < TWIG_RIGHT_MAX_NUM; TwigIndex++)
	{
		Random = GetRand(4);

		// �`�攻��
		if (Random >= 1)
		{
			isDrawRight[TwigIndex] = true;
		}
		else
		{
			isDrawRight[TwigIndex] = false;
		}

		// �}��X���W
		TwigRightPosX[TwigIndex] = WINDOW_WIDTH - WINDOW_WIDTH / 3 - 48;
	}

	// �}��Y���W
	TwigRightPosY[0] = (WINDOW_HEIGHT - 156);
	TwigRightPosY[1] = (WINDOW_HEIGHT - 156) - 69;
	TwigRightPosY[2] = (WINDOW_HEIGHT - 156) - 69 * 6;
	TwigRightPosY[3] = (WINDOW_HEIGHT - 156) - 69 * 7;
	TwigRightPosY[4] = (WINDOW_HEIGHT - 156) - 69 * 16;
	TwigRightPosY[5] = (WINDOW_HEIGHT - 156) - 69 * 17;

	// �J�E���g�ϐ�
	CountNum = 0;

	// �J�E���g�ϐ�2
	CountNum2 = 0;
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

			// debug
			//DrawBox(TwigLeftPosX[TwigIndex] - 40, TwigLeftPosY[TwigIndex] - 40, TwigLeftPosX[TwigIndex] + 40, TwigLeftPosY[TwigIndex] + 40, GetColor(255, 0, 0), false);
		}
	}

	for (int TwigIndex = 0; TwigIndex < TWIG_RIGHT_MAX_NUM; TwigIndex++)
	{
		if (isDrawRight[TwigIndex] == true)
		{
			// �}�̉摜�`��
			DrawRotaGraph(TwigRightPosX[TwigIndex], TwigRightPosY[TwigIndex], 1.0f, 0.0f, TwigImgHandle, true, true);

			// debug
			//DrawBox(TwigRightPosX[TwigIndex] - 40, TwigRightPosY[TwigIndex] - 40, TwigRightPosX[TwigIndex] + 40, TwigRightPosY[TwigIndex] + 40, GetColor(255, 0, 0), false);
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

	// �J�E���g�ϐ�2
	CountNum2 = 0;
}

// �}(��)�̈ړ�����
void Twig::MoveLeftTwig()
{
	for (int TwigIndex = 0; TwigIndex < TWIG_LEFT_MAX_NUM; TwigIndex++)
	{
		if (TwigLeftPosY[TwigIndex] > WINDOW_HEIGHT - 156)
		{
			Random = GetRand(RANDOM_NUM);

			TwigLeftPosY[TwigIndex] = (WINDOW_HEIGHT - 156) - 69 * 19;

			if (Random >= 1)
			{
				isDrawLeft[TwigIndex] = true;
			}
			else
			{
				isDrawLeft[TwigIndex] = false;
			}
		}
	}
}

// �}(�E)�̈ړ�����
void Twig::MoveRightTwig()
{
	// RightTwig1
	for (int TwigIndex = 0; TwigIndex < TWIG_RIGHT_MAX_NUM; TwigIndex++)
	{
		if (TwigRightPosY[TwigIndex] > WINDOW_HEIGHT - 156)
		{
			Random = GetRand(RANDOM_NUM);

			TwigRightPosY[TwigIndex] = (WINDOW_HEIGHT - 156) - 69 * 19;

			if (Random >= 1)
			{
				isDrawRight[TwigIndex] = true;
			}
			else
			{
				isDrawRight[TwigIndex] = false;
			}
		}
	}
}

// ���E��ʃN���b�N����
void Twig::Click()
{
	// ���N���b�N��������Ă����
	if (IsMouseDown(MOUSE_INPUT_LEFT))
	{
		CountNum++;

		if (CountNum <= 3)
		{
			for (int TwigIndex = 0; TwigIndex < TWIG_LEFT_MAX_NUM; TwigIndex++)
			{
				// �}�̍��W
				TwigLeftPosY[TwigIndex] += 23;
			}

			for (int TwigIndex = 0; TwigIndex < TWIG_RIGHT_MAX_NUM; TwigIndex++)
			{
				// �}�̍��W
				TwigRightPosY[TwigIndex] += 23;
			}
		}

	}
	else
	{
		if (CountNum == 2)
		{
			for (int TwigIndex = 0; TwigIndex < TWIG_LEFT_MAX_NUM; TwigIndex++)
			{
				// �}�̍��W
				TwigLeftPosY[TwigIndex] += 23;
			}

			for (int TwigIndex = 0; TwigIndex < TWIG_RIGHT_MAX_NUM; TwigIndex++)
			{
				// �}�̍��W
				TwigRightPosY[TwigIndex] += 23;
			}
		}
		else if (CountNum == 1)
		{
			for (int TwigIndex = 0; TwigIndex < TWIG_LEFT_MAX_NUM; TwigIndex++)
			{
				// �}�̍��W
				TwigLeftPosY[TwigIndex] += 46;
			}

			for (int TwigIndex = 0; TwigIndex < TWIG_RIGHT_MAX_NUM; TwigIndex++)
			{
				// �}�̍��W
				TwigRightPosY[TwigIndex] += 46;
			}
		}
		CountNum = 0;
	}
}

// �v���C���[�Ǝ}�̓����蔻��
void Twig::Player_TwigCollision(int PlayerPosX, int PlayerPosY)
{
	for (int TwigIndex = 0; TwigIndex < TWIG_LEFT_MAX_NUM; TwigIndex++)
	{
		if (isDrawLeft[TwigIndex] == true)
		{
			if (Collision::Rect_Dot(TwigLeftPosX[TwigIndex] - 40, TwigLeftPosY[TwigIndex] - 40, 80, 80, PlayerPosX, PlayerPosY))
			{
				// �Q�[���I�[�o�[�V�[���Ɉړ�
				g_CurrentSceneID = SCENE_ID_FIN_PLAY;
			}
		}
	}

	for (int TwigIndex = 0; TwigIndex < TWIG_RIGHT_MAX_NUM; TwigIndex++)
	{
		if (isDrawRight[TwigIndex] == true)
		{
			if (Collision::Rect_Dot(TwigRightPosX[TwigIndex] - 20, TwigRightPosY[TwigIndex] - 10, 40, 20, PlayerPosX, PlayerPosY))
			{
				// �Q�[���I�[�o�[�V�[���Ɉړ�
				g_CurrentSceneID = SCENE_ID_FIN_PLAY;
			}
		}
	}
}
