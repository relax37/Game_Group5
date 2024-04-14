// 小田
#pragma once

#define PLAYER_STAND_IMG_PATH "Data/Image/Play/stand.png"
#define PLAYER_CUT_IMG_PATH "Data/Image/Play/cut.png"

class Player {
private:
	int PlayerStandImgHandle;		// プレイヤー(待機)画像ハンドル
	int PlayerCutImgHandle;			// プレイヤー(切る)画像ハンドル

	int PlayerPosX, PlayerPosY;		// プレイヤーの座標

	int MouseX, MouseY;				// マウスの座標

	bool isLeftorRight;				// 左右判定
	bool isCut;						// 切る判定

public:
	Player();
	~Player();

	// プレイヤーの初期化
	void Init();

	// プレイヤー通常処理
	void Step();

	// プレイヤー描画処理
	void Draw();

	// プレイヤー終了処理
	void Fin();

	// 左右座標設定
	void SetLRMousePos();

	// 左右画面クリック判定
	void ClickLR();
};
