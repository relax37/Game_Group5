// ���c
#include "DxLib.h"
#include "Scene.h"
#include "ScenePlay.h"

ScenePlay::ScenePlay()
{
	// �v���C�w�i�n���h��
	PlayBGHandle = 0;

	// �t�H���g�n���h��
	FontHandle = 0;
}
ScenePlay::~ScenePlay() { FinPlay(); }

//�v���C�V�[���̏�����
void ScenePlay::InitPlay()
{
	// �v���C�w�i�n���h��
	PlayBGHandle = LoadGraph(PLAY_BG_PATH);

	// �t�H���g�ݒ�
	FontHandle = CreateFontToHandle("HGP�n�p��ھ�ݽEB", 48, 3, DX_FONTTYPE_NORMAL);

	// �v���C���[�̏�����
	CPlayer.Init();

	// �؂̏�����
	CWood.Init();

	g_CurrentSceneID = SCENE_ID_LOOP_PLAY;
}

//�v���C�V�[���ʏ폈��
void ScenePlay::StepPlay()
{
	// �v���C���[�̒ʏ폈��
	CPlayer.Step();

	// �؂̒ʏ폈��
	CWood.Step();

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
	// �^�C�g���w�i�`�揈��
	DrawGraph(0, 0, PlayBGHandle, true);

	// �v���C���[�̕`�揈��
	CPlayer.Draw();

	// �؂̕`�揈��
	CWood.Draw();

	// �X�R�A��\��
	DrawScore();
}

//�v���C�V�[���I������
void ScenePlay::FinPlay()
{
	// �^�C�g���w�i�n���h��
	DeleteGraph(PlayBGHandle);

	// �t�H���g�n���h��
	FontHandle = 0;

	// �v���C���[�̏I������
	CPlayer.Fin();

	// �؂̏I������
	CWood.Fin();

	// �N���A�V�[���Ɉړ�
	g_CurrentSceneID = SCENE_ID_INIT_CLEAR;
}

// �X�R�A��\������
void ScenePlay::DrawScore()
{
	if (Score >= 0 && Score < 10)
	{
		DrawFormatStringToHandle(WINDOW_WIDTH / 2 - 9, WINDOW_HEIGHT / 4, GetColor(255, 255, 255), FontHandle, "%d", Score);
	}
	else if(Score >= 10 && Score < 100)
	{
		DrawFormatStringToHandle(WINDOW_WIDTH / 2 - 17, WINDOW_HEIGHT / 4, GetColor(255, 255, 255), FontHandle, "%d", Score);
	}
	else if (Score >= 100 && Score < 1000)
	{
		DrawFormatStringToHandle(WINDOW_WIDTH / 2 - 33, WINDOW_HEIGHT / 4, GetColor(255, 255, 255), FontHandle, "%d", Score);
	}
}
