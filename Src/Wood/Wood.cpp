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

	MouseX = MouseY = 0;						// マウスの座標

	isRightMove = 0;							// 右に動く判定
	isLeftMove = 0;								// 左に動く判定
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

	MouseX = MouseY = 0;				// マウスの座標

	isRightMove = false;							// 右に動く判定
	isLeftMove = false;								// 左に動く判定
}

//プレイシーン通常処理
void Wood::Step()
{
	GetMousePoint(&MouseX, &MouseY);	// マウスの座標を取得

	// 左右画面クリック判定
	ClickLR();

	WoodMoveRight();

	WoodMoveLeft();
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

	MouseX = MouseY = 0;					// マウスの座標

	isRightMove = 0;							// 右に動く判定
	isLeftMove = 0;								// 左に動く判定
}

// 右方向に木が飛ぶ
void Wood::WoodMoveRight()
{
	if (isRightMove)
	{
		// Wood[0]
		if (Collision::Rect(WoodPosX[0] - WOOD_SIZE_W / 2, WoodPosY[0] - WOOD_SIZE_H / 2, WOOD_SIZE_W, WOOD_SIZE_H,
								0, WINDOW_HEIGHT - 166, WINDOW_WIDTH, WINDOW_HEIGHT))
		{
			// WoodPosX[0]を右に移動させる
			if (WoodPosX[0] < WINDOW_WIDTH + WOOD_SIZE_W)
			{
				WoodPosX[0] += 150;
			}
			// 画面外に出たら
			else
			{
				// WoodPos[0]を一番上に移動
				WoodPosX[0] = WINDOW_WIDTH / 2;
				WoodPosY[0] = WINDOW_HEIGHT - 166 - 138 * 5;
			}

			// その他の木を下にずらす
			if (WoodPosY[1] <= WINDOW_HEIGHT - 166)
			{
				WoodPosY[1] += 30;
				WoodPosY[2] += 30;
				WoodPosY[3] += 30;
				WoodPosY[4] += 30;
				WoodPosY[5] += 30;
			}
			// 移動が終わったらisRightMoveをfalseにする
			else
			{
				isRightMove = false;
			}
		}

		//// Wood[1]
		//if (Collision::Rect(WoodPosX[1] - WOOD_SIZE_W / 2, WoodPosY[1] - WOOD_SIZE_H / 2, WOOD_SIZE_W, WOOD_SIZE_H,
		//					0, 524, WINDOW_WIDTH, WINDOW_HEIGHT))
		//{
		//	// WoodPosX[1]を右に移動させる
		//	if (WoodPosX[1] < WINDOW_WIDTH + WOOD_SIZE_W)
		//	{
		//		WoodPosX[1] += 150;
		//	}
		//	// 画面外に出たら
		//	else
		//	{
		//		// WoodPos[1]を一番上に移動
		//		WoodPosX[1] = WINDOW_WIDTH / 2;
		//		WoodPosY[1] = WINDOW_HEIGHT - 166 - 138 * 5;
		//	}

		//	// その他の木を下にずらす
		//	if (WoodPosY[2] <= WINDOW_HEIGHT - 166)
		//	{
		//		WoodPosY[2] += 20;
		//		WoodPosY[3] += 20;
		//		WoodPosY[4] += 20;
		//		WoodPosY[5] += 20;
		//		WoodPosY[0] += 20;
		//	}

		//	// 移動が終わったらisRightMoveをfalseにする
		//	if (WoodPosY[1] == WINDOW_HEIGHT - 166 - 138 * 5 && WoodPosY[2] == WINDOW_HEIGHT - 166)
		//	{
		//		isRightMove = false;
		//	}
		//}
	}
}

// 左方向に木が飛ぶ
void Wood::WoodMoveLeft()
{

}

// 左右画面クリック判定
void Wood::ClickLR()
{
	if (isRightMove == false)
	{
		// 左側にマウスカーソルがあるとき
		if (Collision::Rect_Dot(0, 0, WINDOW_WIDTH / 2, WINDOW_HEIGHT, MouseX, MouseY))
		{
			// 左クリックが押されていれば
			if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
			{
				isRightMove = true;
			}
			// 左クリックが押されていなければ
			else
			{
				
			}
		}
	}
	

	// 左側にマウスカーソルがあるとき
	if (Collision::Rect_Dot(WINDOW_WIDTH / 2, 0, WINDOW_WIDTH / 2, WINDOW_HEIGHT, MouseX, MouseY))
	{
		// 左クリックが押されていれば
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
		{
			WoodMoveLeft();
		}
		// 左クリックが押されていなければ
		else
		{
			
		}
	}
}
