//����
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

	//SE&BGM�n���h��
	title_select_button_handle = 0;		//�I��
	title_click_button_handle = 0;		//�N���b�N����
	title_bgm_handle = 0;				//bgm

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
	//�I��x��
	IsSlowSelect = false;
	//�N���b�N�x��
	SlowClick = 0;
	//�V�[���J��Bool
	SceneBool = false;
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

	//BGM&SE
	title_select_button_handle = LoadSoundMem(SELECT_BUTTON_PATH);		//�I��
	title_click_button_handle = LoadSoundMem(CLICK_BUTTOM_PATH);		//�N���b�N
	title_bgm_handle = LoadSoundMem(TITLE_BGM_PATH);					//bgm

	//�}�E�X��\��
	SetMouseDispFlag(mouse_flag);

	//bgm
	PlaySoundMem(title_bgm_handle, DX_PLAYTYPE_LOOP, true);

	//bgm���ʒ���
	ChangeVolumeSoundMem(100, title_bgm_handle);

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
		//�I��x��
		if (IsSlowSelect == false)
		{
			//��b�x��
			IsSlowSelect = true;
			//SE
			PlaySoundMem(title_select_button_handle, DX_PLAYTYPE_BACK, true);	//�I��
		}
		//���N���b�N�𗣂�
		if (IsMouseRelease(MOUSE_INPUT_LEFT))
		{
			//�V�[���J��Bool
			SceneBool = true;
			if (SlowClick == 0)
			{
				SlowClick = 60;
				//SE
				PlaySoundMem(title_click_button_handle, DX_PLAYTYPE_BACK, true);	//�N���b�N
			}
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
				//�V�[���J��Bool
				SceneBool = true;
				if (SlowClick == 0)
				{
					SlowClick = 60;
					//SE
					PlaySoundMem(title_click_button_handle, DX_PLAYTYPE_BACK, true);	//�N���b�N
				}
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
		//�I��x��
		if (IsSlowSelect == false)
		{
			//��b�x��
			IsSlowSelect = true;
			//SE
			PlaySoundMem(title_select_button_handle, DX_PLAYTYPE_BACK, true);	//�I��
		}
		//���N���b�N�𗣂�
		if (IsMouseRelease(MOUSE_INPUT_LEFT))
		{
			if (SlowClick == 0)
			{
				SlowClick = 60;
				//SE
				PlaySoundMem(title_click_button_handle, DX_PLAYTYPE_BACK, true);	//�N���b�N
			}
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
			//SE
			PlaySoundMem(title_select_button_handle, DX_PLAYTYPE_BACK, true);	//�I��
			//���N���b�N�𗣂�
			if (IsMouseRelease(MOUSE_INPUT_LEFT))
			{
				if (SlowClick == 0)
				{
					SlowClick = 60;
					//SE
					PlaySoundMem(title_click_button_handle, DX_PLAYTYPE_BACK, true);	//�N���b�N
				}
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
	//�����̃{�^���ɓ������ĂȂ��Ƃ�
	if (IsStart == false && IsRules == false)
	{
		//�Ăђx��
		IsSlowSelect = false;
	}
	//�N���b�N�x��
	if (SlowClick != 0)
	{
		SlowClick--;
	}
	if (SlowClick == 0 && SceneBool == true)
	{
		//�^�C�g���Ɉڍs
		g_CurrentSceneID = SCENE_ID_FIN_TITLE;
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

	//SE&BGM
	DeleteSoundMem(title_select_button_handle);	//�I��
	DeleteSoundMem(title_click_button_handle);	//�N���b�N
	DeleteSoundMem(title_bgm_handle);			//bgm

	//�I��x��
	IsSlowSelect = false;
	//�V�[���J��Bool
	SceneBool = false;

	//���[�����\���ɂ���
	IsRulesDraw = false;

	// �v���C�V�[���Ɉړ�
	g_CurrentSceneID = SCENE_ID_INIT_PLAY;
}

