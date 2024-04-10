#include "DxLib.h"
#include "Scene.h"
#include "ScenePlay.h"

ScenePlay::ScenePlay()
{
	// �v���C�w�i�n���h��
	PlayBGHandle = 0;

	for (int WoodIndex = 0; WoodIndex < WOOD_MAX_NUM; WoodIndex++)
	{
		// �؂̉摜�n���h��
		WoodImgHandle[WoodIndex] = 0;

		// �؂̍��W
		WoodPosX[WoodIndex] = WoodPosY[WoodIndex] = 0;
	}

	for (int TwigIndex = 0; TwigIndex < TWIG_MAX_NUM; TwigIndex++)
	{
		// �}�̉摜�n���h��
		TwigImgHandle[TwigIndex] = 0;

		// �}�̍��W
		TwigPosX[TwigIndex] = TwigPosY[TwigIndex] = 0;
	}
}
ScenePlay::~ScenePlay() { FinPlay(); }

//�v���C�V�[���̏�����
void ScenePlay::InitPlay()
{
	// �v���C�w�i�n���h��
	PlayBGHandle = LoadGraph(PLAY_BG_PATH);

	for (int WoodIndex = 0; WoodIndex < WOOD_MAX_NUM; WoodIndex++)
	{
		// �؂̉摜�n���h��
		WoodImgHandle[WoodIndex] = LoadGraph(WOOD_IMG_PATH);

		// �؂̍��W
		WoodPosX[WoodIndex] = WoodPosY[WoodIndex] = 0;
	}

	for (int TwigIndex = 0; TwigIndex < TWIG_MAX_NUM; TwigIndex++)
	{
		// �}�̉摜�n���h��
		TwigImgHandle[TwigIndex] = LoadGraph(TWIG_IMG_PATH);

		// �}�̍��W
		TwigPosX[TwigIndex] = TwigPosY[TwigIndex] = 0;
	}

	g_CurrentSceneID = SCENE_ID_LOOP_PLAY;
}

//�v���C�V�[���ʏ폈��
void ScenePlay::StepPlay()
{

	// Enter����������
	if (InputKey::Push(KEY_INPUT_RETURN))
	{
		// �v���C�V�[�����I������
		FinPlay();
	}
}

//�v���C�V�[���`�揈��
void ScenePlay::DrawPlay()
{
	// �^�C�g���w�i�`��
	DrawGraph(0, 0, PlayBGHandle, true);

	for (int WoodIndex = 0; WoodIndex < WOOD_MAX_NUM; WoodIndex++)
	{
		// �؂̉摜�n���h��
		DrawRotaGraph(WoodPosX[WoodIndex], WoodPosY[WoodIndex] * WoodIndex + WOOD_SIZE / 2, 1.0f, 0.0f, false, false);
	}

	for (int TwigIndex = 0; TwigIndex < TWIG_MAX_NUM; TwigIndex++)
	{
		// �}�̉摜�n���h��
		TwigImgHandle[TwigIndex] = LoadGraph(TWIG_IMG_PATH);

		// �}�̍��W
		TwigPosX[TwigIndex] = TwigPosY[TwigIndex] = 0;
	}
}

//�v���C�V�[���I������
void ScenePlay::FinPlay()
{
	// �^�C�g���w�i�n���h��
	DeleteGraph(PlayBGHandle);

	// �N���A�V�[���Ɉړ�
	g_CurrentSceneID = SCENE_ID_INIT_CLEAR;
}
