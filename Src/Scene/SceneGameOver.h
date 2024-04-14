#pragma once

// 画像パス
#define GAMEOVER_BG_PATH "Data/GameOverImage/GameOverBuckGround.png"	//背景

enum GAMEOVER_FROM_SCENE
{
	GAMEOVER_FROM_TITLE,	//タイトルへ
	GAMEOVER_FROM_PLAY,		//プレイへ
};

class SceneGameOver {
private:
	//画像ハンドル
	int gameover_bg_handle;				//背景
	int gameover_start_handle;			//スタートボタン
	int gameover_title_handle;			//タイトルボタン
	int gameover_score_handle;			//スコアボード
	int gameover_font_handle;			//フォント
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
	SceneGameOver();
	~SceneGameOver();

	//ゲームオーバーシーン初期化
	void InitGameOver();

	//ゲームオーバーシーン通常処理
	void StepGameOver();

	//ゲームオーバーシーン描画処理
	void DrawGameOver();

	//ゲームオーバーシーン終了処理
	void FinGameOver();
};
