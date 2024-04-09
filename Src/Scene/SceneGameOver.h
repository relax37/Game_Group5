#pragma once

class SceneGameOver {
private:
	

public:
	SceneGameOver();
	~SceneGameOver();

	//ゲームオーバーシーン初期化
	void InitGameOver();

	//ゲームオーバーシーン通常処理
	void StepGameOver();

	//ゲームオーバーシーン描画処理
	void DrawGameOver();

	//ゲームオーバーシーン終了処理
	void FinGameOver();
};
