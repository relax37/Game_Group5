#pragma once


class ScenePlay {
private:
	
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
};
