#pragma once

#define KEY_BUF_LEN	(256)

class InputKey {
private:

public:

};

//入力制御初期化
void InitInput();

//入力制御ステップ
//他のStepより早く呼ぶ
void StepInput();

//単純に押されているか
bool IsKeyDown(int key_code);

//今押された
bool IsKeyPush(int key_code);

//押し続けられているか
bool IsKeyKeep(int key_code);

//たった今離されたか
bool IsKeyRelease(int key_code);
