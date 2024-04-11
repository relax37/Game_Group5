#pragma once

#define PLAYER_STAND_IMG_PATH "Data/Play/stand.png"
#define PLAYER_CUT_IMG_PATH "Data/Play/cut.png"

class Player {
private:
	int PlayerStandImgHandle;		// �v���C���[(�ҋ@)�摜�n���h��
	int PlayerCutImgHandle;			// �v���C���[(�؂�)�摜�n���h��

	int PlayerPosX, PlayerPosY;		// �v���C���[�̍��W

	bool isLeftorRight;				// ���E����
	bool isCut;						// �؂锻��

public:
	Player();
	~Player();

	// �v���C�V�[���̏�����
	void Init();

	// �v���C�V�[���ʏ폈��
	void Step();

	// �v���C�V�[���`�揈��
	void Draw();

	// �v���C�V�[���I������
	void Fin();

	// ���E��ʃN���b�N����
	void ClickLR();
};
