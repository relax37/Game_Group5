#include "DxLib.h"
#include "../Input/Input.h"
#include "Scene.h"
#include "SceneTitle.h"

SceneTitle::SceneTitle() {}
SceneTitle::~SceneTitle() {}

// タイトルの初期化
void SceneTitle::InitTitle()
{

	// タイトルループへ
	g_CurrentSceneID = SCENE_ID_LOOP_TITLE;
}

// タイトル通常処理
void SceneTitle::StepTitle()
{
	FinTitle();
}

// タイトル描画処理
void SceneTitle::DrawTitle()
{

}

// タイトル終了処理
void SceneTitle::FinTitle()
{
	
	// プレイシーンに移動
	g_CurrentSceneID = SCENE_ID_INIT_PLAY;
}
