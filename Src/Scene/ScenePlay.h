#pragma once


class ScenePlay {
private:
	
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
