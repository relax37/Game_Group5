// ���c
#pragma once

#include "../Player/Player.h"
#include "../Wood/Wood.h"
#include "../Twig/Twig.h"
#include "../Timer/Timer.h"

// �摜�p�X
// �v���C�w�i
#define PLAY_BG_PATH "Data/Image/BackGround/PlayBG.png"

// �T�E���h�p�X
#define PLAY_BGM_PATH "Data/SE&BGM/Play/PlayBGM.mp3"

enum PlaySound {
	PLAY_BGM,
	START_SE,
	CUT_SE,

	SOUND_MAX_NUM,
};

class ScenePlay {
private:
	// �v���C�w�i�n���h��
	int PlayBGHandle;

	// �t�H���g�n���h��
	int FontHandle;

	// �T�E���h�n���h��
	int SoundHandle;

	// Class
	Player CPlayer;
	Wood CWood;
	Twig CTwig;
	Timer CTimer;

	// �N���b�N�X�^�[�g����
	bool isClickStart;

public:
	ScenePlay();
	~ScenePlay();

	// �v���C�V�[���̏�����
	void InitPlay();

	// �v���C�V�[���ʏ폈��
	void StepPlay();

	// �v���C�V�[���`�揈��
	void DrawPlay();

	// �v���C�V�[���I������
	void FinPlay();

	// �X�R�A��\������
	void DrawScore();

	// �N���b�N����
	void Click();
};
