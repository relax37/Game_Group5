// ���c
#pragma once
#include "../Wood/Wood.h"
#include "../Player/Player.h"
#include "../Timer/Timer.h"

// �摜�p�X
// �v���C�w�i
#define PLAY_BG_PATH "Data/Image/BackGround/PlayBG.png"

class ScenePlay {
private:
	// �v���C�w�i�n���h��
	int PlayBGHandle;

	// �t�H���g�n���h��
	int FontHandle;

	// Class
	Player CPlayer;
	Wood CWood;
	Timer CTimer;

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
};
