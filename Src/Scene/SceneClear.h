#pragma once

// 画像パス
// クリア背景
#define CLEAR_BG_PATH "Data/ClearImage/ClearBuckGround.png"

enum CLEAR_FROM_SCENE
{
	CLEAR_FROM_TITLE,	//タイトルへ
	CLEAR_FROM_PLAY,	//プレイへ
};

class SceneClear {
private:
	//画像ハンドル
	int clear_bg_handle;			//背景
	int clear_start_handle;			//スタートボタン
	int clear_title_handle;			//タイトルボタン
	int clear_score_handle;			//スコアボード
	int clear_font_handle;			//フォント
	//マウスの表示設定
	int mouse_flag;
	//座標
	//マウスの座標
	int mouseX;
	int mouseY;
	//スタートボタン
	int startPosX_L;
	int startPosY_L;
	int startPosX_R;
	int startPosY_R;
	//タイトルボタン
	int titlePosX_L;
	int titlePosY_L;
	int titlePosX_R;
	int titlePosY_R;
	//ボタンBool
	bool IsStart;	//スタートボタン
	bool IsTitle;	//タイトルボタン
	//タイトルかプレイか
	int IsFromScene;

public:
	SceneClear();
	~SceneClear();

	//クリアシーン初期化
	void InitClear();

	//クリアシーン通常処理
	void StepClear();

	//クリアシーン描画処理
	void DrawClear();

	//クリアシーン終了処理
	void FinClear();
};
