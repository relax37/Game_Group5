#pragma once

#define PLAYER_STAND_IMG_PATH "Data/Play/stand.png"
#define PLAYER_CUT_IMG_PATH "Data/Play/cut.png"

class Player {
private:
	int PlayerStandImgHandle;		// プレイヤー(待機)画像ハンドル
	int PlayerCutImgHandle;			// プレイヤー(切る)画像ハンドル

	int PlayerPosX, PlayerPosY;		// プレイヤーの座標

	bool isLeftorRight;				// 左右判定
	bool isCut;						// 切る判定

public:
	Player();
	~Player();

	// プレイシーンの初期化
	void Init();

	// プレイシーン通常処理
	void Step();

	// プレイシーン描画処理
	void Draw();

	// プレイシーン終了処理
	void Fin();

	// 左右画面クリック判定
	void ClickLR();
};
