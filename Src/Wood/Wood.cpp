#include "DxLib.h"
#include "../Scene/Scene.h"
#include "Wood.h"
#include "../Collision/Collision.h"

Wood::Wood()
{
	for (int WoodIndex = 0; WoodIndex < WOOD_MAX_NUM; WoodIndex++)
	{
		// �؂̉摜�n���h��
		WoodImgHandle[WoodIndex] = 0;

		// �؂̍��W
		WoodPosX[WoodIndex] = WoodPosY[WoodIndex] = 0;
	}
	// �؂̍��̉摜�n���h��
	WoodStandImgHandle = 0;

	// �؂̍��̍��W
	WoodStandPosX = WoodStandPosY = 0;

	//for (int TwigIndex = 0; TwigIndex < TWIG_MAX_NUM; TwigIndex++)
	//{
	//	// �}�̉摜�n���h��
	//	TwigImgHandle[TwigIndex] = 0;

	//	// �}�̍��W
	//	TwigPosX[TwigIndex] = TwigPosY[TwigIndex] = 0;
	//}

	MouseX = MouseY = 0;						// �}�E�X�̍��W

	isRightMove = 0;							// �E�ɓ�������
	isLeftMove = 0;								// ���ɓ�������
}
Wood::~Wood() { Fin(); }

//�v���C�V�[���̏�����
void Wood::Init()
{
	for (int WoodIndex = 0; WoodIndex < WOOD_MAX_NUM; WoodIndex++)
	{
		// �؂̉摜�n���h��
		WoodImgHandle[WoodIndex] = LoadGraph(WOOD_IMG_PATH);

		// �؂̍��W
		WoodPosX[WoodIndex] = WINDOW_WIDTH / 2;
		WoodPosY[WoodIndex] = WINDOW_HEIGHT - 166 - 138 * WoodIndex;
	}
	// �؂̍��̉摜�n���h��
	WoodStandImgHandle = LoadGraph(WOODSTAND_IMG_PATH);

	// �؂̍��̍��W
	WoodStandPosX = WINDOW_WIDTH / 2;
	WoodStandPosY = WINDOW_HEIGHT - 50;

	//for (int TwigIndex = 0; TwigIndex < TWIG_MAX_NUM; TwigIndex++)
	//{
	//	// �}�̉摜�n���h��
	//	TwigImgHandle[TwigIndex] = LoadGraph(TWIG_IMG_PATH);

	//	// �}�̍��W
	//	TwigPosX[TwigIndex] = TwigPosY[TwigIndex] = 0;
	//}

	MouseX = MouseY = 0;				// �}�E�X�̍��W

	isRightMove = false;							// �E�ɓ�������
	isLeftMove = false;								// ���ɓ�������
}

//�v���C�V�[���ʏ폈��
void Wood::Step()
{
	GetMousePoint(&MouseX, &MouseY);	// �}�E�X�̍��W���擾

	// ���E��ʃN���b�N����
	ClickLR();

	WoodMoveRight();

	WoodMoveLeft();
}

//�v���C�V�[���`�揈��
void Wood::Draw()
{
	for (int WoodIndex = 0; WoodIndex < WOOD_MAX_NUM; WoodIndex++)
	{
		// �؂̉摜�`��
		DrawRotaGraph(WoodPosX[WoodIndex], WoodPosY[WoodIndex], 2.0f, 0.0f, WoodImgHandle[WoodIndex], true, false);
	}
	// �؂̍��̉摜�`��
	DrawRotaGraph(WoodStandPosX, WoodStandPosY, 2.0f, 0.0f, WoodStandImgHandle, true, false);

	//for (int TwigIndex = 0; TwigIndex < TWIG_MAX_NUM; TwigIndex++)
	//{
	//	// �}�̉摜�n���h��
	//	TwigImgHandle[TwigIndex] = LoadGraph(TWIG_IMG_PATH);

	//	// �}�̍��W
	//	TwigPosX[TwigIndex] = TwigPosY[TwigIndex] = 0;
	//}
}

//�v���C�V�[���I������
void Wood::Fin()
{
	for (int WoodIndex = 0; WoodIndex < WOOD_MAX_NUM; WoodIndex++)
	{
		// �؂̉摜�n���h��
		DeleteGraph(WoodImgHandle[WoodIndex]);

		// �؂̍��W
		WoodPosX[WoodIndex] = WoodPosY[WoodIndex] = 0;
	}
	// �؂̍��̉摜�n���h��
	DeleteGraph(WoodStandImgHandle);

	// �؂̍��̍��W
	WoodStandPosX = WoodStandPosY = 0;

	MouseX = MouseY = 0;					// �}�E�X�̍��W

	isRightMove = 0;							// �E�ɓ�������
	isLeftMove = 0;								// ���ɓ�������
}

// �E�����ɖ؂����
void Wood::WoodMoveRight()
{
	if (isRightMove)
	{
		// Wood[0]
		if (Collision::Rect(WoodPosX[0] - WOOD_SIZE_W / 2, WoodPosY[0] - WOOD_SIZE_H / 2, WOOD_SIZE_W, WOOD_SIZE_H,
								0, WINDOW_HEIGHT - 166, WINDOW_WIDTH, WINDOW_HEIGHT))
		{
			// WoodPosX[0]���E�Ɉړ�������
			if (WoodPosX[0] < WINDOW_WIDTH + WOOD_SIZE_W)
			{
				WoodPosX[0] += 150;
			}
			// ��ʊO�ɏo����
			else
			{
				// WoodPos[0]����ԏ�Ɉړ�
				WoodPosX[0] = WINDOW_WIDTH / 2;
				WoodPosY[0] = WINDOW_HEIGHT - 166 - 138 * 5;
			}

			// ���̑��̖؂����ɂ��炷
			if (WoodPosY[1] <= WINDOW_HEIGHT - 166)
			{
				WoodPosY[1] += 30;
				WoodPosY[2] += 30;
				WoodPosY[3] += 30;
				WoodPosY[4] += 30;
				WoodPosY[5] += 30;
			}
			// �ړ����I�������isRightMove��false�ɂ���
			else
			{
				isRightMove = false;
			}
		}

		//// Wood[1]
		//if (Collision::Rect(WoodPosX[1] - WOOD_SIZE_W / 2, WoodPosY[1] - WOOD_SIZE_H / 2, WOOD_SIZE_W, WOOD_SIZE_H,
		//					0, 524, WINDOW_WIDTH, WINDOW_HEIGHT))
		//{
		//	// WoodPosX[1]���E�Ɉړ�������
		//	if (WoodPosX[1] < WINDOW_WIDTH + WOOD_SIZE_W)
		//	{
		//		WoodPosX[1] += 150;
		//	}
		//	// ��ʊO�ɏo����
		//	else
		//	{
		//		// WoodPos[1]����ԏ�Ɉړ�
		//		WoodPosX[1] = WINDOW_WIDTH / 2;
		//		WoodPosY[1] = WINDOW_HEIGHT - 166 - 138 * 5;
		//	}

		//	// ���̑��̖؂����ɂ��炷
		//	if (WoodPosY[2] <= WINDOW_HEIGHT - 166)
		//	{
		//		WoodPosY[2] += 20;
		//		WoodPosY[3] += 20;
		//		WoodPosY[4] += 20;
		//		WoodPosY[5] += 20;
		//		WoodPosY[0] += 20;
		//	}

		//	// �ړ����I�������isRightMove��false�ɂ���
		//	if (WoodPosY[1] == WINDOW_HEIGHT - 166 - 138 * 5 && WoodPosY[2] == WINDOW_HEIGHT - 166)
		//	{
		//		isRightMove = false;
		//	}
		//}
	}
}

// �������ɖ؂����
void Wood::WoodMoveLeft()
{

}

// ���E��ʃN���b�N����
void Wood::ClickLR()
{
	if (isRightMove == false)
	{
		// �����Ƀ}�E�X�J�[�\��������Ƃ�
		if (Collision::Rect_Dot(0, 0, WINDOW_WIDTH / 2, WINDOW_HEIGHT, MouseX, MouseY))
		{
			// ���N���b�N��������Ă����
			if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
			{
				isRightMove = true;
			}
			// ���N���b�N��������Ă��Ȃ����
			else
			{
				
			}
		}
	}
	

	// �����Ƀ}�E�X�J�[�\��������Ƃ�
	if (Collision::Rect_Dot(WINDOW_WIDTH / 2, 0, WINDOW_WIDTH / 2, WINDOW_HEIGHT, MouseX, MouseY))
	{
		// ���N���b�N��������Ă����
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
		{
			WoodMoveLeft();
		}
		// ���N���b�N��������Ă��Ȃ����
		else
		{
			
		}
	}
}
