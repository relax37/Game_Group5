#pragma once

// �摜�p�X
// �^�C�g���w�i
#define TITLE_BG_PATH "Data/Image/BackGround/TentativeTitleBG.png"

class SceneTitle {
private:
	// �^�C�g���w�i�n���h��
	int TitleBGHandle;

public:
	SceneTitle();
	~SceneTitle();

	// �^�C�g���̏�����
	void InitTitle();

	// �^�C�g���ʏ폈��
	void StepTitle();

	// �^�C�g���`�揈��
	void DrawTitle();

	// �^�C�g���I������
	void FinTitle();
};
