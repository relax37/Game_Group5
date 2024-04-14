// ���c
#pragma once

#define PLAYER_STAND_IMG_PATH "Data/Image/Play/stand.png"
#define PLAYER_CUT_IMG_PATH "Data/Image/Play/cut.png"

class Player {
private:
	int PlayerStandImgHandle;		// �v���C���[(�ҋ@)�摜�n���h��
	int PlayerCutImgHandle;			// �v���C���[(�؂�)�摜�n���h��

	int PlayerPosX, PlayerPosY;		// �v���C���[�̍��W

	int MouseX, MouseY;				// �}�E�X�̍��W

	bool isLeftorRight;				// ���E����
	bool isCut;						// �؂锻��

public:
	Player();
	~Player();

	// �v���C���[�̏�����
	void Init();

	// �v���C���[�ʏ폈��
	void Step();

	// �v���C���[�`�揈��
	void Draw();

	// �v���C���[�I������
	void Fin();

	// ���E���W�ݒ�
	void SetLRMousePos();

	// ���E��ʃN���b�N����
	void ClickLR();
};
