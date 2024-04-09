#pragma once

class SceneClear {
private:


public:
	SceneClear();
	~SceneClear();

	//クリアシーン初期化
	void InitClear();

	//クリアシーン通常処理
	void StepClear();

	//クリアシーン描画処理
	void DrawClear();

	//クリアシーン終了処理
	void FinClear();
};
