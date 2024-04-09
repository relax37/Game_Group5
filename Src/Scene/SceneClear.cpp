#include "DxLib.h"
#include "../Input/Input.h"
#include "Scene.h"
#include "SceneClear.h"

SceneClear::SceneClear() {}
SceneClear::~SceneClear() {}

//�N���A�V�[��������
void SceneClear::InitClear()
{

	//�N���A�V�[�����[�v��
	g_CurrentSceneID = SCENE_ID_LOOP_CLEAR;
}

//�N���A�V�[���ʏ폈��
void SceneClear::StepClear()
{
	// �^�C�g���ɖ߂�
	FinClear();
}

//�N���A�V�[���`�揈��
void SceneClear::DrawClear()
{

}

//�N���A�V�[���I������
void SceneClear::FinClear()
{
	//�^�C�g���V�[���ֈړ�
	g_CurrentSceneID = SCENE_ID_INIT_TITLE;
}
