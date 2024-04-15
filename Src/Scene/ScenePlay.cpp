// 小田
#include "DxLib.h"
#include "Scene.h"
#include "ScenePlay.h"
#include "../InputMouse/InputMouse.h"

ScenePlay::ScenePlay()
{
	// プレイ背景ハンドル
	PlayBGHandle = 0;

	// フォントハンドル
	FontHandle = 0;

	// サウンドハンドル
	SoundHandle = 0;

	// クリックスタート判定
	isClickStart = 0;
}
ScenePlay::~ScenePlay() { FinPlay(); }

//プレイシーンの初期化
void ScenePlay::InitPlay()
{
	// プレイ背景ハンドル
	PlayBGHandle = LoadGraph(PLAY_BG_PATH);

	// フォント設定
	FontHandle = CreateFontToHandle("HGP創英ﾌﾟﾚｾﾞﾝｽEB", 48, 3, DX_FONTTYPE_NORMAL);

	// サウンド
	SoundHandle = LoadSoundMem(PLAY_BGM_PATH);

	//BGM&SE
	PlaySoundMem(SoundHandle, DX_PLAYTYPE_LOOP, true);

	//bgm音量調整
	ChangeVolumeSoundMem(100, SoundHandle);

	// プレイヤーの初期化
	CPlayer.Init();

	// 木の初期化
	CWood.Init();

	// 枝の初期化
	CTwig.Init();

	// タイマーの初期化
	CTimer.Init();

	// クリックスタート判定
	isClickStart = false;

	g_CurrentSceneID = SCENE_ID_LOOP_PLAY;
}

//プレイシーン通常処理
void ScenePlay::StepPlay()
{
	// クリック判定
	Click();

	if (isClickStart == true)
	{
		// プレイヤーの通常処理
		CPlayer.Step();

		// 木の通常処理
		CWood.Step();

		// 枝の通常処理
		CTwig.Step();

		// プレイヤーと枝の当たり判定
		CTwig.Player_TwigCollision(CPlayer.GetPlayerPosX(), CPlayer.GetPlayerPosY());

		// タイマーの通常処理
		CTimer.Step();
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

	// 枝の描画処理
	CTwig.Draw();

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

	DeleteSoundMem(SoundHandle);

	// フォントハンドル
	FontHandle = 0;

	// プレイヤーの終了処理
	CPlayer.Fin();

	// 木の終了処理
	CWood.Fin();

	// 枝の終了処理
	CTwig.Fin();

	// タイマーの終了処理
	CTimer.Fin();

	// クリックスタート判定
	isClickStart = 0;

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

// クリック判定
void ScenePlay::Click()
{
	// 左クリックが押されていれば
	if (IsMouseDown(MOUSE_INPUT_LEFT))
	{
		isClickStart = true;
	}
}
