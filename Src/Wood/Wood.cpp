#include "DxLib.h"
#include "../Scene/Scene.h"
#include "Wood.h"
#include "../Collision/Collision.h"

Wood::Wood()
{
	for (int WoodIndex = 0; WoodIndex < WOOD_MAX_NUM; WoodIndex++)
	{
		// 木の画像ハンドル
		WoodImgHandle[WoodIndex] = 0;

		// 木の座標
		WoodPosX[WoodIndex] = WoodPosY[WoodIndex] = 0;
	}
	// 木の根の画像ハンドル
	WoodStandImgHandle = 0;

	// 木の根の座標
	WoodStandPosX = WoodStandPosY = 0;

	//for (int TwigIndex = 0; TwigIndex < TWIG_MAX_NUM; TwigIndex++)
	//{
	//	// 枝の画像ハンドル
	//	TwigImgHandle[TwigIndex] = 0;

	//	// 枝の座標
	//	TwigPosX[TwigIndex] = TwigPosY[TwigIndex] = 0;
	//}

	// マウスの座標
	MouseX = MouseY = 0;

	// カウント変数
	CountNum = 0;
}
Wood::~Wood() { Fin(); }

//プレイシーンの初期化
void Wood::Init()
{
	for (int WoodIndex = 0; WoodIndex < WOOD_MAX_NUM; WoodIndex++)
	{
		// 木の画像ハンドル
		WoodImgHandle[WoodIndex] = LoadGraph(WOOD_IMG_PATH);

		// 木の座標
		WoodPosX[WoodIndex] = WINDOW_WIDTH / 2;
		WoodPosY[WoodIndex] = WINDOW_HEIGHT - 166 - 138 * WoodIndex;
	}
	// 木の根の画像ハンドル
	WoodStandImgHandle = LoadGraph(WOODSTAND_IMG_PATH);

	// 木の根の座標
	WoodStandPosX = WINDOW_WIDTH / 2;
	WoodStandPosY = WINDOW_HEIGHT - 50;

	//for (int TwigIndex = 0; TwigIndex < TWIG_MAX_NUM; TwigIndex++)
	//{
	//	// 枝の画像ハンドル
	//	TwigImgHandle[TwigIndex] = LoadGraph(TWIG_IMG_PATH);

	//	// 枝の座標
	//	TwigPosX[TwigIndex] = TwigPosY[TwigIndex] = 0;
	//}

	// マウスの座標
	MouseX = MouseY = 0;

	// カウント変数
	CountNum = 0;
}

//プレイシーン通常処理
void Wood::Step()
{
	// マウスの座標を取得
	GetMousePoint(&MouseX, &MouseY);

	// 左右画面クリック判定
	ClickLR();
}

//プレイシーン描画処理
void Wood::Draw()
{
	for (int WoodIndex = 0; WoodIndex < WOOD_MAX_NUM; WoodIndex++)
	{
		// 木の画像描画
		DrawRotaGraph(WoodPosX[WoodIndex], WoodPosY[WoodIndex], 2.0f, 0.0f, WoodImgHandle[WoodIndex], true, false);
	}
	// 木の根の画像描画
	DrawRotaGraph(WoodStandPosX, WoodStandPosY, 2.0f, 0.0f, WoodStandImgHandle, true, false);

	//for (int TwigIndex = 0; TwigIndex < TWIG_MAX_NUM; TwigIndex++)
	//{
	//	// 枝の画像ハンドル
	//	TwigImgHandle[TwigIndex] = LoadGraph(TWIG_IMG_PATH);

	//	// 枝の座標
	//	TwigPosX[TwigIndex] = TwigPosY[TwigIndex] = 0;
	//}
}

//プレイシーン終了処理
void Wood::Fin()
{
	for (int WoodIndex = 0; WoodIndex < WOOD_MAX_NUM; WoodIndex++)
	{
		// 木の画像ハンドル
		DeleteGraph(WoodImgHandle[WoodIndex]);

		// 木の座標
		WoodPosX[WoodIndex] = WoodPosY[WoodIndex] = 0;
	}
	// 木の根の画像ハンドル
	DeleteGraph(WoodStandImgHandle);

	// 木の根の座標
	WoodStandPosX = WoodStandPosY = 0;

	// マウスの座標
	MouseX = MouseY = 0;

	// カウント変数
	CountNum = 0;
}

// 右方向に木が飛ぶ
void Wood::WoodMoveRight()
{
	// WoodPosX[0]を右に移動させる
	if (WoodPosX[0] <= WINDOW_WIDTH + WOOD_SIZE_W)
	{
		// WoodPosX[0]を右に移動させる
		WoodPosX[0] += 200;
	}

	if (WoodPosY[1] < WINDOW_HEIGHT - 166)
	{
		// その他の木を下にずらす
		WoodPosY[1] += 40;
		WoodPosY[2] += 40;
		WoodPosY[3] += 40;
		WoodPosY[4] += 40;
		WoodPosY[5] += 40;
	}

	if (WoodPosX[0] >= WINDOW_WIDTH + WOOD_SIZE_W && WoodPosY[1] >= WINDOW_HEIGHT - 166)
	{
		for (int WoodIndex = 0; WoodIndex < WOOD_MAX_NUM; WoodIndex++)
		{
			// 木の座標再設定
			WoodPosX[WoodIndex] = WINDOW_WIDTH / 2;
			WoodPosY[WoodIndex] = WINDOW_HEIGHT - 166 - 138 * WoodIndex;
		}
	}
}

// 左方向に木が飛ぶ
void Wood::WoodMoveLeft()
{
	// WoodPosX[0]を右に移動させる
	if (WoodPosX[0] >= 0)
	{
		// WoodPosX[0]を右に移動させる
		WoodPosX[0] -= 200;
	}

	if (WoodPosY[1] < WINDOW_HEIGHT - 166)
	{
		// その他の木を下にずらす
		WoodPosY[1] += 40;
		WoodPosY[2] += 40;
		WoodPosY[3] += 40;
		WoodPosY[4] += 40;
		WoodPosY[5] += 40;
	}

	if (WoodPosX[0] <= 0 && WoodPosY[1] >= WINDOW_HEIGHT - 166)
	{
		// 木の座標の再設定
		ResetWoodPos();
	}
}

// 木の座標の再設定
void Wood::ResetWoodPos()
{
	for (int WoodIndex = 0; WoodIndex < WOOD_MAX_NUM; WoodIndex++)
	{
		// 木の座標再設定
		WoodPosX[WoodIndex] = WINDOW_WIDTH / 2;
		WoodPosY[WoodIndex] = WINDOW_HEIGHT - 166 - 138 * WoodIndex;
	}
}

// 左右画面クリック判定
void Wood::ClickLR()
{
	// 左側にマウスカーソルがあるとき
	if (Collision::Rect_Dot(0, 0, WINDOW_WIDTH / 2, WINDOW_HEIGHT, MouseX, MouseY))
	{
		// 左クリックが押されていれば
		if (IsMouseDown(MOUSE_INPUT_LEFT))
		{
			CountNum++;
			if (CountNum < 5)
			{
				// 右に木が移動
				WoodMoveRight();
			}
		}
		else
		{
			CountNum = 0;
			// 木の座標の再設定
			ResetWoodPos();
		}
	}

	// 左側にマウスカーソルがあるとき
	if (Collision::Rect_Dot(WINDOW_WIDTH / 2, 0, WINDOW_WIDTH / 2, WINDOW_HEIGHT, MouseX, MouseY))
	{
		// 左クリックが押されていれば
		if (IsMouseDown(MOUSE_INPUT_LEFT))
		{
			CountNum++;
			if (CountNum < 5)
			{
				// 左に木が移動
				WoodMoveLeft();
			}
		}
		else
		{
			CountNum = 0;
			// 木の座標の再設定
			ResetWoodPos();
		}
	}
	
}
