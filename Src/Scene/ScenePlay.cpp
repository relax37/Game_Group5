// 小田
#include "DxLib.h"
#include "Scene.h"
#include "ScenePlay.h"

ScenePlay::ScenePlay()
{
	// プレイ背景ハンドル
	PlayBGHandle = 0;

	// フォントハンドル
	FontHandle = 0;
}
ScenePlay::~ScenePlay() { FinPlay(); }

//プレイシーンの初期化
void ScenePlay::InitPlay()
{
	// プレイ背景ハンドル
	PlayBGHandle = LoadGraph(PLAY_BG_PATH);

	// フォント設定
	FontHandle = CreateFontToHandle("HGP創英ﾌﾟﾚｾﾞﾝｽEB", 48, 3, DX_FONTTYPE_NORMAL);

	// プレイヤーの初期化
	CPlayer.Init();

	// 木の初期化
	CWood.Init();

	// タイマーの初期化
	CTimer.Init();

	g_CurrentSceneID = SCENE_ID_LOOP_PLAY;
}

//プレイシーン通常処理
void ScenePlay::StepPlay()
{
	// プレイヤーの通常処理
	CPlayer.Step();

	// 木の通常処理
	CWood.Step();

	// タイマーの通常処理
	CTimer.Step();

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

	// タイマーの描画処理
	CTimer.Draw();

	// スコアを表示
	DrawScore();
}

//プレイシーン終了処理
void ScenePlay::FinPlay()
{
	// タイトル背景ハンドル
	DeleteGraph(PlayBGHandle);

	// フォントハンドル
	FontHandle = 0;

	// プレイヤーの終了処理
	CPlayer.Fin();

	// 木の終了処理
	CWood.Fin();

	// タイマーの終了処理
	CTimer.Fin();

	// クリアシーンに移動
	g_CurrentSceneID = SCENE_ID_INIT_GAMEOVER;
}

// スコアを表示する
void ScenePlay::DrawScore()
{
	if (Score >= 0 && Score < 10)
	{
		DrawFormatStringToHandle(WINDOW_WIDTH / 2 - 9, WINDOW_HEIGHT / 4, GetColor(255, 255, 255), FontHandle, "%d", Score);
	}
	else if(Score >= 10 && Score < 100)
	{
		DrawFormatStringToHandle(WINDOW_WIDTH / 2 - 17, WINDOW_HEIGHT / 4, GetColor(255, 255, 255), FontHandle, "%d", Score);
	}
	else if (Score >= 100 && Score < 1000)
	{
		DrawFormatStringToHandle(WINDOW_WIDTH / 2 - 33, WINDOW_HEIGHT / 4, GetColor(255, 255, 255), FontHandle, "%d", Score);
	}
}
