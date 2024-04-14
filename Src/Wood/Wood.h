// ���c
#pragma once

// ��
#define WOOD_IMG_PATH "Data/Image/Play/wood.png"
#define WOODSTAND_IMG_PATH "Data/Image/Play/woodstand.png"
#define WOOD_MAX_NUM (6)
#define WOOD_SIZE_W (83)
#define WOOD_SIZE_H (69)

class Wood {
private:
	int WoodImgHandle;										// �؂̉摜�n���h��
	int WoodStandImgHandle;									// �؂̍��̉摜�n���h��
		
	int WoodPosX[WOOD_MAX_NUM], WoodPosY[WOOD_MAX_NUM];		// �؂̍��W
	int WoodStandPosX, WoodStandPosY;						// �؂̍��̍��W

	int MouseX, MouseY;										// �}�E�X�̍��W

	int CountNum;											// �J�E���g�ϐ�

public:
	Wood();
	~Wood();

	// Wood�̏�����
	void Init();

	// Wood�ʏ폈��
	void Step();

	// Wood�`�揈��
	void Draw();

	// Wood�I������
	void Fin();

	// �E�����ɖ؂����
	void WoodMoveRight();

	// �������ɖ؂����
	void WoodMoveLeft();

	// �؂̍��W�̍Đݒ�
	void ResetWoodPos();

	// ���E��ʃN���b�N����
	void ClickLR();
};
