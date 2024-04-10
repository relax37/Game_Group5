#include "DxLib.h"
#include "Scene.h"
#include "ScenePlay.h"

ScenePlay::ScenePlay() 
{
	// �v���C�w�i�n���h��
	PlayBGHandle = 0;
}
ScenePlay::~ScenePlay() { FinPlay(); }

//�v���C�V�[���̏�����
void ScenePlay::InitPlay()
{
	// �v���C�w�i�n���h��
	PlayBGHandle = LoadGraph(PLAY_BG_PATH);

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
}

//�v���C�V�[���I������
void ScenePlay::FinPlay()
{
	// �^�C�g���w�i�n���h��
	DeleteGraph(PlayBGHandle);

	// �N���A�V�[���Ɉړ�
	g_CurrentSceneID = SCENE_ID_INIT_CLEAR;
}
