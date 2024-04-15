//高松
#pragma once

// 画像パス
#define TITLE_BG_PATH				"Data/TitleImage/TitleGround.png"	// 背景
#define TITLE_NAME_PATH				"Data/TitleImage/TitleName.png"		//タイトル名
#define TITLE_RULES_PATH			"Data/TitleImage/rules.png"			//ルールボタン
#define TITLE_RULES_PICTURE_PATH	"Data/TitleImage/RulesPicture.png"		//ルール画像
//SE&BGMパス
#define TITLE_BGM_PATH		"Data/SE&BGM/Title/bgm.mp3"	//bgm
//画像サイズ
#define TITLE_RULES_WIDE	(320)		//ルール幅
#define TITLE_RULES_HIGH	(100)		//ルール高さ

class SceneTitle {
private:
	//画像ハンドル
	int title_bg_handle;			// 背景
	int title_name_handle;			//タイトル名
	int title_start_handle;			//スタートボタン
	int title_rules_handle;			//ルールボタン
	int title_rules_picture_handle;	//ルール画像
	//SE&BGMハンドル
	int title_select_button_handle;	//選択
	int title_click_button_handle;	//クリックする
	int title_bgm_handle;			//bgm
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
	//選択遅延
	bool IsSlowSelect;
	//クリック遅延
	int SlowClick;
	//シーン遷移Bool
	bool SceneBool;
	//ルール表示Bool
	bool IsRulesDraw;

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
