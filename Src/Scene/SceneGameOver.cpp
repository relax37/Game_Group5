#include "DxLib.h"
#include "../Input/Input.h"
#include "Scene.h"
#include "SceneGameOver.h"

SceneGameOver::SceneGameOver(){}
SceneGameOver::~SceneGameOver() {}

//�Q�[���I�[�o�[�V�[��������
void SceneGameOver::InitGameOver()
{
	
	//�Q�[���I�[�o�[���[�v��
	g_CurrentSceneID = SCENE_ID_LOOP_GAMEOVER;
}

//�Q�[���I�[�o�[�V�[���ʏ폈��
void SceneGameOver::StepGameOver()
{
	FinGameOver();
}

//�Q�[���I�[�o�[�V�[���`�揈��
void SceneGameOver::DrawGameOver()
{

}

//�Q�[���I�[�o�[�V�[���I������
void SceneGameOver::FinGameOver()
{

	//�^�C�g���V�[���ֈړ�
	g_CurrentSceneID = SCENE_ID_INIT_TITLE;
}
