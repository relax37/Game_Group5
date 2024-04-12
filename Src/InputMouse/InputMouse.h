#pragma once

//入力制御初期化
void InitInputMouse();

//入力制御ステップ
//他のStepより早く呼ぶ
void StepInputMouse();

//今押された
bool IsMouseClick(int key_code);

//押しているか
bool IsMouseKeep(int key_code);

//離された
bool IsMouseRelease(int key_code);

//単純に押されているか
bool IsMouseDown(int key_code);
