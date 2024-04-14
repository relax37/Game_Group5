// 小田
#include "DxLib.h"
#include "../Scene/Scene.h"
#include "Twig.h"
#include "../Collision/Collision.h"

Twig::Twig()
{
	// 枝の画像ハンドル
	TwigImgHandle = 0;

	for (int TwigIndex = 0; TwigIndex < TWIG_LEFT_MAX_NUM; TwigIndex++)
	{
		// 枝の座標
		TwigLeftPosX[TwigIndex] = 0;
		TwigLeftPosY[TwigIndex] = 0;

		// 描画判定
		isDrawLeft[TwigIndex] = 0;
	}

	for (int TwigIndex = 0; TwigIndex < TWIG_RIGHT_MAX_NUM; TwigIndex++)
	{
		// 枝の座標
		TwigRightPosX[TwigIndex] = 0;
		TwigRightPosY[TwigIndex] = 0;

		// 描画判定
		isDrawRight[TwigIndex] = 0;
	}

	// ランダム変数
	Random = 0;

	// カウント変数
	CountNum = 0;
}
Twig::~Twig() { Fin(); }

//プレイシーンの初期化
void Twig::Init()
{
	// 枝の画像ハンドル
	TwigImgHandle = LoadGraph(TWIG_IMG_PATH);

	for (int TwigIndex = 0; TwigIndex < TWIG_LEFT_MAX_NUM; TwigIndex++)
	{
		Random = GetRand(1);

		// 描画判定
		if (Random == 1)
		{
			isDrawLeft[TwigIndex] = true;
		}
		else
		{
			isDrawLeft[TwigIndex] = false;
		}
	}

	// 枝の座標
	TwigLeftPosX[0] = WINDOW_WIDTH / 3 + 50;
	TwigLeftPosY[0] = (WINDOW_HEIGHT - 156) - 69 * 3;

	TwigLeftPosX[1] = WINDOW_WIDTH / 3 + 50;
	TwigLeftPosY[1] = (WINDOW_HEIGHT - 156) - 69 * 4;

	TwigLeftPosX[2] = WINDOW_WIDTH / 3 + 50;
	TwigLeftPosY[2] = (WINDOW_HEIGHT - 156) - 69 * 9;

	TwigLeftPosX[3] = WINDOW_WIDTH / 3 + 50;
	TwigLeftPosY[3] = (WINDOW_HEIGHT - 156) - 69 * 10;

	TwigLeftPosX[4] = WINDOW_WIDTH / 3 + 50;
	TwigLeftPosY[4] = (WINDOW_HEIGHT - 156) - 69 * 11;

	TwigLeftPosX[5] = WINDOW_WIDTH / 3 + 50;
	TwigLeftPosY[5] = (WINDOW_HEIGHT - 156) - 69 * 12;

	TwigLeftPosX[6] = WINDOW_WIDTH / 3 + 50;
	TwigLeftPosY[6] = (WINDOW_HEIGHT - 156) - 69 * 13;

	TwigLeftPosX[7] = WINDOW_WIDTH / 3 + 50;
	TwigLeftPosY[7] = (WINDOW_HEIGHT - 156) - 69 * 14;

	for (int TwigIndex = 0; TwigIndex < TWIG_RIGHT_MAX_NUM; TwigIndex++)
	{
		Random = GetRand(1);

		// 描画判定
		if (Random == 1)
		{
			isDrawRight[TwigIndex] = true;
		}
		else
		{
			isDrawRight[TwigIndex] = false;
		}
	}

	// 枝の座標
	TwigRightPosX[0] = WINDOW_WIDTH - WINDOW_WIDTH / 3 - 50;
	TwigRightPosY[0] = (WINDOW_HEIGHT - 156);

	TwigRightPosX[1] = WINDOW_WIDTH - WINDOW_WIDTH / 3 - 50;
	TwigRightPosY[1] = (WINDOW_HEIGHT - 156) - 69;

	TwigRightPosX[2] = WINDOW_WIDTH - WINDOW_WIDTH / 3 - 50;
	TwigRightPosY[2] = (WINDOW_HEIGHT - 156) - 69 * 6;

	TwigRightPosX[3] = WINDOW_WIDTH - WINDOW_WIDTH / 3 - 50;
	TwigRightPosY[3] = (WINDOW_HEIGHT - 156) - 69 * 7;

	TwigRightPosX[4] = WINDOW_WIDTH - WINDOW_WIDTH / 3 - 50;
	TwigRightPosY[4] = (WINDOW_HEIGHT - 156) - 69 * 16;

	TwigRightPosX[5] = WINDOW_WIDTH - WINDOW_WIDTH / 3 - 50;
	TwigRightPosY[5] = (WINDOW_HEIGHT - 156) - 69 * 17;

	// カウント変数
	CountNum = 0;
}

//プレイシーン通常処理
void Twig::Step()
{
	// 枝(左)の移動処理
	MoveLeftTwig();

	// 枝(右)の移動処理
	MoveRightTwig();

	// クリック判定
	Click();
}

//プレイシーン描画処理
void Twig::Draw()
{
	for (int TwigIndex = 0; TwigIndex < TWIG_LEFT_MAX_NUM; TwigIndex++)
	{
		if (isDrawLeft[TwigIndex] == true)
		{
			// 枝の画像描画
			DrawRotaGraph(TwigLeftPosX[TwigIndex], TwigLeftPosY[TwigIndex], 1.0f, 0.0f, TwigImgHandle, true, false);
		}

	}

	for (int TwigIndex = 0; TwigIndex < TWIG_RIGHT_MAX_NUM; TwigIndex++)
	{
		if (isDrawRight[TwigIndex] == true)
		{
			// 枝の画像描画
			DrawRotaGraph(TwigRightPosX[TwigIndex], TwigRightPosY[TwigIndex], 1.0f, 0.0f, TwigImgHandle, true, true);
		}

	}
}

//プレイシーン終了処理
void Twig::Fin()
{
	// 枝の画像ハンドル
	DeleteGraph(TwigImgHandle);

	for (int TwigIndex = 0; TwigIndex < TWIG_LEFT_MAX_NUM; TwigIndex++)
	{
		// 枝の座標
		TwigLeftPosX[TwigIndex] = 0;
		TwigLeftPosY[TwigIndex] = 0;

		// 描画判定
		isDrawLeft[TwigIndex] = 0;
	}

	for (int TwigIndex = 0; TwigIndex < TWIG_RIGHT_MAX_NUM; TwigIndex++)
	{
		// 枝の座標
		TwigRightPosX[TwigIndex] = 0;
		TwigRightPosY[TwigIndex] = 0;

		// 描画判定
		isDrawRight[TwigIndex] = 0;
	}

	// ランダム変数
	Random = 0;

	// カウント変数
	CountNum = 0;
}

// 枝(左)の移動処理
void Twig::MoveLeftTwig()
{
	// LeftTwig1
	for (int TwigIndex = 0; TwigIndex < TWIG_LEFT_MAX_NUM; TwigIndex++)
	{
		if (TwigLeftPosY[TwigIndex] >= WINDOW_HEIGHT - 156)
		{
			Random = GetRand(1);

			TwigLeftPosY[TwigIndex] = (WINDOW_HEIGHT - 156) - 69 * 19;

			if (Random == 1)
			{
				isDrawLeft[TwigIndex] = true;
			}
			else
			{
				isDrawLeft[TwigIndex] = false;
			}
		}
	}


	// LeftTwig2

	// LeftTwig3

	// LeftTwig4

	// LeftTwig5

	// LeftTwig6

	// LeftTwig7

	// LeftTwig8
}

// 枝(右)の移動処理
void Twig::MoveRightTwig()
{
	// RightTwig1
	for (int TwigIndex = 0; TwigIndex < TWIG_RIGHT_MAX_NUM; TwigIndex++)
	{
		if (TwigRightPosY[TwigIndex] >= WINDOW_HEIGHT - 156)
		{
			Random = GetRand(1);

			TwigRightPosY[TwigIndex] = (WINDOW_HEIGHT - 156) - 69 * 19;

			if (Random == 1)
			{
				isDrawRight[TwigIndex] = true;
			}
			else
			{
				isDrawRight[TwigIndex] = false;
			}
		}
	}

	// RightTwig2

	// RightTwig3

	// RightTwig4

	// RightTwig5

	// RightTwig6
}

// 左右画面クリック判定
void Twig::Click()
{
	// 左クリックが押されていれば
	if (IsMouseDown(MOUSE_INPUT_LEFT))
	{
		CountNum++;

		if (CountNum <= 1)
		{
			for (int TwigIndex = 0; TwigIndex < TWIG_LEFT_MAX_NUM; TwigIndex++)
			{
				// 枝の座標
				TwigLeftPosY[TwigIndex] += 69;
			}

			for (int TwigIndex = 0; TwigIndex < TWIG_RIGHT_MAX_NUM; TwigIndex++)
			{
				// 枝の座標
				TwigRightPosY[TwigIndex] += 69;
			}
		}
	}
	else
	{
		CountNum = 0;
	}
}
