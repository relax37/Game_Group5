#include "DxLib.h"
#include "Scene.h"
#include "SceneGameOver.h"

SceneGameOver::SceneGameOver()
{
	// �Q�[���I�[�o�[�w�i�n���h��
	GameOverBGHandle = 0;
}
SceneGameOver::~SceneGameOver() { FinGameOver(); }

//�Q�[���I�[�o�[�V�[��������
void SceneGameOver::InitGameOver()
{
	// �Q�[���I�[�o�[�w�i�n���h��
	GameOverBGHandle = LoadGraph(GAMEOVER_BG_PATH);

	//�Q�[���I�[�o�[���[�v��
	g_CurrentSceneID = SCENE_ID_LOOP_GAMEOVER;
}

//�Q�[���I�[�o�[�V�[���ʏ폈��
void SceneGameOver::StepGameOver()
{

	// Enter����������
	if (InputKey::Push(KEY_INPUT_RETURN))
	{
		// �Q�[���I�[�o�[�V�[�����I��
		FinGameOver();
	}
}

//�Q�[���I�[�o�[�V�[���`�揈��
void SceneGameOver::DrawGameOver()
{
	// �Q�[���I�[�o�[�w�i�`��
	DrawGraph(0, 0, GameOverBGHandle, true);
}

//�Q�[���I�[�o�[�V�[���I������
void SceneGameOver::FinGameOver()
{
	// �Q�[���I�[�o�[�w�i�n���h��
	DeleteGraph(GameOverBGHandle);

	// �X�R�A�̏�����
	Score = 0;

	//�^�C�g���V�[���ֈړ�
	g_CurrentSceneID = SCENE_ID_INIT_TITLE;
}
