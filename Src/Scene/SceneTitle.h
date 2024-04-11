#pragma once

// 画像パス
#define TITLE_BG_PATH		"Data/TitleImage/TitleGround.png"	// 背景
#define TITLE_NAME_PATH		"Data/TitleImage/TitleName.png"		//タイトル名
#define TITLE_START_PATH	"Data/TitleImage/start.png"			//スタートボタン
#define TITLE_RULES_PATH	"Data/TitleImage/rules.png"			//ルールボタン

class SceneTitle {
private:
	//画像ハンドル
	int title_bg_handle;	// 背景
	int title_name_handle;	//タイトル名
	int title_start_handle;	//スタートボタン
	int title_rules_handle;	//ルールボタン

public:
	SceneTitle();
	~SceneTitle();

	// タイトルの初期化
	void InitTitle();

	// タイトル通常処理
	void StepTitle();

	// タイトル描画処理
	void DrawTitle();

	// タイトル終了処理
	void FinTitle();
};
