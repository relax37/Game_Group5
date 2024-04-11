#include "DxLib.h"
#include "../Scene/Scene.h"
#include "Wood.h"

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
		WoodPosY[WoodIndex] = WINDOW_HEIGHT - 166- 138 * WoodIndex;
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

	g_CurrentSceneID = SCENE_ID_LOOP_PLAY;
}

//プレイシーン通常処理
void Wood::Step()
{

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
}
