#include "DxLib.h"
#include "../Scene/Scene.h"
#include "Wood.h"

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
		WoodPosY[WoodIndex] = WINDOW_HEIGHT - 166- 138 * WoodIndex;
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

	g_CurrentSceneID = SCENE_ID_LOOP_PLAY;
}

//�v���C�V�[���ʏ폈��
void Wood::Step()
{

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
}
