#pragma once

class SceneClear {
private:


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
