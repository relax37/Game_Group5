#include "DxLib.h"
#include "Scene.h"
#include "SceneTitle.h"

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

	//マウスのボタンの状態を得る(前の
	if (IsMouseRelease(MOUSE_INPUT_LEFT))
	{
		//テスト
	}

	switch (title_select)
	{
		//スタートボタンを拡大
	case TitleSelect::START_BOTTUN:
		
		break;
		//ルールボタンを拡大
	case TitleSelect::RULES_BOTTUN:

		break;
	}

	// Enterを押したら
	if(InputKey::Push(KEY_INPUT_RETURN))
	{
		// タイトルシーンを終了
		FinTitle();
	}
}

// タイトル描画処理
void SceneTitle::DrawTitle()
{
	DrawGraph(0, 0, title_bg_handle, true);			//背景
	DrawGraph(340, 60, title_name_handle, true);	//タイトル名
	DrawGraph(470, 310, title_start_handle, true);	//スタートボタン
	DrawGraph(480, 480, title_rules_handle, true);	//ルールボタン
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
