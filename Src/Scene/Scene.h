// ���c
#pragma once
#include "../Input/Input.h"
#include "../InputMouse/InputMouse.h"	//�}�E�X�̓��͐ݒ�

//�E�B���h�E�T�C�Y
#define	WINDOW_WIDTH	1280	// X�����̉�ʃT�C�Y���w��
#define	WINDOW_HEIGHT	720		// Y�����̉�ʃT�C�Y���w��
//�摜�p�X
#define START_PATH	"Data/All/start.png"			//�X�^�[�g�{�^��
#define TITLE_PATH	"Data/All/title.png"			//�^�C�g���{�^��
#define SCORE_PATH	"Data/All/ScoreBoard.png"		//�X�R�A�{�[�h
//�摜�T�C�Y
//�{�^��
#define START_WIDE	(340)		//�X�^�[�g��
#define START_HIGH	(100)		//�X�^�[�g����
#define TITLE_WIDE	(340)		//�^�C�g����
#define TITLE_HIGH	(100)		//�^�C�g������
//�{�^���̊g���
#define BUTTON_WIDE	(50)		//��
#define BUTTON_HIGH	(20)		//����

// �X�R�A
extern int Score;

enum SCENE_ID
{
	//�^�C�g���V�[����ID
	SCENE_ID_INIT_TITLE,	//������
	SCENE_ID_LOOP_TITLE,	//���[�v
	SCENE_ID_FIN_TITLE,		//�I��

	//�v���C�V�[����ID
	SCENE_ID_INIT_PLAY,		//������
	SCENE_ID_LOOP_PLAY,		//���[�v
	SCENE_ID_FIN_PLAY,		//�I��

	//�N���A�V�[����ID
	SCENE_ID_INIT_CLEAR,	//������
	SCENE_ID_LOOP_CLEAR,	//���[�v
	SCENE_ID_FIN_CLEAR,		//�I��

	//�Q�[���I�[�o�[��ID
	SCENE_ID_INIT_GAMEOVER,	//������
	SCENE_ID_LOOP_GAMEOVER,	//���[�v
	SCENE_ID_FIN_GAMEOVER,	//�I��
};

//���݂̃V�[��ID
extern SCENE_ID g_CurrentSceneID;