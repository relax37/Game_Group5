#pragma once

// �摜�p�X
// �v���C�w�i
#define PLAY_BG_PATH "Data/Image/BackGround/TentativePlayBG.png"

// ��
#define WOOD_IMG_PATH "Data/Play/wood.png"
#define WOOD_MAX_NUM (100)
#define WOOD_SIZE (128)

// �}
#define TWIG_IMG_PATH "Data/Play/twig.png"
#define TWIG_MAX_NUM (50)
#define TWIG_SIZE (128)

class ScenePlay {
private:
	int PlayBGHandle;									// �v���C�w�i�n���h��
	int WoodImgHandle[WOOD_MAX_NUM];					// �؂̉摜�n���h��
	int TwigImgHandle[TWIG_MAX_NUM];					// �}�̉摜�n���h��

	int WoodPosX[WOOD_MAX_NUM], WoodPosY[WOOD_MAX_NUM];	// �؂̍��W
	int TwigPosX[TWIG_MAX_NUM], TwigPosY[TWIG_MAX_NUM];	// �}�̍��W

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
