// 小田
#include "DxLib.h"
#include "../Scene/Scene.h"
#include "Timer.h"
#include "../InputMouse/InputMouse.h"

Timer::Timer()
{
	// タイマーの座標
	TimerPosX = TimerPosY = 0;

	// タイマーのサイズ
	TimerWidth = 0;
	TimerHeight = 0;

	// カウント変数
	CountNum = 0;
}
Timer::~Timer() { Fin(); }

// Timerの初期化
void Timer::Init()
{
	// タイマーの座標
	TimerPosX = WINDOW_WIDTH / 2 - 200;
	TimerPosY = 75;

	// タイマーのサイズ
	TimerWidth = 200;
	TimerHeight = 70;

	// カウント変数
	CountNum = 0;
}

// Timer通常処理
void Timer::Step()
{
	TimerWidth -= 2;

	// 左クリックが押されていれば
	if (IsMouseDown(MOUSE_INPUT_LEFT))
	{
			CountNum++;
		if (CountNum < 4)
		{
			TimerWidth += 8;
		}	
	}
	else 
	{
		CountNum = 0;
	}

	if (TimerWidth >= 400)
	{
		TimerWidth = 400;
	}

	if (TimerWidth <= 0)
	{
		// ゲームオーバーシーンに移動
		g_CurrentSceneID = SCENE_ID_FIN_PLAY;
	}
}

// Timer描画処理
void Timer::Draw()
{
	// タイマー背景
	DrawBox(WINDOW_WIDTH / 2 - 205, 70, WINDOW_WIDTH / 2 + 205, 150, GetColor(230, 152, 101), true);
	DrawBox(WINDOW_WIDTH / 2 - 200, 75, WINDOW_WIDTH / 2 + 200, 145, GetColor(79, 41, 32), true);

	// タイマーゲージ
	DrawBox(TimerPosX, TimerPosY, TimerPosX + TimerWidth, TimerPosY + TimerHeight, GetColor(255, 0, 0), true);
}

// Timer終了処理
void Timer::Fin()
{
	// タイマーの座標
	TimerPosX = 0;
	TimerPosY = 0;

	// タイマーのサイズ
	TimerWidth = 0;
	TimerHeight = 0;

	// カウント変数
	CountNum = 0;
}