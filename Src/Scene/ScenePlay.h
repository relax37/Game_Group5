#pragma once
#include "../Wood/Wood.h"
#include "../Player/Player.h"

// 画像パス
// プレイ背景
#define PLAY_BG_PATH "Data/Image/BackGround/TentativePlayBG.png"

class ScenePlay {
private:
	int PlayBGHandle;									// プレイ背景ハンドル

	// Class
	Player CPlayer;
	Wood CWood;

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
};
