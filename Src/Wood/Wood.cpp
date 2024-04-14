// ���c
#include "DxLib.h"
#include "../Scene/Scene.h"
#include "Wood.h"
#include "../Collision/Collision.h"

Wood::Wood()
{
	// �؂̉摜�n���h��
	WoodImgHandle = 0;

	for (int WoodIndex = 0; WoodIndex < WOOD_MAX_NUM; WoodIndex++)
	{
		// �؂̍��W
		WoodPosX[WoodIndex] = WoodPosY[WoodIndex] = 0;
	}
	// �؂̍��̉摜�n���h��
	WoodStandImgHandle = 0;

	// �؂̍��̍��W
	WoodStandPosX = WoodStandPosY = 0;

	// �}�E�X�̍��W
	MouseX = MouseY = 0;

	// �J�E���g�ϐ�
	CountNum = 0;
}
Wood::~Wood() { Fin(); }

//�v���C�V�[���̏�����
void Wood::Init()
{
	// �؂̉摜�n���h��
	WoodImgHandle = LoadGraph(WOOD_IMG_PATH);

	for (int WoodIndex = 0; WoodIndex < WOOD_MAX_NUM; WoodIndex++)
	{
		// �؂̍��W
		WoodPosX[WoodIndex] = WINDOW_WIDTH / 2;
		WoodPosY[WoodIndex] = WINDOW_HEIGHT - 156 - 138 * WoodIndex;
	}
	// �؂̍��̉摜�n���h��
	WoodStandImgHandle = LoadGraph(WOODSTAND_IMG_PATH);

	// �؂̍��̍��W
	WoodStandPosX = WINDOW_WIDTH / 2;
	WoodStandPosY = WINDOW_HEIGHT - 40;

	// �}�E�X�̍��W
	MouseX = MouseY = 0;

	// �J�E���g�ϐ�
	CountNum = 0;
}

//�v���C�V�[���ʏ폈��
void Wood::Step()
{
	// �}�E�X�̍��W���擾
	GetMousePoint(&MouseX, &MouseY);

	// ���E��ʃN���b�N����
	ClickLR();
}

//�v���C�V�[���`�揈��
void Wood::Draw()
{
	for (int WoodIndex = 0; WoodIndex < WOOD_MAX_NUM; WoodIndex++)
	{
		// �؂̉摜�`��
		DrawRotaGraph(WoodPosX[WoodIndex], WoodPosY[WoodIndex], 2.0f, 0.0f, WoodImgHandle, true, false);
	}
	// �؂̍��̉摜�`��
	DrawRotaGraph(WoodStandPosX, WoodStandPosY, 2.0f, 0.0f, WoodStandImgHandle, true, false);
}

//�v���C�V�[���I������
void Wood::Fin()
{
	// �؂̉摜�n���h��
	DeleteGraph(WoodImgHandle);

	for (int WoodIndex = 0; WoodIndex < WOOD_MAX_NUM; WoodIndex++)
	{
		// �؂̍��W
		WoodPosX[WoodIndex] = WoodPosY[WoodIndex] = 0;
	}
	// �؂̍��̉摜�n���h��
	DeleteGraph(WoodStandImgHandle);

	// �؂̍��̍��W
	WoodStandPosX = WoodStandPosY = 0;

	// �}�E�X�̍��W
	MouseX = MouseY = 0;

	// �J�E���g�ϐ�
	CountNum = 0;
}

// �E�����ɖ؂����
void Wood::WoodMoveRight()
{
	// WoodPosX[0]���E�Ɉړ�������
	if (WoodPosX[0] <= WINDOW_WIDTH + WOOD_SIZE_W)
	{
		// WoodPosX[0]���E�Ɉړ�������
		WoodPosX[0] += 200;
	}

	if (WoodPosY[1] < WINDOW_HEIGHT - 166)
	{
		// ���̑��̖؂����ɂ��炷
		WoodPosY[1] += 40;
		WoodPosY[2] += 40;
		WoodPosY[3] += 40;
		WoodPosY[4] += 40;
		WoodPosY[5] += 40;
	}

	if (WoodPosX[0] >= WINDOW_WIDTH + WOOD_SIZE_W && WoodPosY[1] >= WINDOW_HEIGHT - 166)
	{
		// �؂̍��W�̍Đݒ�
		ResetWoodPos();
	}
}

// �������ɖ؂����
void Wood::WoodMoveLeft()
{
	// WoodPosX[0]���E�Ɉړ�������
	if (WoodPosX[0] >= 0)
	{
		// WoodPosX[0]���E�Ɉړ�������
		WoodPosX[0] -= 200;
	}

	if (WoodPosY[1] < WINDOW_HEIGHT - 166)
	{
		// ���̑��̖؂����ɂ��炷
		WoodPosY[1] += 40;
		WoodPosY[2] += 40;
		WoodPosY[3] += 40;
		WoodPosY[4] += 40;
		WoodPosY[5] += 40;
	}

	if (WoodPosX[0] <= 0 && WoodPosY[1] >= WINDOW_HEIGHT - 166)
	{
		// �؂̍��W�̍Đݒ�
		ResetWoodPos();
	}
}

// �؂̍��W�̍Đݒ�
void Wood::ResetWoodPos()
{
	for (int WoodIndex = 0; WoodIndex < WOOD_MAX_NUM; WoodIndex++)
	{
		// �؂̍��W�Đݒ�
		WoodPosX[WoodIndex] = WINDOW_WIDTH / 2;
		WoodPosY[WoodIndex] = WINDOW_HEIGHT - 156 - 138 * WoodIndex;
	}
}

// ���E��ʃN���b�N����
void Wood::ClickLR()
{
	// �����Ƀ}�E�X�J�[�\��������Ƃ�
	if (Collision::Rect_Dot(0, 0, WINDOW_WIDTH / 2, WINDOW_HEIGHT, MouseX, MouseY))
	{
		// ���N���b�N��������Ă����
		if (IsMouseDown(MOUSE_INPUT_LEFT))
		{
			CountNum++;
			if (CountNum < 5)
			{
				WoodMoveRight();
			}
		}
		else
		{
			CountNum = 0;
			// �؂̍��W�̍Đݒ�
			ResetWoodPos();
		}
	}

	// �����Ƀ}�E�X�J�[�\��������Ƃ�
	if (Collision::Rect_Dot(WINDOW_WIDTH / 2, 0, WINDOW_WIDTH / 2, WINDOW_HEIGHT, MouseX, MouseY))
	{
		// ���N���b�N��������Ă����
		if (IsMouseDown(MOUSE_INPUT_LEFT))
		{
			CountNum++;
			if (CountNum < 5)
			{
				WoodMoveLeft();
			}
		}
		else
		{
			CountNum = 0;
			// �؂̍��W�̍Đݒ�
			ResetWoodPos();
		}
	}

	if (IsMouseClick(MOUSE_INPUT_LEFT))
	{
		Score += 1;
	}
}
