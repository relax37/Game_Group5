// 小田
#pragma once

class Timer {
private:
	// タイマーの座標
	int TimerPosX, TimerPosY;

	// タイマーのサイズ
	int TimerWidth;
	int TimerHeight;

	// タイマーの速さ
	int TimerMinusSpeed;
	int TimerPlusSpeed;

	// カウント変数
	int CountNum;

public:
	Timer();
	~Timer();

	// Timerの初期化
	void Init();

	// Timer通常処理
	void Step();

	// Timer描画処理
	void Draw();

	// Timer終了処理
	void Fin();
};

