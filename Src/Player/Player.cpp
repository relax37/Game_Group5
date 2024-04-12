#include "DxLib.h"
#include "../Scene/Scene.h"
#include "Player.h"
#include "../Collision/Collision.h"

Player::Player()
{
	PlayerStandImgHandle = 0;		// プレイヤー(待機)画像ハンドル
	PlayerCutImgHandle = 0;			// プレイヤー(切る)画像ハンドル

	PlayerPosX = PlayerPosY = 0;	// プレイヤーの座標

	MouseX = MouseY = 0;			// マウスの座標

	isLeftorRight = 0;				// 左右判定	
	isCut = 0;						// 反転判定
}
Player::~Player() { Fin(); }

// プレイシーンの初期化
void Player::Init()
{
	// プレイヤー(待機)画像ハンドル
	PlayerStandImgHandle = LoadGraph(PLAYER_STAND_IMG_PATH);
	// プレイヤー(切る)画像ハンドル
	PlayerCutImgHandle = LoadGraph(PLAYER_CUT_IMG_PATH);

	PlayerPosX = WINDOW_WIDTH / 3 + 50;	// プレイヤーのX座標
	PlayerPosY = WINDOW_HEIGHT - 150;	// プレイヤーのY座標

	MouseX = MouseY = 0;				// マウスの座標

	isLeftorRight = true;				// 左右判定	(初期(true)は左)
	isCut = false;						// 切る判定
}

// プレイシーン通常処理
void Player::Step()
{
	GetMousePoint(&MouseX, &MouseY);	// マウスの座標を取得

	// 左右座標設定
	SetLRMousePos();

	// 左右画面クリック判定
	ClickLR();
}

// プレイシーン描画処理
void Player::Draw()
{
	// 左側判定であれば
	if (isLeftorRight == true)
	{
		// 切る判定が真であれば
		if (isCut == true)
		{
			DrawRotaGraph(PlayerPosX, PlayerPosY, 1.0f, 0.0f, PlayerCutImgHandle, true, false);
		}
		// 切る判定が偽であれば
		if (isCut == false)
		{
			DrawRotaGraph(PlayerPosX, PlayerPosY, 1.0f, 0.0f, PlayerStandImgHandle, true, false);
		}
		
	}
	// 右側判定であれば
	if (isLeftorRight == false)
	{
		// 切る判定が真であれば
		if (isCut == true)
		{
			DrawRotaGraph(PlayerPosX, PlayerPosY, 1.0f, 0.0f, PlayerCutImgHandle, true, true);
		}
		// 切る判定が偽であれば
		if (isCut == false)
		{
			DrawRotaGraph(PlayerPosX, PlayerPosY, 1.0f, 0.0f, PlayerStandImgHandle, true, false);
		}

	}

	// debug
	/*DrawFormatString(0, 0, GetColor(255, 0, 0), "%d, %d", MouseX, MouseY);*/
}

// プレイシーン終了処理
void Player::Fin()
{
	DeleteGraph(PlayerStandImgHandle);		// プレイヤー(待機)画像ハンドル
	DeleteGraph(PlayerCutImgHandle); 		// プレイヤー(切る)画像ハンドル

	PlayerPosX = PlayerPosY = 0;			// プレイヤーの座標

	MouseX = MouseY = 0;					// マウスの座標

	isLeftorRight = 0;						// 左右判定	
	isCut = 0;								// 反転判定
}

// 左右座標設定
void Player::SetLRMousePos()
{
	// 左右判定が左であれば
	if (isLeftorRight == true)
	{
		PlayerPosX = WINDOW_WIDTH / 3 + 50;	// プレイヤーのX座標
		PlayerPosY = WINDOW_HEIGHT - 150;	// プレイヤーのY座標
	}
	// 左右判定が右であれば
	if (isLeftorRight == false)
	{
		PlayerPosX = WINDOW_WIDTH - WINDOW_WIDTH / 3 - 50;	// プレイヤーのX座標
		PlayerPosY = WINDOW_HEIGHT - 150;					// プレイヤーのY座標
	}
}

// 左右画面クリック判定
void Player::ClickLR()
{
	// 左側にマウスカーソルがあるとき
	if (Collision::Rect_Dot(0, 0, WINDOW_WIDTH / 2, WINDOW_HEIGHT, MouseX, MouseY))
	{
		// 左クリックが押されていれば
		if (IsMouseClick(MOUSE_INPUT_LEFT))
		{
			isLeftorRight = true;				// 左右判定を左に
			isCut = true;						// 切る判定をtrueに
		}
		// 左クリックが押されていなければ
		else
		{
			isCut = false;						// 切る判定をfalseに
		}
	}

	// 左側にマウスカーソルがあるとき
	if (Collision::Rect_Dot(WINDOW_WIDTH / 2, 0, WINDOW_WIDTH / 2, WINDOW_HEIGHT, MouseX, MouseY))
	{
		// 左クリックが押されていれば
		if (IsMouseClick(MOUSE_INPUT_LEFT))
		{
			isLeftorRight = false;				// 左右判定を左に
			isCut = true;						// 切る判定をtrueに
		}
		// 左クリックが押されていなければ
		else
		{
			isCut = false;						// 切る判定をfalseに
		}
	}
}