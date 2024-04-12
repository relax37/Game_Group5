#include "DxLib.h"					// DX���C�u�����̃C���N���[�h
#include "FrameRate/FrameRate.h"	// �t���[�����[�g�̃C���N���[�h
#include "Input/Input.h"			// �C���v�b�g�n�̃C���N���[�h
#include "Scene/Scene.h"			// �V�[���w�b�_�[�̃C���N���[�h
#include "Scene/SceneClear.h"		// �N���A�V�[���̃C���N���[�h
#include "Scene/SceneGameOver.h"	// �Q�[���I�[�o�[�̃C���N���[�h
#include "Scene/ScenePlay.h"		//  �V�[���v���C�̃C���N���[�h
#include "Scene/SceneTitle.h"		// �V�[���^�C�g���̃C���N�E�[�h

// ���݂̃V�[��ID
SCENE_ID g_CurrentSceneID = SCENE_ID_INIT_TITLE;

// Win32�A�v���P�[�V������ WinMain�֐� ����n�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//�E�B���h�E�̏�Ԃ�ݒ肷��
	ChangeWindowMode(true);

	//DX���C�u�����̏�����
	if (DxLib_Init() == -1) {
		return -1;
	}

	// ��ʃT�C�Y��ύX
	SetGraphMode(WINDOW_WIDTH, WINDOW_HEIGHT, 32);

	//�`�悷��X�N���[����ݒ肷��
	SetDrawScreen(DX_SCREEN_BACK);

	//���͐��䏉����
	InitInput();
	InitInputMouse();
	
	//Class
	SceneTitle    Title;
	ScenePlay     Play;
	SceneClear    Clear;
	SceneGameOver GameOver;

	//�Q�[�����C�����[�v
	while (ProcessMessage() != -1)
	{
		Sleep(1);	//�V�X�e���ɏ�����Ԃ�

		//FPS����
		ProcessingFPS();

		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
		{
			//�G�X�P�[�v�L�[�������ꂽ��I��
			break;
		}

		//��ʂɕ\�����ꂽ���̂�������
		ClearDrawScreen();

		//���͐���X�e�b�v
		StepInput();
		StepInputMouse();

		//�V�[��ID�ɂ���ď����̐U�蕪��
		switch (g_CurrentSceneID)
		{

		case SCENE_ID_INIT_TITLE:
		{
			//�^�C�g��������
			Title.InitTitle();

		}//SCENE_ID_TITLE�I���̊���
		break;

		case SCENE_ID_LOOP_TITLE:
		{
			//�^�C�g���`�揈��
			Title.DrawTitle();

			//�^�C�g���ʏ폈��
			Title.StepTitle();

		}//SCENE_ID_TITLE�I���̊���
		break;

		case SCENE_ID_FIN_TITLE:
		{
			//�^�C�g���I������
			Title.FinTitle();
		}
		break;

		case SCENE_ID_INIT_PLAY:
		{
			//�v���C�V�[���̏�����
			Play.InitPlay();

		}//SCENE_ID_INIT_PLAY

		break;

		case SCENE_ID_LOOP_PLAY:
		{
			//�v���C�V�[���ʏ폈��
			Play.StepPlay();

			//�v���C�V�[���`�揈��
			Play.DrawPlay();

		}//SCENE_ID_LOOP_PLAY�I���̊���
		break;

		case SCENE_ID_FIN_PLAY:
		{
			//�v���C�V�[���I������
			Play.FinPlay();
		}
		break;

		case SCENE_ID_INIT_CLEAR:
		{
			//�N���A�V�[��������
			Clear.InitClear();

		}//SCENE_ID_INIT_CLEAR�I���̊���
		break;

		case SCENE_ID_LOOP_CLEAR:
		{
			//�N���A�V�[���ʏ폈��
			Clear.StepClear();

			//�N���A�V�[���`�揈��
			Clear.DrawClear();

		}//SCENE_ID_LOOP_CLEAR�I���̊���
		break;

		case SCENE_ID_FIN_CLEAR:
		{
			//�N���A�V�[���I������
			Clear.FinClear();
		}
		break;

		case SCENE_ID_INIT_GAMEOVER:
		{

			//�Q�[���I�[�o�[�V�[��������
			GameOver.InitGameOver();

		}//SCENE_ID_INIT_CLEAR�I���̊���
		break;

		case SCENE_ID_LOOP_GAMEOVER:
		{

			//�Q�[���I�[�o�[�V�[���ʏ폈��
			GameOver.StepGameOver();

			//�Q�[���I�[�o�[�V�[���`�揈��
			GameOver.DrawGameOver();

		}//SCENE_ID_LOOP_CLEAR�I���̊���
		break;

		case SCENE_ID_FIN_GAMEOVER:
		{

			//�Q�[���I�[�o�[�V�[���I������
			GameOver.FinGameOver();

		}//SCENE_ID_FIN_CLEAR�I���̊���
		break;

		}//�V�[���U�蕪����switch��

		//FPS�v�Z
		CalcFPS();

		//FPS�\��
		DrawFPS();

		ScreenFlip();
		
	}

	//�Ō�ɂP�񂾂���鏈���������ɏ���
	//DX���C�u�����̌㏈��
	DxLib_End();

	return 0;
}

