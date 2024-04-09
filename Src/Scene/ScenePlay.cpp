#include "DxLib.h"
#include "Scene.h"
#include "ScenePlay.h"

ScenePlay::ScenePlay() {}
ScenePlay::~ScenePlay() { FinPlay(); }

//プレイシーンの初期化
void ScenePlay::InitPlay()
{

	g_CurrentSceneID = SCENE_ID_LOOP_PLAY;
}

//プレイシーン通常処理
void ScenePlay::StepPlay()
{
	FinPlay();
}

//プレイシーン描画処理
void ScenePlay::DrawPlay()
{

}

//プレイシーン終了処理
void ScenePlay::FinPlay()
{

}
