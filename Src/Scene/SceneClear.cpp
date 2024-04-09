#include "DxLib.h"
#include "../Input/Input.h"
#include "Scene.h"
#include "SceneClear.h"

SceneClear::SceneClear() {}
SceneClear::~SceneClear() {}

//クリアシーン初期化
void SceneClear::InitClear()
{

	//クリアシーンループへ
	g_CurrentSceneID = SCENE_ID_LOOP_CLEAR;
}

//クリアシーン通常処理
void SceneClear::StepClear()
{
	// タイトルに戻る
	FinClear();
}

//クリアシーン描画処理
void SceneClear::DrawClear()
{

}

//クリアシーン終了処理
void SceneClear::FinClear()
{
	//タイトルシーンへ移動
	g_CurrentSceneID = SCENE_ID_INIT_TITLE;
}
