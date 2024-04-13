#pragma once
#include "../Input/Input.h"
#include "../InputMouse/InputMouse.h"	//�}�E�X�̓��͐ݒ�

//�E�B���h�E�T�C�Y
#define	WINDOW_WIDTH	1280	// X�����̉�ʃT�C�Y���w��
#define	WINDOW_HEIGHT	720		// Y�����̉�ʃT�C�Y���w��

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