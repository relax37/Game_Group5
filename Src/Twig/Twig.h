// ���c
#pragma once

// �}
#define TWIG_IMG_PATH "Data/Image/Play/twig.png"
#define TWIG_LEFT_MAX_NUM (8)
#define TWIG_RIGHT_MAX_NUM (6)

#define RANDOM_NUM (5)

class Twig {
private:
	int TwigImgHandle;														// �}�̉摜�n���h��

	int TwigLeftPosX[TWIG_LEFT_MAX_NUM], TwigLeftPosY[TWIG_LEFT_MAX_NUM];	// �}�̍��W
	int TwigRightPosX[TWIG_RIGHT_MAX_NUM], TwigRightPosY[TWIG_RIGHT_MAX_NUM];// �}�̍��W

	bool isDrawLeft[TWIG_LEFT_MAX_NUM];										// �`�攻��
	bool isDrawRight[TWIG_RIGHT_MAX_NUM];									// �`�攻��

	int Random;																// �����_���ϐ�

	int CountNum;															// �J�E���g�ϐ�

	int CountNum2;															// �J�E���g�ϐ�2
		
public:
	Twig();
	~Twig();

	// Twig�̏�����
	void Init();

	// Twig�ʏ폈��
	void Step();

	// Twig�`�揈��
	void Draw();

	// Twig�I������
	void Fin();

	// �}(��)�̈ړ�����
	void MoveLeftTwig();

	// �}(�E)�̈ړ�����
	void MoveRightTwig();

	// �N���b�N����
	void Click();

	// �v���C���[�Ǝ}�̓����蔻��
	void Player_TwigCollision(int PlayerPosX, int PlayerPosY);
};

