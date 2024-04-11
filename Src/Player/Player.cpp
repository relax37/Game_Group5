#include "DxLib.h"
#include "../Scene/Scene.h"
#include "Player.h"
#include "../Collision/Collision.h"

Player::Player()
{
	PlayerStandImgHandle = 0;		// �v���C���[(�ҋ@)�摜�n���h��
	PlayerCutImgHandle = 0;			// �v���C���[(�؂�)�摜�n���h��

	PlayerPosX = PlayerPosY = 0;	// �v���C���[�̍��W

	isLeftorRight = 0;				// ���E����	
	isCut = 0;						// ���]����
}
Player::~Player() { Fin(); }

// �v���C�V�[���̏�����
void Player::Init()
{
	// �v���C���[(�ҋ@)�摜�n���h��
	PlayerStandImgHandle = LoadGraph(PLAYER_STAND_IMG_PATH);
	// �v���C���[(�؂�)�摜�n���h��
	PlayerCutImgHandle = LoadGraph(PLAYER_CUT_IMG_PATH);

	PlayerPosX = WINDOW_WIDTH * 2 / 5;	// �v���C���[��X���W
	PlayerPosY = WINDOW_HEIGHT - 100;	// �v���C���[��Y���W

	isLeftorRight = true;				// ���E����	(����(true)�͍�)
	isCut = false;						// �؂锻��
}

// �v���C�V�[���ʏ폈��
void Player::Step()
{

}

// �v���C�V�[���`�揈��
void Player::Draw()
{
	// ��������ł����
	if (isLeftorRight == true)
	{
		// �؂锻�肪�^�ł����
		if (isCut == true)
		{
			DrawRotaGraph(PlayerPosX, PlayerPosY, 1.0f, 0.0f, PlayerCutImgHandle, true, false);
		}
		// �؂锻�肪�U�ł����
		if (isCut == false)
		{
			DrawRotaGraph(PlayerPosX, PlayerPosY, 1.0f, 0.0f, PlayerStandImgHandle, true, false);
		}
		
	}
	// �E������ł����
	if (isLeftorRight == false)
	{
		// �؂锻�肪�^�ł����
		if (isCut == true)
		{
			DrawRotaGraph(PlayerPosX, PlayerPosY, 1.0f, 0.0f, PlayerCutImgHandle, true, true);
		}
		// �؂锻�肪�U�ł����
		if (isCut == false)
		{
			DrawRotaGraph(PlayerPosX, PlayerPosY, 1.0f, 0.0f, PlayerStandImgHandle, true, false);
		}

	}
}

// �v���C�V�[���I������
void Player::Fin()
{
	DeleteGraph(PlayerStandImgHandle);		// �v���C���[(�ҋ@)�摜�n���h��
	DeleteGraph(PlayerCutImgHandle); 		// �v���C���[(�؂�)�摜�n���h��

	PlayerPosX = PlayerPosY = 0;			// �v���C���[�̍��W

	isLeftorRight = 0;						// ���E����	
	isCut = 0;								// ���]����

}

// ���E��ʃN���b�N����
void Player::ClickLR()
{

}