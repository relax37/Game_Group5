#include "DxLib.h"
#include "../Scene/Scene.h"
#include "Player.h"
#include "../Collision/Collision.h"

Player::Player()
{
	PlayerStandImgHandle = 0;		// �v���C���[(�ҋ@)�摜�n���h��
	PlayerCutImgHandle = 0;			// �v���C���[(�؂�)�摜�n���h��

	PlayerPosX = PlayerPosY = 0;	// �v���C���[�̍��W

	MouseX = MouseY = 0;			// �}�E�X�̍��W

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

	PlayerPosX = WINDOW_WIDTH / 3 + 50;	// �v���C���[��X���W
	PlayerPosY = WINDOW_HEIGHT - 150;	// �v���C���[��Y���W

	MouseX = MouseY = 0;				// �}�E�X�̍��W

	isLeftorRight = true;				// ���E����	(����(true)�͍�)
	isCut = false;						// �؂锻��
}

// �v���C�V�[���ʏ폈��
void Player::Step()
{
	GetMousePoint(&MouseX, &MouseY);	// �}�E�X�̍��W���擾

	// ���E���W�ݒ�
	SetLRMousePos();

	// ���E��ʃN���b�N����
	ClickLR();
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

	// debug
	/*DrawFormatString(0, 0, GetColor(255, 0, 0), "%d, %d", MouseX, MouseY);*/
}

// �v���C�V�[���I������
void Player::Fin()
{
	DeleteGraph(PlayerStandImgHandle);		// �v���C���[(�ҋ@)�摜�n���h��
	DeleteGraph(PlayerCutImgHandle); 		// �v���C���[(�؂�)�摜�n���h��

	PlayerPosX = PlayerPosY = 0;			// �v���C���[�̍��W

	MouseX = MouseY = 0;					// �}�E�X�̍��W

	isLeftorRight = 0;						// ���E����	
	isCut = 0;								// ���]����
}

// ���E���W�ݒ�
void Player::SetLRMousePos()
{
	// ���E���肪���ł����
	if (isLeftorRight == true)
	{
		PlayerPosX = WINDOW_WIDTH / 3 + 50;	// �v���C���[��X���W
		PlayerPosY = WINDOW_HEIGHT - 150;	// �v���C���[��Y���W
	}
	// ���E���肪�E�ł����
	if (isLeftorRight == false)
	{
		PlayerPosX = WINDOW_WIDTH - WINDOW_WIDTH / 3 - 50;	// �v���C���[��X���W
		PlayerPosY = WINDOW_HEIGHT - 150;					// �v���C���[��Y���W
	}
}

// ���E��ʃN���b�N����
void Player::ClickLR()
{
	// �����Ƀ}�E�X�J�[�\��������Ƃ�
	if (Collision::Rect_Dot(0, 0, WINDOW_WIDTH / 2, WINDOW_HEIGHT, MouseX, MouseY))
	{
		// ���N���b�N��������Ă����
		if (IsMouseClick(MOUSE_INPUT_LEFT))
		{
			isLeftorRight = true;				// ���E���������
			isCut = true;						// �؂锻���true��
		}
		// ���N���b�N��������Ă��Ȃ����
		else
		{
			isCut = false;						// �؂锻���false��
		}
	}

	// �����Ƀ}�E�X�J�[�\��������Ƃ�
	if (Collision::Rect_Dot(WINDOW_WIDTH / 2, 0, WINDOW_WIDTH / 2, WINDOW_HEIGHT, MouseX, MouseY))
	{
		// ���N���b�N��������Ă����
		if (IsMouseClick(MOUSE_INPUT_LEFT))
		{
			isLeftorRight = false;				// ���E���������
			isCut = true;						// �؂锻���true��
		}
		// ���N���b�N��������Ă��Ȃ����
		else
		{
			isCut = false;						// �؂锻���false��
		}
	}
}