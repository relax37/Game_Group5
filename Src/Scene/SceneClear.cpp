#include "DxLib.h"
#include "Scene.h"
#include "SceneClear.h"
#include "../Collision/Collision.h"

SceneClear::SceneClear() 
{
	//�摜�n���h��
	clear_bg_handle = 0;		//�w�i
	clear_start_handle = 0;		//�X�^�[�g�{�^��
	clear_title_handle = 0;		//�^�C�g���{�^��
	clear_score_handle = 0;		//�X�R�A�{�[�h
	clear_font_handle = 0;		//�t�H���g
	//�}�E�X�̕\���ݒ�
	mouse_flag=TRUE;		//�\��
	//���W
	//�}�E�X�̍��W
	mouseX = 0;
	mouseY = 0;
	//�X�^�[�g�{�^��
	startPosX_L = 150;
	startPosY_L = 500;
	startPosX_R = startPosX_L + START_WIDE;
	startPosY_R = startPosY_L + START_HIGH;
	//�^�C�g���{�^��
	titlePosX_L = 790;
	titlePosY_L = 500;
	titlePosX_R = titlePosX_L + TITLE_WIDE;
	titlePosY_R = titlePosY_L + TITLE_HIGH;
	//�{�^��Bool
	IsStart = false;	//�X�^�[�g�{�^��
	IsTitle = false;	//�^�C�g���{�^��
	//�^�C�g�����v���C��
	IsFromScene = -1;
}
SceneClear::~SceneClear() { FinClear(); }

//�N���A�V�[��������
void SceneClear::InitClear()
{
	//�摜�n���h��
	clear_bg_handle = LoadGraph(CLEAR_BG_PATH);		//�w�i
	clear_start_handle = LoadGraph(START_PATH);		//�X�^�[�g�{�^��
	clear_title_handle = LoadGraph(TITLE_PATH);		//�^�C�g���{�^��
	clear_score_handle = LoadGraph(SCORE_PATH);		//�X�R�A�{�[�h
	// �t�H���g�ݒ�
	clear_font_handle = CreateFontToHandle("HGP�n�p��ھ�ݽEB", 48, 3, DX_FONTTYPE_NORMAL);

	//�}�E�X��\��
	SetMouseDispFlag(mouse_flag);

	//�N���A�V�[�����[�v��
	g_CurrentSceneID = SCENE_ID_LOOP_CLEAR;
}

//�N���A�V�[���ʏ폈��
void SceneClear::StepClear()
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
			//�N���A�㏈���Ɉڍs
			g_CurrentSceneID = SCENE_ID_FIN_CLEAR;
			//��Ƀv���C�V�[���ֈړ�
			IsFromScene = CLEAR_FROM_SCENE::CLEAR_FROM_PLAY;
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
				//�N���A�㏈���Ɉڍs
				g_CurrentSceneID = SCENE_ID_FIN_CLEAR;
				//��Ƀv���C�V�[���ֈړ�
				IsFromScene = CLEAR_FROM_SCENE::CLEAR_FROM_PLAY;
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
	//�}�E�X�ƃ^�C�g���{�^���̓����蔻��
	if (Collision::Rect(mouseX, mouseY, 0, 0,
		titlePosX_L, titlePosY_L, TITLE_WIDE, TITLE_HIGH))
	{
		if (IsTitle == false)
		{
			//�^�C�g��Bool��true�ɂ���
			IsTitle = true;
		}
		//���N���b�N�𗣂�
		if (IsMouseRelease(MOUSE_INPUT_LEFT))
		{
			//�N���A�㏈���Ɉڍs
			g_CurrentSceneID = SCENE_ID_FIN_CLEAR;
			//��Ƀ^�C�g���V�[���ֈړ�
			IsFromScene = CLEAR_FROM_SCENE::CLEAR_FROM_TITLE;
		}
	}
	else if (IsTitle == true)
	{
		if (Collision::Rect(mouseX, mouseY, 0, 0, titlePosX_L - BUTTON_WIDE, titlePosY_L - BUTTON_HIGH,
			TITLE_WIDE + BUTTON_WIDE * 2, TITLE_HIGH + BUTTON_HIGH))
		{
			//���N���b�N�𗣂�
			if (IsMouseRelease(MOUSE_INPUT_LEFT))
			{
				//�N���A�㏈���Ɉڍs
				g_CurrentSceneID = SCENE_ID_FIN_CLEAR;
				//��Ƀ^�C�g���V�[���ֈړ�
				IsFromScene = CLEAR_FROM_SCENE::CLEAR_FROM_TITLE;
			}
		}
		//�������ĂȂ��Ƃ�
		else
		{
			IsTitle = false;
		}
	}
	//�������ĂȂ��Ƃ�
	else
	{
		IsTitle = false;
	}

}

//�N���A�V�[���`�揈��
void SceneClear::DrawClear()
{
	//�摜�`��
	DrawGraph(0, 0, clear_bg_handle, true);		//�w�i
	if (IsStart == true)
	{
		DrawExtendGraph(startPosX_L - BUTTON_WIDE, startPosY_L - BUTTON_HIGH,
			startPosX_R + BUTTON_WIDE, startPosY_R + BUTTON_HIGH, clear_start_handle, true);	//�X�^�[�g�{�^��
	}
	else
	{
		DrawExtendGraph(startPosX_L, startPosY_L, startPosX_R, startPosY_R, clear_start_handle, true);		//�X�^�[�g�{�^��
	}
	if (IsTitle == true)
	{
		DrawExtendGraph(titlePosX_L - BUTTON_WIDE, titlePosY_L - BUTTON_HIGH,
			titlePosX_R + BUTTON_WIDE, titlePosY_R + BUTTON_HIGH, clear_title_handle, true);	//�^�C�g���{�^��
	}
	else
	{
		DrawExtendGraph(titlePosX_L, titlePosY_L, titlePosX_R, titlePosY_R, clear_title_handle, true);		//�^�C�g���{�^��
	}
	DrawGraph(450, 100, clear_score_handle, true);		//�X�R�A�{�[�h
	//�X�R�A�\��
	if (Score >= 0 && Score < 10)
	{
		DrawFormatStringToHandle(WINDOW_WIDTH / 2 - 9, 240, GetColor(255, 0, 0), clear_font_handle, "%d", Score);
	}
	else if (Score >= 10 && Score < 100)
	{
		DrawFormatStringToHandle(WINDOW_WIDTH / 2 - 17, 240, GetColor(255, 0, 0), clear_font_handle, "%d", Score);
	}
	else if (Score >= 100 && Score < 1000)
	{
		DrawFormatStringToHandle(WINDOW_WIDTH / 2 - 33, 240, GetColor(255, 0, 0), clear_font_handle, "%d", Score);
	}
}

//�N���A�V�[���I������
void SceneClear::FinClear()
{
	//�摜�n���h��
	DeleteGraph(clear_bg_handle);		//�w�i
	DeleteGraph(clear_start_handle);	//�X�^�[�g�{�^��
	DeleteGraph(clear_title_handle);	//�^�C�g���{�^��
	DeleteGraph(clear_score_handle);	//�X�R�A�{�[�h

	//�t�H���g
	clear_font_handle = 0;

	// �X�R�A�̏�����
	Score = 0;

	if (IsFromScene == CLEAR_FROM_SCENE::CLEAR_FROM_TITLE)
	{
		//�^�C�g���V�[���ֈړ�
		g_CurrentSceneID = SCENE_ID_INIT_TITLE;
	}
	else if (IsFromScene == CLEAR_FROM_SCENE::CLEAR_FROM_PLAY)
	{
		//�v���C�V�[���ֈړ�
		g_CurrentSceneID = SCENE_ID_INIT_PLAY;
	}
}
