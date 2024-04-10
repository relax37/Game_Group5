#include "DxLib.h"
#include "Scene.h"
#include "ScenePlay.h"

ScenePlay::ScenePlay()
{
	// プレイ背景ハンドル
	PlayBGHandle = 0;

	for (int WoodIndex = 0; WoodIndex < WOOD_MAX_NUM; WoodIndex++)
	{
		// 木の画像ハンドル
		WoodImgHandle[WoodIndex] = 0;

		// 木の座標
		WoodPosX[WoodIndex] = WoodPosY[WoodIndex] = 0;
	}

	for (int TwigIndex = 0; TwigIndex < TWIG_MAX_NUM; TwigIndex++)
	{
		// 枝の画像ハンドル
		TwigImgHandle[TwigIndex] = 0;

		// 枝の座標
		TwigPosX[TwigIndex] = TwigPosY[TwigIndex] = 0;
	}
}
ScenePlay::~ScenePlay() { FinPlay(); }

//プレイシーンの初期化
void ScenePlay::InitPlay()
{
	// プレイ背景ハンドル
	PlayBGHandle = LoadGraph(PLAY_BG_PATH);

	for (int WoodIndex = 0; WoodIndex < WOOD_MAX_NUM; WoodIndex++)
	{
		// 木の画像ハンドル
		WoodImgHandle[WoodIndex] = LoadGraph(WOOD_IMG_PATH);

		// 木の座標
		WoodPosX[WoodIndex] = WoodPosY[WoodIndex] = 0;
	}

	for (int TwigIndex = 0; TwigIndex < TWIG_MAX_NUM; TwigIndex++)
	{
		// 枝の画像ハンドル
		TwigImgHandle[TwigIndex] = LoadGraph(TWIG_IMG_PATH);

		// 枝の座標
		TwigPosX[TwigIndex] = TwigPosY[TwigIndex] = 0;
	}

	g_CurrentSceneID = SCENE_ID_LOOP_PLAY;
}

//プレイシーン通常処理
void ScenePlay::StepPlay()
{

	// Enterを押したら
	if (InputKey::Push(KEY_INPUT_RETURN))
	{
		// プレイシーンを終了する
		FinPlay();
	}
}

//プレイシーン描画処理
void ScenePlay::DrawPlay()
{
	// タイトル背景描画
	DrawGraph(0, 0, PlayBGHandle, true);

	for (int WoodIndex = 0; WoodIndex < WOOD_MAX_NUM; WoodIndex++)
	{
		// 木の画像ハンドル
		DrawRotaGraph(WoodPosX[WoodIndex], WoodPosY[WoodIndex] * WoodIndex + WOOD_SIZE / 2, 1.0f, 0.0f, false, false);
	}

	for (int TwigIndex = 0; TwigIndex < TWIG_MAX_NUM; TwigIndex++)
	{
		// 枝の画像ハンドル
		TwigImgHandle[TwigIndex] = LoadGraph(TWIG_IMG_PATH);

		// 枝の座標
		TwigPosX[TwigIndex] = TwigPosY[TwigIndex] = 0;
	}
}

//プレイシーン終了処理
void ScenePlay::FinPlay()
{
	// タイトル背景ハンドル
	DeleteGraph(PlayBGHandle);

	// クリアシーンに移動
	g_CurrentSceneID = SCENE_ID_INIT_CLEAR;
}
