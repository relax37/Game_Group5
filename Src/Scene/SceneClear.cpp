//高松
#include "DxLib.h"
#include "Scene.h"
#include "SceneClear.h"
#include "../Collision/Collision.h"

SceneClear::SceneClear() 
{
	//画像ハンドル
	clear_bg_handle = 0;		//背景
	clear_win_handle = 0;		//勝つ
	clear_start_handle = 0;		//スタートボタン
	clear_title_handle = 0;		//タイトルボタン
	clear_score_handle = 0;		//スコアボード
	clear_font_handle = 0;		//フォント
	//SE&BGMハンドル
	clear_select_button_handle = 0;	//選択
	clear_click_button_handle = 0;	//クリックする
	clear_clear_handle = 0;			//クリア
	//マウスの表示設定
	mouse_flag=TRUE;		//表示
	//座標
	//マウスの座標
	mouseX = 0;
	mouseY = 0;
	//スタートボタン
	startPosX_L = 150;
	startPosY_L = 500;
	startPosX_R = startPosX_L + START_WIDE;
	startPosY_R = startPosY_L + START_HIGH;
	//タイトルボタン
	titlePosX_L = 790;
	titlePosY_L = 500;
	titlePosX_R = titlePosX_L + TITLE_WIDE;
	titlePosY_R = titlePosY_L + TITLE_HIGH;
	//ボタンBool
	IsStart = false;	//スタートボタン
	IsTitle = false;	//タイトルボタン
	//選択遅延
	IsSlowSelect = false;
	//クリック遅延
	SlowClick = 0;
	//シーン遷移Bool
	SceneBool = false;
	//タイトルかプレイか
	IsFromScene = -1;
}
SceneClear::~SceneClear() { FinClear(); }

//クリアシーン初期化
void SceneClear::InitClear()
{
	//画像ハンドル
	clear_bg_handle = LoadGraph(CLEAR_BG_PATH);		//背景
	clear_win_handle = LoadGraph(CLEAR_WIN_PATH);	//勝つ
	clear_start_handle = LoadGraph(START_PATH);		//スタートボタン
	clear_title_handle = LoadGraph(TITLE_PATH);		//タイトルボタン
	clear_score_handle = LoadGraph(SCORE_PATH);		//スコアボード
	//SE&BGMパス
	clear_select_button_handle = LoadSoundMem(SELECT_BUTTON_PATH);	//選択
	clear_click_button_handle = LoadSoundMem(CLICK_BUTTOM_PATH);	//クリックする
	clear_clear_handle = LoadSoundMem(CLEAR_WIN_SE_PATH);			//クリア
	// フォント設定
	clear_font_handle = CreateFontToHandle("HGP創英ﾌﾟﾚｾﾞﾝｽEB", 48, 3, DX_FONTTYPE_NORMAL);

	//クリアSE
	PlaySoundMem(clear_clear_handle, DX_PLAYTYPE_BACK, true);

	//マウスを表示
	SetMouseDispFlag(mouse_flag);

	//クリアシーンループへ
	g_CurrentSceneID = SCENE_ID_LOOP_CLEAR;
}

//クリアシーン通常処理
void SceneClear::StepClear()
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
			PlaySoundMem(clear_select_button_handle, DX_PLAYTYPE_BACK, true);	//選択
		}
		//左クリックを離す
		if (IsMouseRelease(MOUSE_INPUT_LEFT))
		{
			//後にプレイシーンへ移動
			IsFromScene = CLEAR_FROM_SCENE::CLEAR_FROM_PLAY;
			//シーン遷移Bool
			SceneBool = true;
			if (SlowClick == 0)
			{
				SlowClick = 60;
				//SE
				PlaySoundMem(clear_click_button_handle, DX_PLAYTYPE_BACK, true);	//クリック
			}
		}
	}
	else if (IsStart == true)
	{
		if (Collision::Rect(mouseX, mouseY, 0, 0, startPosX_L - BUTTON_WIDE, startPosY_L - BUTTON_HIGH,
			START_WIDE + BUTTON_WIDE * 2, START_HIGH + BUTTON_HIGH * 2))
		{
			//SE
			PlaySoundMem(clear_select_button_handle, DX_PLAYTYPE_BACK, true);	//選択
			//左クリックを離す
			if (IsMouseRelease(MOUSE_INPUT_LEFT))
			{
				//後にプレイシーンへ移動
				IsFromScene = CLEAR_FROM_SCENE::CLEAR_FROM_PLAY;
				//シーン遷移Bool
				SceneBool = true;
				if (SlowClick == 0)
				{
					SlowClick = 60;
					//SE
					PlaySoundMem(clear_click_button_handle, DX_PLAYTYPE_BACK, true);	//クリック
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
	//マウスとタイトルボタンの当たり判定
	if (Collision::Rect(mouseX, mouseY, 0, 0,
		titlePosX_L, titlePosY_L, TITLE_WIDE, TITLE_HIGH))
	{
		if (IsTitle == false)
		{
			//タイトルBoolをtrueにする
			IsTitle = true;
		}
		//選択遅延
		if (IsSlowSelect == false)
		{
			//一秒遅延
			IsSlowSelect = true;
			//SE
			PlaySoundMem(clear_select_button_handle, DX_PLAYTYPE_BACK, true);	//選択
		}
		//左クリックを離す
		if (IsMouseRelease(MOUSE_INPUT_LEFT))
		{
			//後にタイトルシーンへ移動
			IsFromScene = CLEAR_FROM_SCENE::CLEAR_FROM_TITLE;
			if (SlowClick == 0)
			{
				SlowClick = 60;
				//SE
				PlaySoundMem(clear_click_button_handle, DX_PLAYTYPE_BACK, true);	//クリック
			}
		}
	}
	else if (IsTitle == true)
	{
		if (Collision::Rect(mouseX, mouseY, 0, 0, titlePosX_L - BUTTON_WIDE, titlePosY_L - BUTTON_HIGH,
			TITLE_WIDE + BUTTON_WIDE * 2, TITLE_HIGH + BUTTON_HIGH))
		{
			//SE
			PlaySoundMem(clear_select_button_handle, DX_PLAYTYPE_BACK, true);	//選択
			if (IsTitle == false)
			//左クリックを離す
			if (IsMouseRelease(MOUSE_INPUT_LEFT))
			{
				//後にタイトルシーンへ移動
				IsFromScene = CLEAR_FROM_SCENE::CLEAR_FROM_TITLE;
				if (SlowClick == 0)
				{
					SlowClick = 60;
					//SE
					PlaySoundMem(clear_click_button_handle, DX_PLAYTYPE_BACK, true);	//クリック
				}
			}
		}
		//当たってないとき
		else
		{
			IsTitle = false;
		}
	}
	//当たってないとき
	else
	{
		IsTitle = false;
	}
	//両方のボタンに当たってないとき
	if (IsStart == false && IsTitle == false)
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
		//クリア後処理に移行
		g_CurrentSceneID = SCENE_ID_FIN_CLEAR;
	}
}

//クリアシーン描画処理
void SceneClear::DrawClear()
{
	//画像描画
	DrawGraph(0, 0, clear_bg_handle, true);			//背景
	DrawGraph(340, 50, clear_win_handle, true);		//勝つ
	if (IsStart == true)
	{
		DrawExtendGraph(startPosX_L - BUTTON_WIDE, startPosY_L - BUTTON_HIGH,
			startPosX_R + BUTTON_WIDE, startPosY_R + BUTTON_HIGH, clear_start_handle, true);	//スタートボタン
	}
	else
	{
		DrawExtendGraph(startPosX_L, startPosY_L, startPosX_R, startPosY_R, clear_start_handle, true);		//スタートボタン
	}
	if (IsTitle == true)
	{
		DrawExtendGraph(titlePosX_L - BUTTON_WIDE, titlePosY_L - BUTTON_HIGH,
			titlePosX_R + BUTTON_WIDE, titlePosY_R + BUTTON_HIGH, clear_title_handle, true);	//タイトルボタン
	}
	else
	{
		DrawExtendGraph(titlePosX_L, titlePosY_L, titlePosX_R, titlePosY_R, clear_title_handle, true);		//タイトルボタン
	}
	DrawGraph(447, 200, clear_score_handle, true);		//スコアボード
	//スコア表示
	if (Score >= 0 && Score < 10)
	{
		DrawFormatStringToHandle(WINDOW_WIDTH / 2 - 9, 340, GetColor(255, 0, 0), clear_font_handle, "%d", Score);
	}
	else if (Score >= 10 && Score < 100)
	{
		DrawFormatStringToHandle(WINDOW_WIDTH / 2 - 17, 340, GetColor(255, 0, 0), clear_font_handle, "%d", Score);
	}
	else if (Score >= 100 && Score < 1000)
	{
		DrawFormatStringToHandle(WINDOW_WIDTH / 2 - 33, 340, GetColor(255, 0, 0), clear_font_handle, "%d", Score);
	}
}

//クリアシーン終了処理
void SceneClear::FinClear()
{
	//画像ハンドル
	DeleteGraph(clear_bg_handle);		//背景
	DeleteGraph(clear_win_handle);		//勝つ
	DeleteGraph(clear_start_handle);	//スタートボタン
	DeleteGraph(clear_title_handle);	//タイトルボタン
	DeleteGraph(clear_score_handle);	//スコアボード

	//SE&BGM
	DeleteSoundMem(clear_select_button_handle);		//選択
	DeleteSoundMem(clear_click_button_handle);		//クリック
	DeleteSoundMem(clear_clear_handle);				//クリア

	//選択遅延
	IsSlowSelect = false;
	//シーン遷移Bool
	SceneBool = false;

	//フォント
	clear_font_handle = 0;

	// スコアの初期化
	Score = 0;

	if (IsFromScene == CLEAR_FROM_SCENE::CLEAR_FROM_TITLE)
	{
		//タイトルシーンへ移動
		g_CurrentSceneID = SCENE_ID_INIT_TITLE;
	}
	else if (IsFromScene == CLEAR_FROM_SCENE::CLEAR_FROM_PLAY)
	{
		//プレイシーンへ移動
		g_CurrentSceneID = SCENE_ID_INIT_PLAY;
	}
}
