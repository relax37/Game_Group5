//����
#pragma once

// �摜�p�X
#define GAMEOVER_BG_PATH		"Data/GameOverImage/GameOverBuckGround.png"	//�w�i
#define GAMEOVER_DEFEAT_PATH	"Data/GameOverImage/lose.png"				//����
//SE&BGM�p�X
#define GAMEOVER_DEFEAT_SE_PATH	"Data/SE&BGM/Gameover/defeat.mp3"		//����

enum GAMEOVER_FROM_SCENE
{
	GAMEOVER_FROM_TITLE,	//�^�C�g����
	GAMEOVER_FROM_PLAY,		//�v���C��
};

class SceneGameOver {
private:
	//�摜�n���h��
	int gameover_bg_handle;				//�w�i
	int gameover_defeat_handle;			//����
	int gameover_start_handle;			//�X�^�[�g�{�^��
	int gameover_title_handle;			//�^�C�g���{�^��
	int gameover_score_handle;			//�X�R�A�{�[�h
	int gameover_font_handle;			//�t�H���g
	//SE&BGM�n���h��
	int gameover_select_button_handle;	//�I��
	int gameover_click_button_handle;	//�N���b�N����
	int gameover_gameover_handle;		//�Q�[���I�[�o�[
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
	//�I��x��
	bool IsSlowSelect;
	//�N���b�N�x��
	int SlowClick;
	//�V�[���J��Bool
	bool SceneBool;
	//�^�C�g�����v���C��
	int IsFromScene;

public:
	SceneGameOver();
	~SceneGameOver();

	//�Q�[���I�[�o�[�V�[��������
	void InitGameOver();

	//�Q�[���I�[�o�[�V�[���ʏ폈��
	void StepGameOver();

	//�Q�[���I�[�o�[�V�[���`�揈��
	void DrawGameOver();

	//�Q�[���I�[�o�[�V�[���I������
	void FinGameOver();
};
