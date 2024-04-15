// 小田
#pragma once

// 枝
#define TWIG_IMG_PATH "Data/Image/Play/twig.png"
#define TWIG_LEFT_MAX_NUM (8)
#define TWIG_RIGHT_MAX_NUM (6)

#define RANDOM_NUM (5)

class Twig {
private:
	int TwigImgHandle;														// 枝の画像ハンドル

	int TwigLeftPosX[TWIG_LEFT_MAX_NUM], TwigLeftPosY[TWIG_LEFT_MAX_NUM];	// 枝の座標
	int TwigRightPosX[TWIG_RIGHT_MAX_NUM], TwigRightPosY[TWIG_RIGHT_MAX_NUM];// 枝の座標

	bool isDrawLeft[TWIG_LEFT_MAX_NUM];										// 描画判定
	bool isDrawRight[TWIG_RIGHT_MAX_NUM];									// 描画判定

	int Random;																// ランダム変数

	int CountNum;															// カウント変数

	int CountNum2;															// カウント変数2
		
public:
	Twig();
	~Twig();

	// Twigの初期化
	void Init();

	// Twig通常処理
	void Step();

	// Twig描画処理
	void Draw();

	// Twig終了処理
	void Fin();

	// 枝(左)の移動処理
	void MoveLeftTwig();

	// 枝(右)の移動処理
	void MoveRightTwig();

	// クリック判定
	void Click();

	// プレイヤーと枝の当たり判定
	void Player_TwigCollision(int PlayerPosX, int PlayerPosY);
};

