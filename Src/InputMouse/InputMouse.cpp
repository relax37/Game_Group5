#include "DxLib.h"

//マウス周り認識数
//#define CLICK_BUF_LEN (3)

//現在フレームのクリック情報
//int currentMouseBuf[CLICK_BUF_LEN];
int currentMouseBuf;

//前フレームのクリック情報
//int preMouseBuf[CLICK_BUF_LEN];
int preMouseBuf;

//入力制御初期化
void InitInputMouse()
{
	/*for (int i = 0; i < CLICK_BUF_LEN; i++)
	{
		currentMouseBuf[i] = 0;
		preMouseBuf[i] = 0;
	}*/
	currentMouseBuf = 0;
	preMouseBuf = 0;
}

//入力制御ステップ
//他のStepより早く呼ぶ
void StepInputMouse()
{
	//前フレームのキー情報変数に記録しておく
	//for (int index = 0; index < CLICK_BUF_LEN; index++)
	//{
	//	preMouseBuf[index] = currentMouseBuf[index];
	//}

	preMouseBuf = currentMouseBuf;

	//現在のクリック情報を取得
	//currentMouseBuf[0] = GetMouseInput();
	currentMouseBuf = GetMouseInput();
}

//今押された
bool IsMouseClick(int key_code)
{
	//左クリック
	//前フレで押されてない かつ 現フレで押されている
	if (preMouseBuf != key_code && currentMouseBuf== key_code)
	{
		return true;
	}

	//押されてないので false
	return false;
}

//押され続けている
bool IsMouseKeep(int key_code)
{
	//前フレでおされている かつ 現フレで押されている
	if (preMouseBuf == key_code && currentMouseBuf == key_code)
		return true;

	return false;
}

//離された
bool IsMouseRelease(int key_code)
{
	//前フレで押されていた かつ 現フレで押されていない
	if (preMouseBuf == key_code && currentMouseBuf != key_code)
		return true;

	return false;
}

//単純に押されているか
bool IsMouseDown(int key_code)
{
	//現フレで押されている（前フレの状態は関係なし）
	if (currentMouseBuf == key_code)
		return true;

	return false;
}