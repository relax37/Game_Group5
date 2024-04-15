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

	// カウント変数2
	CountNum2 = 0;
}
Twig::~Twig() { Fin(); }

//プレイシーンの初期化
void Twig::Init()
{
	// 枝の画像ハンドル
	TwigImgHandle = LoadGraph(TWIG_IMG_PATH);

	for (int TwigIndex = 0; TwigIndex < TWIG_LEFT_MAX_NUM; TwigIndex++)
	{
		Random = GetRand(RANDOM_NUM);

		// 描画判定
		if (Random >= 1)
		{
			isDrawLeft[TwigIndex] = true;
		}
		else
		{
			isDrawLeft[TwigIndex] = false;
		}

		// 枝のX座標
		TwigLeftPosX[TwigIndex] = WINDOW_WIDTH / 3 + 53;
	}

	// 枝のY座標
	TwigLeftPosY[0] = (WINDOW_HEIGHT - 156) - 69 * 3;
	TwigLeftPosY[1] = (WINDOW_HEIGHT - 156) - 69 * 4;
	TwigLeftPosY[2] = (WINDOW_HEIGHT - 156) - 69 * 9;
	TwigLeftPosY[3] = (WINDOW_HEIGHT - 156) - 69 * 10;
	TwigLeftPosY[4] = (WINDOW_HEIGHT - 156) - 69 * 11;
	TwigLeftPosY[5] = (WINDOW_HEIGHT - 156) - 69 * 12;
	TwigLeftPosY[6] = (WINDOW_HEIGHT - 156) - 69 * 13;
	TwigLeftPosY[7] = (WINDOW_HEIGHT - 156) - 69 * 14;

	for (int TwigIndex = 0; TwigIndex < TWIG_RIGHT_MAX_NUM; TwigIndex++)
	{
		Random = GetRand(4);

		// 描画判定
		if (Random >= 1)
		{
			isDrawRight[TwigIndex] = true;
		}
		else
		{
			isDrawRight[TwigIndex] = false;
		}

		// 枝のX座標
		TwigRightPosX[TwigIndex] = WINDOW_WIDTH - WINDOW_WIDTH / 3 - 48;
	}

	// 枝のY座標
	TwigRightPosY[0] = (WINDOW_HEIGHT - 156);
	TwigRightPosY[1] = (WINDOW_HEIGHT - 156) - 69;
	TwigRightPosY[2] = (WINDOW_HEIGHT - 156) - 69 * 6;
	TwigRightPosY[3] = (WINDOW_HEIGHT - 156) - 69 * 7;
	TwigRightPosY[4] = (WINDOW_HEIGHT - 156) - 69 * 16;
	TwigRightPosY[5] = (WINDOW_HEIGHT - 156) - 69 * 17;

	// カウント変数
	CountNum = 0;

	// カウント変数2
	CountNum2 = 0;
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

			// debug
			//DrawBox(TwigLeftPosX[TwigIndex] - 40, TwigLeftPosY[TwigIndex] - 40, TwigLeftPosX[TwigIndex] + 40, TwigLeftPosY[TwigIndex] + 40, GetColor(255, 0, 0), false);
		}
	}

	for (int TwigIndex = 0; TwigIndex < TWIG_RIGHT_MAX_NUM; TwigIndex++)
	{
		if (isDrawRight[TwigIndex] == true)
		{
			// 枝の画像描画
			DrawRotaGraph(TwigRightPosX[TwigIndex], TwigRightPosY[TwigIndex], 1.0f, 0.0f, TwigImgHandle, true, true);

			// debug
			//DrawBox(TwigRightPosX[TwigIndex] - 40, TwigRightPosY[TwigIndex] - 40, TwigRightPosX[TwigIndex] + 40, TwigRightPosY[TwigIndex] + 40, GetColor(255, 0, 0), false);
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

	// カウント変数2
	CountNum2 = 0;
}

// 枝(左)の移動処理
void Twig::MoveLeftTwig()
{
	for (int TwigIndex = 0; TwigIndex < TWIG_LEFT_MAX_NUM; TwigIndex++)
	{
		if (TwigLeftPosY[TwigIndex] > WINDOW_HEIGHT - 156)
		{
			Random = GetRand(RANDOM_NUM);

			TwigLeftPosY[TwigIndex] = (WINDOW_HEIGHT - 156) - 69 * 19;

			if (Random >= 1)
			{
				isDrawLeft[TwigIndex] = true;
			}
			else
			{
				isDrawLeft[TwigIndex] = false;
			}
		}
	}
}

// 枝(右)の移動処理
void Twig::MoveRightTwig()
{
	// RightTwig1
	for (int TwigIndex = 0; TwigIndex < TWIG_RIGHT_MAX_NUM; TwigIndex++)
	{
		if (TwigRightPosY[TwigIndex] > WINDOW_HEIGHT - 156)
		{
			Random = GetRand(RANDOM_NUM);

			TwigRightPosY[TwigIndex] = (WINDOW_HEIGHT - 156) - 69 * 19;

			if (Random >= 1)
			{
				isDrawRight[TwigIndex] = true;
			}
			else
			{
				isDrawRight[TwigIndex] = false;
			}
		}
	}
}

// 左右画面クリック判定
void Twig::Click()
{
	// 左クリックが押されていれば
	if (IsMouseDown(MOUSE_INPUT_LEFT))
	{
		CountNum++;

		if (CountNum <= 3)
		{
			for (int TwigIndex = 0; TwigIndex < TWIG_LEFT_MAX_NUM; TwigIndex++)
			{
				// 枝の座標
				TwigLeftPosY[TwigIndex] += 23;
			}

			for (int TwigIndex = 0; TwigIndex < TWIG_RIGHT_MAX_NUM; TwigIndex++)
			{
				// 枝の座標
				TwigRightPosY[TwigIndex] += 23;
			}
		}

	}
	else
	{
		if (CountNum == 2)
		{
			for (int TwigIndex = 0; TwigIndex < TWIG_LEFT_MAX_NUM; TwigIndex++)
			{
				// 枝の座標
				TwigLeftPosY[TwigIndex] += 23;
			}

			for (int TwigIndex = 0; TwigIndex < TWIG_RIGHT_MAX_NUM; TwigIndex++)
			{
				// 枝の座標
				TwigRightPosY[TwigIndex] += 23;
			}
		}
		else if (CountNum == 1)
		{
			for (int TwigIndex = 0; TwigIndex < TWIG_LEFT_MAX_NUM; TwigIndex++)
			{
				// 枝の座標
				TwigLeftPosY[TwigIndex] += 46;
			}

			for (int TwigIndex = 0; TwigIndex < TWIG_RIGHT_MAX_NUM; TwigIndex++)
			{
				// 枝の座標
				TwigRightPosY[TwigIndex] += 46;
			}
		}
		CountNum = 0;
	}
}

// プレイヤーと枝の当たり判定
void Twig::Player_TwigCollision(int PlayerPosX, int PlayerPosY)
{
	for (int TwigIndex = 0; TwigIndex < TWIG_LEFT_MAX_NUM; TwigIndex++)
	{
		if (isDrawLeft[TwigIndex] == true)
		{
			if (Collision::Rect_Dot(TwigLeftPosX[TwigIndex] - 40, TwigLeftPosY[TwigIndex] - 40, 80, 80, PlayerPosX, PlayerPosY))
			{
				// ゲームオーバーシーンに移動
				g_CurrentSceneID = SCENE_ID_FIN_PLAY;
			}
		}
	}

	for (int TwigIndex = 0; TwigIndex < TWIG_RIGHT_MAX_NUM; TwigIndex++)
	{
		if (isDrawRight[TwigIndex] == true)
		{
			if (Collision::Rect_Dot(TwigRightPosX[TwigIndex] - 20, TwigRightPosY[TwigIndex] - 10, 40, 20, PlayerPosX, PlayerPosY))
			{
				// ゲームオーバーシーンに移動
				g_CurrentSceneID = SCENE_ID_FIN_PLAY;
			}
		}
	}
}
