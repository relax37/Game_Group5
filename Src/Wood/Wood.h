#pragma once

// ��
#define WOOD_IMG_PATH "Data/Image/Play/wood.png"
#define WOODSTAND_IMG_PATH "Data/Image/Play/woodstand.png"
#define WOOD_MAX_NUM (20)
#define WOOD_SIZE (200)

// �}
//#define TWIG_IMG_PATH "Data/Imaga/Play/karinoeda.png"
//#define TWIG_MAX_NUM (50)
//#define TWIG_SIZE (128)

class Wood {
private:
	int WoodImgHandle[WOOD_MAX_NUM];					// �؂̉摜�n���h��
	int WoodStandImgHandle;								// �؂̍��̉摜�n���h��
	//int TwigImgHandle[TWIG_MAX_NUM];					// �}�̉摜�n���h��

	int WoodPosX[WOOD_MAX_NUM], WoodPosY[WOOD_MAX_NUM];	// �؂̍��W
	int WoodStandPosX, WoodStandPosY;					// �؂̍��̍��W
	//int TwigPosX[TWIG_MAX_NUM], TwigPosY[TWIG_MAX_NUM];	// �}�̍��W

public:
	Wood();
	~Wood();

	// �v���C�V�[���̏�����
	void Init();

	// �v���C�V�[���ʏ폈��
	void Step();

	// �v���C�V�[���`�揈��
	void Draw();

	// �v���C�V�[���I������
	void Fin();
};
