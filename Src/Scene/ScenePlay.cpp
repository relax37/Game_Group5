#include "DxLib.h"
#include "Scene.h"
#include "ScenePlay.h"

ScenePlay::ScenePlay()
{
	// プレイ背景ハンドル
	PlayBGHandle = 0;
}
ScenePlay::~ScenePlay() { FinPlay(); }

//プレイシーンの初期化
void ScenePlay::InitPlay()
{
	// プレイ背景ハンドル
	PlayBGHandle = LoadGraph(PLAY_BG_PATH);

	// プレイヤーの初期化
	CPlayer.Init();

	// 木の初期化
	CWood.Init();

	g_CurrentSceneID = SCENE_ID_LOOP_PLAY;
}

//プレイシーン通常処理
void ScenePlay::StepPlay()
{
	// プレイヤーの通常処理
	CPlayer.Step();

	// 木の通常処理
	CWood.Step();

	// Enterを押したら
	if (InputKey::Push(KEY_INPUT_RETURN))
	{
		// プレイシーンを終了する
		FinPlay();
	}
}

//プレイシーン描画処理
void ScenePlay::DrawPlay()
{
	// タイトル背景描画処理
	DrawGraph(0, 0, PlayBGHandle, true);

	// プレイヤーの描画処理
	CPlayer.Draw();

	// 木の描画処理
	CWood.Draw();
}

//プレイシーン終了処理
void ScenePlay::FinPlay()
{
	// タイトル背景ハンドル
	DeleteGraph(PlayBGHandle);

	// プレイヤーの終了処理
	CPlayer.Fin();

	// 木の終了処理
	CWood.Fin();

	// クリアシーンに移動
	g_CurrentSceneID = SCENE_ID_INIT_CLEAR;
}
