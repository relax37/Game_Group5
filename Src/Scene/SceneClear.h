#pragma once

// �摜�p�X
// �N���A�w�i
#define CLEAR_BG_PATH "Data/Image/BackGround/TentativeClearBG.png"

class SceneClear {
private:
	// �N���A�w�i�n���h��
	int ClearBGHandle;

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
