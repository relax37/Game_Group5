#include "DxLib.h"
#include "Scene.h"
#include "SceneTitle.h"
#include "../Collision/Collision.h"

SceneTitle::SceneTitle() 
{
	//�摜�n���h��
	title_bg_handle = -1;				// �w�i
	title_name_handle = -1;				//�^�C�g����
	title_start_handle = -1;			//�X�^�[�g�{�^��
	title_rules_handle = -1;			//���[���{�^��
	title_rules_picture_handle = -1;	//���[���摜

	//�}�E�X��\��
	mouse_flag = TRUE;

	//�}�E�X�̍��W
	mouseX = 0;
	mouseY = 0;
	//�X�^�[�g�{�^��
	startPosX_L = 470;
	startPosY_L = 310;
	startPosX_R = startPosX_L + START_WIDE;
	startPosY_R = startPosY_L + START_HIGH;
	//���[���{�^��
	rulesPosX_L = 480;
	rulesPosY_L = 480;
	rulesPosX_R = rulesPosX_L + TITLE_RULES_WIDE;
	rulesPosY_R = rulesPosY_L + TITLE_RULES_HIGH;
	//�{�^��Bool
	IsStart = false;	//�X�^�[�g�{�^��
	IsRules = false;	//���[���{�^��

	//���[���\��Bool
	IsRulesDraw = false;
}
SceneTitle::~SceneTitle() { FinTitle(); }

// �^�C�g���̏�����
void SceneTitle::InitTitle()
{
	//�摜�n���h��
	title_bg_handle = LoadGraph(TITLE_BG_PATH);							//�w�i
	title_name_handle = LoadGraph(TITLE_NAME_PATH);						//�^�C�g����
	title_start_handle = LoadGraph(START_PATH);							//�X�^�[�g�{�^��
	title_rules_handle = LoadGraph(TITLE_RULES_PATH);					//���[���{�^��
	title_rules_picture_handle = LoadGraph(TITLE_RULES_PICTURE_PATH);	//���[���摜

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

	//�}�E�X�ƃX�^�[�g�{�^���̓����蔻��
	if (Collision::Rect(mouseX, mouseY, 0, 0, 
		startPosX_L, startPosY_L, START_WIDE, START_HIGH))
	{
		if (IsStart == false)
		{
			//�X�^�[�gBool��true�ɂ���
			IsStart = true;
		}
		//���N���b�N�𗣂�
		if (IsMouseRelease(MOUSE_INPUT_LEFT))
		{
			//�^�C�g���Ɉڍs
			g_CurrentSceneID = SCENE_ID_FIN_TITLE;
		}
	}
	else if (IsStart == true)
	{
		if (Collision::Rect(mouseX, mouseY, 0, 0, startPosX_L - BUTTON_WIDE, startPosY_L - BUTTON_HIGH,
			START_WIDE + BUTTON_WIDE * 2, START_HIGH + BUTTON_HIGH * 2))
		{
			//���N���b�N�𗣂�
			if (IsMouseRelease(MOUSE_INPUT_LEFT))
			{
				//�^�C�g���Ɉڍs
				g_CurrentSceneID = SCENE_ID_FIN_TITLE;
			}
		}
		//�������ĂȂ��Ƃ�
		else
		{
			IsStart = false;
		}
	}
	//�������ĂȂ��Ƃ�
	else
	{
		IsStart = false;
	}
	//�}�E�X�ƃ��[���{�^���̓����蔻��
	if (Collision::Rect(mouseX, mouseY, 0, 0,
		rulesPosX_L, rulesPosY_L, TITLE_RULES_WIDE, TITLE_RULES_HIGH))
	{
		if (IsRules == false)
		{
			//���[��Bool��true�ɂ���
			IsRules = true;
		}
		//���N���b�N�𗣂�
		if (IsMouseRelease(MOUSE_INPUT_LEFT))
		{
			if (IsRulesDraw == false)
			{
				IsRulesDraw = true;
			}
			else
			{
				IsRulesDraw = false;
			}
		}
	}
	else if (IsRules == true)
	{
		if (Collision::Rect(mouseX, mouseY, 0, 0, rulesPosX_L - BUTTON_WIDE, rulesPosY_L - BUTTON_HIGH,
			TITLE_RULES_WIDE + BUTTON_WIDE * 2, TITLE_RULES_HIGH + BUTTON_HIGH))
		{
			//���N���b�N�𗣂�
			if (IsMouseRelease(MOUSE_INPUT_LEFT))
			{
				if (IsRulesDraw == false)
				{
					IsRulesDraw = true;
				}
				else
				{
					IsRulesDraw = false;
				}
			}
		}
		//�������ĂȂ��Ƃ�
		else
		{
			IsRules = false;
		}
	}
	//�������ĂȂ��Ƃ�
	else
	{
		IsRules = false;
	}

}

// �^�C�g���`�揈��
void SceneTitle::DrawTitle()
{
	DrawGraph(0, 0, title_bg_handle, true);			//�w�i
	DrawGraph(340, 45, title_name_handle, true);	//�^�C�g����
	if (IsStart == true)
	{
		DrawExtendGraph(startPosX_L - BUTTON_WIDE, startPosY_L - BUTTON_HIGH,
			startPosX_R + BUTTON_WIDE, startPosY_R + BUTTON_HIGH, title_start_handle, true);	//�X�^�[�g�{�^��
	}
	else
	{
		DrawExtendGraph(startPosX_L, startPosY_L, startPosX_R, startPosY_R, title_start_handle, true);		//�X�^�[�g�{�^��
	}
	if (IsRules == true)
	{
		DrawExtendGraph(rulesPosX_L - BUTTON_WIDE, rulesPosY_L - BUTTON_HIGH,
			rulesPosX_R + BUTTON_WIDE, rulesPosY_R + BUTTON_HIGH, title_rules_handle, true);	//���[���{�^��
	}
	else
	{
		DrawExtendGraph(rulesPosX_L, rulesPosY_L, rulesPosX_R, rulesPosY_R, title_rules_handle, true);		//���[���{�^��
	}

	//���[���\��
	if (IsRulesDraw == true)
	{
		DrawGraph(100, 275, title_rules_picture_handle, true);
	}
}

// �^�C�g���I������
void SceneTitle::FinTitle()
{
	//�摜�j��
	DeleteGraph(title_bg_handle);				//�w�i
	DeleteGraph(title_name_handle);				//�^�C�g����
	DeleteGraph(title_start_handle);			//�X�^�[�g�{�^��
	DeleteGraph(title_rules_handle);			//���[���{�^��
	DeleteGraph(title_rules_picture_handle);	//���[���摜

	//���[�����\���ɂ���
	IsRulesDraw = false;

	// �v���C�V�[���Ɉړ�
	g_CurrentSceneID = SCENE_ID_INIT_PLAY;
}

