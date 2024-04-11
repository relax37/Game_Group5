#pragma once

// 画像パス
// プレイ背景
#define PLAY_BG_PATH "Data/Image/BackGround/TentativePlayBG.png"

// 木
#define WOOD_IMG_PATH "Data/Play/wood.png"
#define WOOD_MAX_NUM (100)
#define WOOD_SIZE (128)

// 枝
#define TWIG_IMG_PATH "Data/Play/twig.png"
#define TWIG_MAX_NUM (50)
#define TWIG_SIZE (128)

class ScenePlay {
private:
	int PlayBGHandle;									// プレイ背景ハンドル
	int WoodImgHandle[WOOD_MAX_NUM];					// 木の画像ハンドル
	int TwigImgHandle[TWIG_MAX_NUM];					// 枝の画像ハンドル

	int WoodPosX[WOOD_MAX_NUM], WoodPosY[WOOD_MAX_NUM];	// 木の座標
	int TwigPosX[TWIG_MAX_NUM], TwigPosY[TWIG_MAX_NUM];	// 枝の座標

public:
	ScenePlay();
	~ScenePlay();

	// プレイシーンの初期化
	void InitPlay();

	// プレイシーン通常処理
	void StepPlay();

	// プレイシーン描画処理
	void DrawPlay();

	// プレイシーン終了処理
	void FinPlay();
};
