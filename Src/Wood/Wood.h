// 小田
#pragma once

// 木
#define WOOD_IMG_PATH "Data/Image/Play/wood.png"
#define WOODSTAND_IMG_PATH "Data/Image/Play/woodstand.png"
#define WOOD_MAX_NUM (6)
#define WOOD_SIZE_W (83)
#define WOOD_SIZE_H (69)

class Wood {
private:
	int WoodImgHandle;										// 木の画像ハンドル
	int WoodStandImgHandle;									// 木の根の画像ハンドル
		
	int WoodPosX[WOOD_MAX_NUM], WoodPosY[WOOD_MAX_NUM];		// 木の座標
	int WoodStandPosX, WoodStandPosY;						// 木の根の座標

	int MouseX, MouseY;										// マウスの座標

	int CountNum;											// カウント変数

public:
	Wood();
	~Wood();

	// Woodの初期化
	void Init();

	// Wood通常処理
	void Step();

	// Wood描画処理
	void Draw();

	// Wood終了処理
	void Fin();

	// 右方向に木が飛ぶ
	void WoodMoveRight();

	// 左方向に木が飛ぶ
	void WoodMoveLeft();

	// 木の座標の再設定
	void ResetWoodPos();

	// 左右画面クリック判定
	void ClickLR();
};
