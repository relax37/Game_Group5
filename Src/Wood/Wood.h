#pragma once

// ��
#define WOOD_IMG_PATH "Data/Image/Play/wood.png"
#define WOODSTAND_IMG_PATH "Data/Image/Play/woodstand.png"
#define WOOD_MAX_NUM (6)
#define WOOD_SIZE_W (83)
#define WOOD_SIZE_H (69)

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

	int MouseX, MouseY;									// �}�E�X�̍��W

	bool isClick;										// �N���b�N����

	bool isRightMove;									// �E�ɓ�������
	bool isLeftMove;									// ���ɓ�������

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

	// �E�����ɖ؂����
	void WoodMoveRight();

	// �������ɖ؂����
	void WoodMoveLeft();

	// �N���b�N����
	void Click();

	// ���E��ʃN���b�N����
	void ClickLR();
};
