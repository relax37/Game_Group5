#include "DxLib.h"
#include "Scene.h"
#include "SceneTitle.h"

SceneTitle::SceneTitle() 
{
	// �^�C�g���w�i�n���h��
	title_bg_handle = 0;
}
SceneTitle::~SceneTitle() { FinTitle(); }

// �^�C�g���̏�����
void SceneTitle::InitTitle()
{
	//�摜�n���h��
	title_bg_handle = LoadGraph(TITLE_BG_PATH);			//�w�i
	title_name_handle = LoadGraph(TITLE_NAME_PATH);		//�^�C�g����
	title_start_handle = LoadGraph(TITLE_START_PATH);	//�X�^�[�g�{�^��
	title_rules_handle = LoadGraph(TITLE_RULES_PATH);	//���[���{�^��

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
	DrawGraph(0, 0, title_bg_handle, true);			//�w�i
	DrawGraph(340, 60, title_name_handle, true);	//�^�C�g����
	DrawGraph(470, 310, title_start_handle, true);	//�X�^�[�g�{�^��
	DrawGraph(480, 480, title_rules_handle, true);	//���[���{�^��
}

// �^�C�g���I������
void SceneTitle::FinTitle()
{
	//�摜�j��
	DeleteGraph(title_bg_handle);		//�w�i
	DeleteGraph(title_name_handle);		//�^�C�g����
	DeleteGraph(title_start_handle);	//�X�^�[�g�{�^��
	DeleteGraph(title_rules_handle);	//���[���{�^��

	// �v���C�V�[���Ɉړ�
	g_CurrentSceneID = SCENE_ID_INIT_PLAY;
}
