#include "DxLib.h"
#include "Scene.h"
#include "SceneClear.h"

SceneClear::SceneClear() 
{
	// �N���A�w�i�n���h��
	ClearBGHandle = 0;
}
SceneClear::~SceneClear() { FinClear(); }

//�N���A�V�[��������
void SceneClear::InitClear()
{
	// �N���A�w�i�n���h��
	ClearBGHandle = LoadGraph(CLEAR_BG_PATH);

	//�N���A�V�[�����[�v��
	g_CurrentSceneID = SCENE_ID_LOOP_CLEAR;
}

//�N���A�V�[���ʏ폈��
void SceneClear::StepClear()
{

	// Enter����������
	if (InputKey::Push(KEY_INPUT_RETURN))
	{
		// �N���A�V�[�����I��
		FinClear();
	}
}

//�N���A�V�[���`�揈��
void SceneClear::DrawClear()
{
	// �N���A�w�i�`��
	DrawGraph(0, 0, ClearBGHandle, true);
}

//�N���A�V�[���I������
void SceneClear::FinClear()
{
	// �N���A�w�i�n���h��
	DeleteGraph(ClearBGHandle);

	//�^�C�g���V�[���ֈړ�
	g_CurrentSceneID = SCENE_ID_INIT_TITLE;
}
