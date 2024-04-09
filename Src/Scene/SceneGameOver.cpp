#include "DxLib.h"
#include "../Input/Input.h"
#include "Scene.h"
#include "SceneGameOver.h"

SceneGameOver::SceneGameOver(){}
SceneGameOver::~SceneGameOver() {}

//ゲームオーバーシーン初期化
void SceneGameOver::InitGameOver()
{
	
	//ゲームオーバーループへ
	g_CurrentSceneID = SCENE_ID_LOOP_GAMEOVER;
}

//ゲームオーバーシーン通常処理
void SceneGameOver::StepGameOver()
{
	FinGameOver();
}

//ゲームオーバーシーン描画処理
void SceneGameOver::DrawGameOver()
{

}

//ゲームオーバーシーン終了処理
void SceneGameOver::FinGameOver()
{

	//タイトルシーンへ移動
	g_CurrentSceneID = SCENE_ID_INIT_TITLE;
}
