// 小田
#pragma once
#include "../Wood/Wood.h"
#include "../Player/Player.h"
#include "../Timer/Timer.h"

// 画像パス
// プレイ背景
#define PLAY_BG_PATH "Data/Image/BackGround/PlayBG.png"

class ScenePlay {
private:
	// プレイ背景ハンドル
	int PlayBGHandle;

	// フォントハンドル
	int FontHandle;

	// Class
	Player CPlayer;
	Wood CWood;
	Timer CTimer;

public:
	ScenePlay();
	~ScenePlay();

	// プレイシーンの初期化
	void InitPlay();

	// プレイシーン通常処理
	void StepPlay();

	// プレイシーン描画処理
	void DrawPlay();

	// プレイシーン終了処理
	void FinPlay();

	// スコアを表示する
	void DrawScore();
};
