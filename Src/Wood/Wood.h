#pragma once

// 木
#define WOOD_IMG_PATH "Data/Image/Play/wood.png"
#define WOODSTAND_IMG_PATH "Data/Image/Play/woodstand.png"
#define WOOD_MAX_NUM (20)
#define WOOD_SIZE (200)

// 枝
//#define TWIG_IMG_PATH "Data/Imaga/Play/karinoeda.png"
//#define TWIG_MAX_NUM (50)
//#define TWIG_SIZE (128)

class Wood {
private:
	int WoodImgHandle[WOOD_MAX_NUM];					// 木の画像ハンドル
	int WoodStandImgHandle;								// 木の根の画像ハンドル
	//int TwigImgHandle[TWIG_MAX_NUM];					// 枝の画像ハンドル

	int WoodPosX[WOOD_MAX_NUM], WoodPosY[WOOD_MAX_NUM];	// 木の座標
	int WoodStandPosX, WoodStandPosY;					// 木の根の座標
	//int TwigPosX[TWIG_MAX_NUM], TwigPosY[TWIG_MAX_NUM];	// 枝の座標

public:
	Wood();
	~Wood();

	// プレイシーンの初期化
	void Init();

	// プレイシーン通常処理
	void Step();

	// プレイシーン描画処理
	void Draw();

	// プレイシーン終了処理
	void Fin();
};
