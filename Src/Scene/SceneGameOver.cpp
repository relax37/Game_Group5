//����
#include "DxLib.h"
#include "Scene.h"
#include "SceneGameOver.h"
#include "../Collision/Collision.h"

SceneGameOver::SceneGameOver()
{
	//�摜�n���h��
	gameover_bg_handle = 0;			//�w�i
	gameover_defeat_handle = 0;		//����
	gameover_start_handle = 0;		//�X�^�[�g�{�^��
	gameover_title_handle = 0;		//�^�C�g���{�^��
	gameover_score_handle = 0;		//�X�R�A�{�[�h
	gameover_font_handle = 0;		//�t�H���g
	//SE&BGM�n���h��
	gameover_select_button_handle = 0;	//�I��
	gameover_click_button_handle = 0;	//�N���b�N����
	gameover_gameover_handle = 0;		//�Q�[���I�[�o�[
	//�}�E�X�̕\���ݒ�
	mouse_flag = TRUE;		//�\��
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
	//�I��x��
	IsSlowSelect = false;
	//�N���b�N�x��
	SlowClick = 0;
	//�V�[���J��Bool
	SceneBool = false;
	//�^�C�g�����v���C��
	IsFromScene = -1;
}
SceneGameOver::~SceneGameOver() { FinGameOver(); }

//�Q�[���I�[�o�[�V�[��������
void SceneGameOver::InitGameOver()
{
	//�摜�n���h��
	gameover_bg_handle = LoadGraph(GAMEOVER_BG_PATH);			//�w�i
	gameover_defeat_handle = LoadGraph(GAMEOVER_DEFEAT_PATH);	//����
	gameover_start_handle = LoadGraph(START_PATH);				//�X�^�[�g�{�^��
	gameover_title_handle = LoadGraph(TITLE_PATH);				//�^�C�g���{�^��
	gameover_score_handle = LoadGraph(SCORE_PATH);				//�X�R�A�{�[�h

	//SE&BGM�p�X
	gameover_select_button_handle = LoadSoundMem(SELECT_BUTTON_PATH);	//�I��
	gameover_click_button_handle = LoadSoundMem(CLICK_BUTTOM_PATH);		//�N���b�N
	gameover_gameover_handle = LoadSoundMem(GAMEOVER_DEFEAT_SE_PATH);	//����

	// �t�H���g�ݒ�
	gameover_font_handle = CreateFontToHandle("HGP�n�p��ھ�ݽEB", 48, 3, DX_FONTTYPE_NORMAL);

	//�Q�[���I�[�o�[SE
	PlaySoundMem(gameover_gameover_handle, DX_PLAYTYPE_BACK, true);

	//�}�E�X��\��
	SetMouseDispFlag(mouse_flag);

	//�Q�[���I�[�o�[���[�v��
	g_CurrentSceneID = SCENE_ID_LOOP_GAMEOVER;
}

//�Q�[���I�[�o�[�V�[���ʏ폈��
void SceneGameOver::StepGameOver()
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
			PlaySoundMem(gameover_select_button_handle, DX_PLAYTYPE_BACK, true);	//�I��
		}
		//���N���b�N�𗣂�
		if (IsMouseRelease(MOUSE_INPUT_LEFT))
		{
			//��Ƀv���C�V�[���ֈړ�
			IsFromScene = GAMEOVER_FROM_SCENE::GAMEOVER_FROM_PLAY;
			//�V�[���J��Bool
			SceneBool = true;
			if (SlowClick == 0)
			{
				SlowClick = 60;
				//SE
				PlaySoundMem(gameover_click_button_handle, DX_PLAYTYPE_BACK, true);	//�N���b�N
			}
		}
	}
	else if (IsStart == true)
	{
		if (Collision::Rect(mouseX, mouseY, 0, 0, startPosX_L - BUTTON_WIDE, startPosY_L - BUTTON_HIGH,
			START_WIDE + BUTTON_WIDE * 2, START_HIGH + BUTTON_HIGH * 2))
		{
			//SE
			PlaySoundMem(gameover_select_button_handle, DX_PLAYTYPE_BACK, true);	//�I��
			//���N���b�N�𗣂�
			if (IsMouseRelease(MOUSE_INPUT_LEFT))
			{
				//��Ƀv���C�V�[���ֈړ�
				IsFromScene = GAMEOVER_FROM_SCENE::GAMEOVER_FROM_PLAY;
				//�V�[���J��Bool
				SceneBool = true;
				if (SlowClick == 0)
				{
					SlowClick = 60;
					//SE
					PlaySoundMem(gameover_click_button_handle, DX_PLAYTYPE_BACK, true);	//�N���b�N
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
	//�}�E�X�ƃ^�C�g���{�^���̓����蔻��
	if (Collision::Rect(mouseX, mouseY, 0, 0,
		titlePosX_L, titlePosY_L, TITLE_WIDE, TITLE_HIGH))
	{
		if (IsTitle == false)
		{
			//�^�C�g��Bool��true�ɂ���
			IsTitle = true;
		}
		//�I��x��
		if (IsSlowSelect == false)
		{
			//��b�x��
			IsSlowSelect = true;
			//SE
			PlaySoundMem(gameover_select_button_handle, DX_PLAYTYPE_BACK, true);	//�I��
		}
		//���N���b�N�𗣂�
		if (IsMouseRelease(MOUSE_INPUT_LEFT))
		{
			//��Ƀ^�C�g���V�[���ֈړ�
			IsFromScene = GAMEOVER_FROM_SCENE::GAMEOVER_FROM_TITLE;
			//�V�[���J��Bool
			SceneBool = true;
			if (SlowClick == 0)
			{
				SlowClick = 60;
				//SE
				PlaySoundMem(gameover_click_button_handle, DX_PLAYTYPE_BACK, true);	//�N���b�N
			}
		}
	}
	else if (IsTitle == true)
	{
		if (Collision::Rect(mouseX, mouseY, 0, 0, titlePosX_L - BUTTON_WIDE, titlePosY_L - BUTTON_HIGH,
			TITLE_WIDE + BUTTON_WIDE * 2, TITLE_HIGH + BUTTON_HIGH))
		{
			//SE
			PlaySoundMem(gameover_select_button_handle, DX_PLAYTYPE_BACK, true);	//�I��
			//���N���b�N�𗣂�
			if (IsMouseRelease(MOUSE_INPUT_LEFT))
			{
				//��Ƀ^�C�g���V�[���ֈړ�
				IsFromScene = GAMEOVER_FROM_SCENE::GAMEOVER_FROM_TITLE;
				//�V�[���J��Bool
				SceneBool = true;
				if (SlowClick == 0)
				{
					SlowClick = 60;
					//SE
					PlaySoundMem(gameover_click_button_handle, DX_PLAYTYPE_BACK, true);	//�N���b�N
				}
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
	//�����̃{�^���ɓ������ĂȂ��Ƃ�
	if (IsStart == false && IsTitle == false)
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
		//�Q�[���I�[�o�[�㏈���Ɉڍs
		g_CurrentSceneID = SCENE_ID_FIN_GAMEOVER;
	}
}

//�Q�[���I�[�o�[�V�[���`�揈��
void SceneGameOver::DrawGameOver()
{
	//�摜�`��
	DrawGraph(0, 0, gameover_bg_handle, true);			//�w�i
	DrawGraph(551, 50, gameover_defeat_handle, true);	//����
	if (IsStart == true)
	{
		DrawExtendGraph(startPosX_L - BUTTON_WIDE, startPosY_L - BUTTON_HIGH,
			startPosX_R + BUTTON_WIDE, startPosY_R + BUTTON_HIGH, gameover_start_handle, true);	//�X�^�[�g�{�^��
	}
	else
	{
		DrawExtendGraph(startPosX_L, startPosY_L, startPosX_R, startPosY_R, gameover_start_handle, true);		//�X�^�[�g�{�^��
	}
	if (IsTitle == true)
	{
		DrawExtendGraph(titlePosX_L - BUTTON_WIDE, titlePosY_L - BUTTON_HIGH,
			titlePosX_R + BUTTON_WIDE, titlePosY_R + BUTTON_HIGH, gameover_title_handle, true);	//�^�C�g���{�^��
	}
	else
	{
		DrawExtendGraph(titlePosX_L, titlePosY_L, titlePosX_R, titlePosY_R, gameover_title_handle, true);		//�^�C�g���{�^��
	}
	DrawGraph(447, 200, gameover_score_handle, true);		//�X�R�A�{�[�h
	//�X�R�A�\��
	if (Score >= 0 && Score < 10)
	{
		DrawFormatStringToHandle(WINDOW_WIDTH / 2 - 9, 340, GetColor(255, 0, 0), gameover_font_handle, "%d", Score);
	}
	else if (Score >= 10 && Score < 100)
	{
		DrawFormatStringToHandle(WINDOW_WIDTH / 2 - 17, 340, GetColor(255, 0, 0), gameover_font_handle, "%d", Score);
	}
	else if (Score >= 100 && Score < 1000)
	{
		DrawFormatStringToHandle(WINDOW_WIDTH / 2 - 33, 340, GetColor(255, 0, 0), gameover_font_handle, "%d", Score);
	}
}

//�Q�[���I�[�o�[�V�[���I������
void SceneGameOver::FinGameOver()
{
	//�摜�n���h��
	DeleteGraph(gameover_bg_handle);		//�w�i
	DeleteGraph(gameover_defeat_handle);	//����
	DeleteGraph(gameover_start_handle);		//�X�^�[�g�{�^��
	DeleteGraph(gameover_title_handle);		//�^�C�g���{�^��
	DeleteGraph(gameover_score_handle);		//�X�R�A�{�[�h

	//SE&BGM
	DeleteSoundMem(gameover_select_button_handle);		//�I��
	DeleteSoundMem(gameover_click_button_handle);		//�N���b�N
	DeleteSoundMem(gameover_gameover_handle);			//�Q�[���I�[�o�[

	//�I��x��
	IsSlowSelect = false;
	//�V�[���J��Bool
	SceneBool = false;

	//�t�H���g
	gameover_font_handle = 0;

	// �X�R�A�̏�����
	Score = 0;

	if (IsFromScene == GAMEOVER_FROM_SCENE::GAMEOVER_FROM_TITLE)
	{
		//�^�C�g���V�[���ֈړ�
		g_CurrentSceneID = SCENE_ID_INIT_TITLE;
	}
	else if (IsFromScene == GAMEOVER_FROM_SCENE::GAMEOVER_FROM_PLAY)
	{
		//�v���C�V�[���ֈړ�
		g_CurrentSceneID = SCENE_ID_INIT_PLAY;
	}
}
