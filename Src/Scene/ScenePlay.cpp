#include "DxLib.h"
#include "Scene.h"
#include "ScenePlay.h"

ScenePlay::ScenePlay() {}
ScenePlay::~ScenePlay() { FinPlay(); }

//�v���C�V�[���̏�����
void ScenePlay::InitPlay()
{

	g_CurrentSceneID = SCENE_ID_LOOP_PLAY;
}

//�v���C�V�[���ʏ폈��
void ScenePlay::StepPlay()
{
	FinPlay();
}

//�v���C�V�[���`�揈��
void ScenePlay::DrawPlay()
{

}

//�v���C�V�[���I������
void ScenePlay::FinPlay()
{

}
