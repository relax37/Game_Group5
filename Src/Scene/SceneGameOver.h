//高松
#pragma once

// 画像パス
#define GAMEOVER_BG_PATH		"Data/GameOverImage/GameOverBuckGround.png"	//背景
#define GAMEOVER_DEFEAT_PATH	"Data/GameOverImage/lose.png"				//負け
//SE&BGMパス
#define GAMEOVER_DEFEAT_SE_PATH	"Data/SE&BGM/Gameover/defeat.mp3"		//負け

enum GAMEOVER_FROM_SCENE
{
	GAMEOVER_FROM_TITLE,	//タイトルへ
	GAMEOVER_FROM_PLAY,		//プレイへ
};

class SceneGameOver {
private:
	//画像ハンドル
	int gameover_bg_handle;				//背景
	int gameover_defeat_handle;			//負け
	int gameover_start_handle;			//スタートボタン
	int gameover_title_handle;			//タイトルボタン
	int gameover_score_handle;			//スコアボード
	int gameover_font_handle;			//フォント
	//SE&BGMハンドル
	int gameover_select_button_handle;	//選択
	int gameover_click_button_handle;	//クリックする
	int gameover_gameover_handle;		//ゲームオーバー
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
	//選択遅延
	bool IsSlowSelect;
	//クリック遅延
	int SlowClick;
	//シーン遷移Bool
	bool SceneBool;
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
