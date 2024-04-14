#include "DxLib.h"
#include "Scene.h"
#include "SceneTitle.h"
#include "../Collision/Collision.h"

SceneTitle::SceneTitle() 
{
	// タイトル背景ハンドル
	title_bg_handle = 0;

	//マウスを表示
	mouse_flag = TRUE;

	title_bg_handle = -1;		// 背景
	title_name_handle = -1;		//タイトル名
	title_start_handle = -1;	//スタートボタン
	title_rules_handle = -1;	//ルールボタン

	//マウスの座標
	mouseX = 0;
	mouseY = 0;
	//スタートボタン
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
	title_start_handle = LoadGraph(START_PATH);	//スタートボタン
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

	//マウスとスタートボタンの当たり判定
	if (Collision::Rect(mouseX, mouseY, 0, 0, 
		startPosX_L, startPosY_L, TITLE_START_WIDE, TITLE_START_HIGH))
	{
		if (IsStart == false)
		{
			//スタートBoolをtrueにする
			IsStart = true;
		}
		//左クリックを離す
		if (IsMouseRelease(MOUSE_INPUT_LEFT))
		{
			//タイトルに移行
			g_CurrentSceneID = SCENE_ID_FIN_TITLE;
		}
	}
	else if (IsStart == true)
	{
		if (Collision::Rect(mouseX, mouseY, 0, 0, startPosX_L - TITLE_BUTTON_WIDE, startPosY_L - TITLE_BUTTON_HIGH,
			TITLE_START_WIDE + TITLE_BUTTON_WIDE * 2, TITLE_START_HIGH + TITLE_BUTTON_HIGH * 2))
		{
			//左クリックを離す
			if (IsMouseRelease(MOUSE_INPUT_LEFT))
			{
				//タイトルに移行
				g_CurrentSceneID = SCENE_ID_FIN_TITLE;
			}
		}
		//当たってないとき
		else
		{
			IsStart = false;
		}
	}
	//当たってないとき
	else
	{
		IsStart = false;
	}
	//マウスとルールボタンの当たり判定
	if (Collision::Rect(mouseX, mouseY, 0, 0,
		rulesPosX_L, rulesPosY_L, TITLE_RULES_WIDE, TITLE_RULES_HIGH))
	{
		if (IsRules == false)
		{
			//ルールBoolをtrueにする
			IsRules = true;
		}
		//左クリックを離す
		if (IsMouseRelease(MOUSE_INPUT_LEFT))
		{
			DrawFormatString(30, 30, GetColor(255, 255, 0), "知ってる");
		}
	}
	else if (IsRules == true)
	{
		if (Collision::Rect(mouseX, mouseY, 0, 0, rulesPosX_L - TITLE_BUTTON_WIDE, rulesPosY_L - TITLE_BUTTON_HIGH,
			TITLE_RULES_WIDE + TITLE_BUTTON_WIDE * 2, TITLE_RULES_HIGH + TITLE_BUTTON_HIGH))
		{
			//左クリックを離す
			if (IsMouseRelease(MOUSE_INPUT_LEFT))
			{
				DrawFormatString(30, 30, GetColor(255, 255, 0), "知ってる");
			}
		}
		//当たってないとき
		else
		{
			IsRules = false;
		}
	}
	//当たってないとき
	else
	{
		IsRules = false;
	}

}

// タイトル描画処理
void SceneTitle::DrawTitle()
{
	DrawGraph(0, 0, title_bg_handle, true);			//背景
	DrawGraph(340, 45, title_name_handle, true);	//タイトル名
	if (IsStart == true)
	{
		DrawExtendGraph(startPosX_L - TITLE_BUTTON_WIDE, startPosY_L - TITLE_BUTTON_HIGH,
			startPosX_R + TITLE_BUTTON_WIDE, startPosY_R + TITLE_BUTTON_HIGH, title_start_handle, true);	//スタートボタン
	}
	else
	{
		DrawExtendGraph(startPosX_L, startPosY_L, startPosX_R, startPosY_R, title_start_handle, true);		//スタートボタン
	}
	if (IsRules == true)
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

