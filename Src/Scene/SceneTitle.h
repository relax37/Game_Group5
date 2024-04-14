#pragma once

// 画像パス
#define TITLE_BG_PATH				"Data/TitleImage/TitleGround.png"	// 背景
#define TITLE_NAME_PATH				"Data/TitleImage/TitleName.png"		//タイトル名
#define TITLE_RULES_PATH			"Data/TitleImage/rules.png"			//ルールボタン
#define TITLE_RULES_PICTURE_PATH	"Data/TitleImage/RulesPicture"		//ルール説明画像
//画像サイズ
#define TITLE_START_WIDE	(340)		//スタート幅
#define TITLE_START_HIGH	(100)		//スタート高さ
#define TITLE_RULES_WIDE	(320)		//ルール幅
#define TITLE_RULES_HIGH	(100)		//ルール高さ
//ボタンの拡大量
#define TITLE_BUTTON_WIDE	(50)		//幅
#define TITLE_BUTTON_HIGH	(20)		//高さ

class SceneTitle {
private:
	//画像ハンドル
	int title_bg_handle;	// 背景
	int title_name_handle;	//タイトル名
	int title_start_handle;	//スタートボタン
	int title_rules_handle;	//ルールボタン
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
	//ルールボタン
	int rulesPosX_L;
	int rulesPosY_L;
	int rulesPosX_R;
	int rulesPosY_R;
	//ボタンBool
	bool IsStart;	//スタートボタン
	bool IsRules;	//ルールボタン

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
