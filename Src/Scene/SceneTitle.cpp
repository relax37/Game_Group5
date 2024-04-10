#include "DxLib.h"
#include "Scene.h"
#include "SceneTitle.h"

SceneTitle::SceneTitle() 
{
	// �^�C�g���w�i�n���h��
	TitleBGHandle = 0;
}
SceneTitle::~SceneTitle() { FinTitle(); }

// �^�C�g���̏�����
void SceneTitle::InitTitle()
{
	// �^�C�g���w�i�n���h��
	TitleBGHandle = LoadGraph(TITLE_BG_PATH);

	// �^�C�g�����[�v��
	g_CurrentSceneID = SCENE_ID_LOOP_TITLE;
}

// �^�C�g���ʏ폈��
void SceneTitle::StepTitle()
{

	// Enter����������
	if(InputKey::Push(KEY_INPUT_RETURN))
	{
		// �^�C�g���V�[�����I��
		FinTitle();
	}
}

// �^�C�g���`�揈��
void SceneTitle::DrawTitle()
{
	// �^�C�g���w�i�`��
	DrawGraph(0, 0, TitleBGHandle, true);
}

// �^�C�g���I������
void SceneTitle::FinTitle()
{
	// �^�C�g���w�i�n���h��
	DeleteGraph(TitleBGHandle);

	// �v���C�V�[���Ɉړ�
	g_CurrentSceneID = SCENE_ID_INIT_PLAY;
}
