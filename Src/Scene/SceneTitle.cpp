#include "DxLib.h"
#include "Scene.h"
#include "SceneTitle.h"

SceneTitle::SceneTitle() 
{
	// �^�C�g���w�i�n���h��
	title_bg_handle = 0;

	//���̃{�^�����g�債�Ȃ�
	title_select = -1;

	//�}�E�X��\��
	mouse_flag = TRUE;

	title_bg_handle = -1;		// �w�i
	title_name_handle = -1;		//�^�C�g����
	title_start_handle = -1;	//�X�^�[�g�{�^��
	title_rules_handle = -1;	//���[���{�^��

	//�}�E�X�̍��W
	mouseX = 0;
	mouseY = 0;
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

	//�}�E�X��\��
	SetMouseDispFlag(mouse_flag);

	// �^�C�g�����[�v��
	g_CurrentSceneID = SCENE_ID_LOOP_TITLE;
}

// �^�C�g���ʏ폈��
void SceneTitle::StepTitle()
{
	//�}�E�X�̍��W���擾
	GetMousePoint(&mouseX, &mouseY);

	//�}�E�X�̃{�^���̏�Ԃ𓾂�(�O��
	if (IsMouseRelease(MOUSE_INPUT_LEFT))
	{
		//�e�X�g
	}

	switch (title_select)
	{
		//�X�^�[�g�{�^�����g��
	case TitleSelect::START_BOTTUN:
		
		break;
		//���[���{�^�����g��
	case TitleSelect::RULES_BOTTUN:

		break;
	}

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
