// 小田
#pragma once

#include "../Player/Player.h"
#include "../Wood/Wood.h"
#include "../Twig/Twig.h"
#include "../Timer/Timer.h"

// 画像パス
// プレイ背景
#define PLAY_BG_PATH "Data/Image/BackGround/PlayBG.png"

// サウンドパス
#define PLAY_BGM_PATH "Data/SE&BGM/Play/PlayBGM.mp3"

enum PlaySound {
	PLAY_BGM,
	START_SE,
	CUT_SE,

	SOUND_MAX_NUM,
};

class ScenePlay {
private:
	// プレイ背景ハンドル
	int PlayBGHandle;

	// フォントハンドル
	int FontHandle;

	// サウンドハンドル
	int SoundHandle;

	// Class
	Player CPlayer;
	Wood CWood;
	Twig CTwig;
	Timer CTimer;

	// クリックスタート判定
	bool isClickStart;

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

	// クリック判定
	void Click();
};
