#include "DxLib.h"
#include "../Input/Input.h"
#include "Scene.h"
#include "SceneTitle.h"

SceneTitle::SceneTitle() {}
SceneTitle::~SceneTitle() {}

// �^�C�g���̏�����
void SceneTitle::InitTitle()
{

	// �^�C�g�����[�v��
	g_CurrentSceneID = SCENE_ID_LOOP_TITLE;
}

// �^�C�g���ʏ폈��
void SceneTitle::StepTitle()
{
	FinTitle();
}

// �^�C�g���`�揈��
void SceneTitle::DrawTitle()
{

}

// �^�C�g���I������
void SceneTitle::FinTitle()
{
	
	// �v���C�V�[���Ɉړ�
	g_CurrentSceneID = SCENE_ID_INIT_PLAY;
}
