#pragma once

// �摜�p�X
#define CLEAR_BG_PATH	"Data/ClearImage/ClearBuckGround.png"		//�w�i
#define CLEAR_WIN_PATH	"Data/ClearImage/win.png"					//����
//SE&BGM
#define CLEAR_WIN_SE_PATH	"Data/SE&BGM/Clear/win.mp3"				//�N���A

enum CLEAR_FROM_SCENE
{
	CLEAR_FROM_TITLE,	//�^�C�g����
	CLEAR_FROM_PLAY,	//�v���C��
};

class SceneClear {
private:
	//�摜�n���h��
	int clear_bg_handle;			//�w�i
	int clear_win_handle;			//����
	int clear_start_handle;			//�X�^�[�g�{�^��
	int clear_title_handle;			//�^�C�g���{�^��
	int clear_score_handle;			//�X�R�A�{�[�h
	int clear_font_handle;			//�t�H���g
	//SE&BGM�n���h��
	int clear_select_button_handle;	//�I��
	int clear_click_button_handle;	//�N���b�N����
	int clear_clear_handle;			//�N���A
	//�}�E�X�̕\���ݒ�
	int mouse_flag;
	//���W
	//�}�E�X�̍��W
	int mouseX;
	int mouseY;
	//�X�^�[�g�{�^��
	int startPosX_L;
	int startPosY_L;
	int startPosX_R;
	int startPosY_R;
	//�^�C�g���{�^��
	int titlePosX_L;
	int titlePosY_L;
	int titlePosX_R;
	int titlePosY_R;
	//�{�^��Bool
	bool IsStart;	//�X�^�[�g�{�^��
	bool IsTitle;	//�^�C�g���{�^��
	//�^�C�g�����v���C��
	int IsFromScene;

public:
	SceneClear();
	~SceneClear();

	//�N���A�V�[��������
	void InitClear();

	//�N���A�V�[���ʏ폈��
	void StepClear();

	//�N���A�V�[���`�揈��
	void DrawClear();

	//�N���A�V�[���I������
	void FinClear();
};
