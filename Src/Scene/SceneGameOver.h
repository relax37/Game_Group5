#pragma once

// �摜�p�X
// �Q�[���I�[�o�[�w�i
#define GAMEOVER_BG_PATH "Data/Image/BackGround/TentativeGameOverBG.png"

class SceneGameOver {
private:
	// �Q�[���I�[�o�[�w�i�n���h��
	int GameOverBGHandle;

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
