//高松
#include "DxLib.h"
#include "Scene.h"
#include "SceneTitle.h"
#include "../Collision/Collision.h"

SceneTitle::SceneTitle() 
{
	//画像ハンドル
	title_bg_handle = -1;				// 背景
	title_name_handle = -1;				//タイトル名
	title_start_handle = -1;			//スタートボタン
	title_rules_handle = -1;			//ルールボタン
	title_rules_picture_handle = -1;	//ルール画像

	//SE&BGMハンドル
	title_select_button_handle = 0;		//選択
	title_click_button_handle = 0;		//クリックする
	title_bgm_handle = 0;				//bgm

	//マウスを表示
	mouse_flag = TRUE;

	//マウスの座標
	mouseX = 0;
	mouseY = 0;
	//スタートボタン
	startPosX_L = 470;
	startPosY_L = 310;
	startPosX_R = startPosX_L + START_WIDE;
	startPosY_R = startPosY_L + START_HIGH;
	//ルールボタン
	rulesPosX_L = 480;
	rulesPosY_L = 480;
	rulesPosX_R = rulesPosX_L + TITLE_RULES_WIDE;
	rulesPosY_R = rulesPosY_L + TITLE_RULES_HIGH;
	//ボタンBool
	IsStart = false;	//スタートボタン
	IsRules = false;	//ルールボタン
	//選択遅延
	IsSlowSelect = false;
	//クリック遅延
	SlowClick = 0;
	//シーン遷移Bool
	SceneBool = false;
	//ルール表示Bool
	IsRulesDraw = false;
}
SceneTitle::~SceneTitle() { FinTitle(); }

// タイトルの初期化
void SceneTitle::InitTitle()
{
	//画像ハンドル
	title_bg_handle = LoadGraph(TITLE_BG_PATH);							//背景
	title_name_handle = LoadGraph(TITLE_NAME_PATH);						//タイトル名
	title_start_handle = LoadGraph(START_PATH);							//スタートボタン
	title_rules_handle = LoadGraph(TITLE_RULES_PATH);					//ルールボタン
	title_rules_picture_handle = LoadGraph(TITLE_RULES_PICTURE_PATH);	//ルール画像

	//BGM&SE
	title_select_button_handle = LoadSoundMem(SELECT_BUTTON_PATH);		//選択
	title_click_button_handle = LoadSoundMem(CLICK_BUTTOM_PATH);		//クリック
	title_bgm_handle = LoadSoundMem(TITLE_BGM_PATH);					//bgm

	//マウスを表示
	SetMouseDispFlag(mouse_flag);

	//bgm
	PlaySoundMem(title_bgm_handle, DX_PLAYTYPE_LOOP, true);

	//bgm音量調整
	ChangeVolumeSoundMem(100, title_bgm_handle);

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
		startPosX_L, startPosY_L, START_WIDE, START_HIGH))
	{
		if (IsStart == false)
		{
			//スタートBoolをtrueにする
			IsStart = true;
		}
		//選択遅延
		if (IsSlowSelect == false)
		{
			//一秒遅延
			IsSlowSelect = true;
			//SE
			PlaySoundMem(title_select_button_handle, DX_PLAYTYPE_BACK, true);	//選択
		}
		//左クリックを離す
		if (IsMouseRelease(MOUSE_INPUT_LEFT))
		{
			//シーン遷移Bool
			SceneBool = true;
			if (SlowClick == 0)
			{
				SlowClick = 60;
				//SE
				PlaySoundMem(title_click_button_handle, DX_PLAYTYPE_BACK, true);	//クリック
			}
		}
	}
	else if (IsStart == true)
	{
		if (Collision::Rect(mouseX, mouseY, 0, 0, startPosX_L - BUTTON_WIDE, startPosY_L - BUTTON_HIGH,
			START_WIDE + BUTTON_WIDE * 2, START_HIGH + BUTTON_HIGH * 2))
		{
			//左クリックを離す
			if (IsMouseRelease(MOUSE_INPUT_LEFT))
			{
				//シーン遷移Bool
				SceneBool = true;
				if (SlowClick == 0)
				{
					SlowClick = 60;
					//SE
					PlaySoundMem(title_click_button_handle, DX_PLAYTYPE_BACK, true);	//クリック
				}
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
		//選択遅延
		if (IsSlowSelect == false)
		{
			//一秒遅延
			IsSlowSelect = true;
			//SE
			PlaySoundMem(title_select_button_handle, DX_PLAYTYPE_BACK, true);	//選択
		}
		//左クリックを離す
		if (IsMouseRelease(MOUSE_INPUT_LEFT))
		{
			if (SlowClick == 0)
			{
				SlowClick = 60;
				//SE
				PlaySoundMem(title_click_button_handle, DX_PLAYTYPE_BACK, true);	//クリック
			}
			if (IsRulesDraw == false)
			{
				IsRulesDraw = true;
			}
			else
			{
				IsRulesDraw = false;
			}
		}
	}
	else if (IsRules == true)
	{
		if (Collision::Rect(mouseX, mouseY, 0, 0, rulesPosX_L - BUTTON_WIDE, rulesPosY_L - BUTTON_HIGH,
			TITLE_RULES_WIDE + BUTTON_WIDE * 2, TITLE_RULES_HIGH + BUTTON_HIGH))
		{
			//SE
			PlaySoundMem(title_select_button_handle, DX_PLAYTYPE_BACK, true);	//選択
			//左クリックを離す
			if (IsMouseRelease(MOUSE_INPUT_LEFT))
			{
				if (SlowClick == 0)
				{
					SlowClick = 60;
					//SE
					PlaySoundMem(title_click_button_handle, DX_PLAYTYPE_BACK, true);	//クリック
				}
				if (IsRulesDraw == false)
				{
					IsRulesDraw = true;
				}
				else
				{
					IsRulesDraw = false;
				}
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
	//両方のボタンに当たってないとき
	if (IsStart == false && IsRules == false)
	{
		//再び遅延
		IsSlowSelect = false;
	}
	//クリック遅延
	if (SlowClick != 0)
	{
		SlowClick--;
	}
	if (SlowClick == 0 && SceneBool == true)
	{
		//タイトルに移行
		g_CurrentSceneID = SCENE_ID_FIN_TITLE;
	}
	
}

// タイトル描画処理
void SceneTitle::DrawTitle()
{
	DrawGraph(0, 0, title_bg_handle, true);			//背景
	DrawGraph(340, 45, title_name_handle, true);	//タイトル名
	if (IsStart == true)
	{
		DrawExtendGraph(startPosX_L - BUTTON_WIDE, startPosY_L - BUTTON_HIGH,
			startPosX_R + BUTTON_WIDE, startPosY_R + BUTTON_HIGH, title_start_handle, true);	//スタートボタン
	}
	else
	{
		DrawExtendGraph(startPosX_L, startPosY_L, startPosX_R, startPosY_R, title_start_handle, true);		//スタートボタン
	}
	if (IsRules == true)
	{
		DrawExtendGraph(rulesPosX_L - BUTTON_WIDE, rulesPosY_L - BUTTON_HIGH,
			rulesPosX_R + BUTTON_WIDE, rulesPosY_R + BUTTON_HIGH, title_rules_handle, true);	//ルールボタン
	}
	else
	{
		DrawExtendGraph(rulesPosX_L, rulesPosY_L, rulesPosX_R, rulesPosY_R, title_rules_handle, true);		//ルールボタン
	}

	//ルール表示
	if (IsRulesDraw == true)
	{
		DrawGraph(100, 275, title_rules_picture_handle, true);
	}
}

// タイトル終了処理
void SceneTitle::FinTitle()
{
	//画像破棄
	DeleteGraph(title_bg_handle);				//背景
	DeleteGraph(title_name_handle);				//タイトル名
	DeleteGraph(title_start_handle);			//スタートボタン
	DeleteGraph(title_rules_handle);			//ルールボタン
	DeleteGraph(title_rules_picture_handle);	//ルール画像

	//SE&BGM
	DeleteSoundMem(title_select_button_handle);	//選択
	DeleteSoundMem(title_click_button_handle);	//クリック
	DeleteSoundMem(title_bgm_handle);			//bgm

	//選択遅延
	IsSlowSelect = false;
	//シーン遷移Bool
	SceneBool = false;

	//ルールを非表示にする
	IsRulesDraw = false;

	// プレイシーンに移動
	g_CurrentSceneID = SCENE_ID_INIT_PLAY;
}

