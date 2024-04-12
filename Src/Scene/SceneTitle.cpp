#include "DxLib.h"
#include "Scene.h"
#include "SceneTitle.h"
#include "../Collision/Collision.h"

SceneTitle::SceneTitle() 
{
	// タイトル背景ハンドル
	title_bg_handle = 0;

	//何のボタンも拡大しない
	title_select = -1;

	//マウスを表示
	mouse_flag = TRUE;

	title_bg_handle = -1;		// 背景
	title_name_handle = -1;		//タイトル名
	title_start_handle = -1;	//スタートボタン
	title_rules_handle = -1;	//ルールボタン

	//マウスの座標
	mouseX = 0;
	mouseY = 0;
	//スタート
	startPosX_L = 470;
	startPosY_L = 310;
	startPosX_R = startPosX_L + TITLE_START_WIDE;
	startPosY_R = startPosY_L + TITLE_START_HIGH;
	//ルールボタン
	rulesPosX_L = 480;
	rulesPosY_L = 480;
	rulesPosX_R = rulesPosX_L + TITLE_RULES_WIDE;
	rulesPosY_R = rulesPosY_L + TITLE_RULES_HIGH;
	//ボタンBool
	IsStart = false;	//スタートボタン
	IsRules = false;	//ルールボタン
}
SceneTitle::~SceneTitle() { FinTitle(); }

// タイトルの初期化
void SceneTitle::InitTitle()
{
	//画像ハンドル
	title_bg_handle = LoadGraph(TITLE_BG_PATH);			//背景
	title_name_handle = LoadGraph(TITLE_NAME_PATH);		//タイトル名
	title_start_handle = LoadGraph(TITLE_START_PATH);	//スタートボタン
	title_rules_handle = LoadGraph(TITLE_RULES_PATH);	//ルールボタン

	//マウスを表示
	SetMouseDispFlag(mouse_flag);

	// タイトルループへ
	g_CurrentSceneID = SCENE_ID_LOOP_TITLE;
}

// タイトル通常処理
void SceneTitle::StepTitle()
{
	//マウスの座標を取得
	GetMousePoint(&mouseX, &mouseY);

	//タイトルセレクト
	TitleSelect();

	//マウスとスタートボタンの当たり判定
	if (Collision::Rect(mouseX, mouseY, 0, 0, 
		startPosX_L, startPosY_L, TITLE_START_WIDE, TITLE_START_HIGH))
	{
		if (IsStart == false)
		{
			//スタートBoolをtrueにする
			IsStart = true;
			//タイトルボタンを拡大
			title_select = START_BOTTUN;
		}
	}
	//マウスとルールボタンの当たり判定
	else if (Collision::Rect(mouseX, mouseY, 0, 0,
		rulesPosX_L, rulesPosY_L, TITLE_RULES_WIDE, TITLE_RULES_HIGH))
	{
		if (IsRules == false)
		{
			//ルールBoolをtrueにする
			IsRules = true;
			//ルールボタンを拡大
			title_select = RULES_BOTTUN;
		}
	}
	//どちらにも当たってない
	else
	{
		//スタートとルールのBoolをfalseにする
		IsStart = false;
		IsRules = false;
	}

	//
	if (IsStart == true)
	{

	}

	switch (title_select)
	{
		//スタートボタンを拡大
	case TitleSelect::START_BOTTUN:
		DrawFormatString(30, 30, GetColor(255, 255, 0), "見えてる");
		break;
		//ルールボタンを拡大
	case TitleSelect::RULES_BOTTUN:
		DrawFormatString(30, 30, GetColor(255, 255, 0), "知ってる");
		break;
	}

	//マウスとボタンの当たり判定
	
	//左クリックを離す
	if (IsMouseRelease(MOUSE_INPUT_LEFT))
	{
		//テスト
	}

	// Enterを離す
	if (InputKey::Release(KEY_INPUT_RETURN))
	{
		//スタートボタンの時
		if (title_select == TitleSelect::START_BOTTUN)
		{
			DrawFormatString(30, 30, GetColor(255, 255, 0), "見えてる");
		}
		//ルールボタンの時
		else if (title_select == TitleSelect::RULES_BOTTUN)
		{
			DrawFormatString(30, 30, GetColor(255, 255, 0), "知ってる");
		}
		// タイトルシーンを終了(デバッグ)
		FinTitle();
	}
}

// タイトル描画処理
void SceneTitle::DrawTitle()
{
	DrawGraph(0, 0, title_bg_handle, true);			//背景
	DrawGraph(340, 60, title_name_handle, true);	//タイトル名
	if (title_select == START_BOTTUN)
	{
		DrawExtendGraph(startPosX_L - TITLE_BUTTON_WIDE, startPosY_L - TITLE_BUTTON_HIGH,
			startPosX_R + TITLE_BUTTON_WIDE, startPosY_R + TITLE_BUTTON_HIGH, title_start_handle, true);	//スタートボタン
	}
	else
	{
		DrawExtendGraph(startPosX_L, startPosY_L, startPosX_R, startPosY_R, title_start_handle, true);		//スタートボタン
	}
	if (title_select == RULES_BOTTUN)
	{
		TITLE_BUTTON_WIDE;
		DrawExtendGraph(rulesPosX_L - TITLE_BUTTON_WIDE, rulesPosY_L - TITLE_BUTTON_HIGH,
			rulesPosX_R + TITLE_BUTTON_WIDE, rulesPosY_R + TITLE_BUTTON_HIGH, title_rules_handle, true);	//ルールボタン
	}
	else
	{
		DrawExtendGraph(rulesPosX_L, rulesPosY_L, rulesPosX_R, rulesPosY_R, title_rules_handle, true);		//ルールボタン
	}
}

// タイトル終了処理
void SceneTitle::FinTitle()
{
	//画像破棄
	DeleteGraph(title_bg_handle);		//背景
	DeleteGraph(title_name_handle);		//タイトル名
	DeleteGraph(title_start_handle);	//スタートボタン
	DeleteGraph(title_rules_handle);	//ルールボタン

	// プレイシーンに移動
	g_CurrentSceneID = SCENE_ID_INIT_PLAY;
}

//タイトルセレクト
void SceneTitle::TitleSelect()
{
	if (inputKey.Release(KEY_INPUT_UP))
	{
		//タイトルセレクトボタン
		TitleSelectButton();
	}
	else if (inputKey.Release(KEY_INPUT_DOWN))
	{
		//タイトルセレクトボタン
		TitleSelectButton();
	}
}

//タイトルセレクトボタン
void SceneTitle::TitleSelectButton()
{
	//スタートボタンの時
	if (title_select == TitleSelect::START_BOTTUN)
	{
		//ルールボタンにする
		title_select = TitleSelect::RULES_BOTTUN;
	}
	//初期とルールボタンの時
	else if (title_select == -1 || title_select == TitleSelect::RULES_BOTTUN)
	{
		//スタートボタンにする
		title_select = TitleSelect::START_BOTTUN;
	}
}