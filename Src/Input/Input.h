#pragma once

#define KEY_BUF_LEN	(256)

class InputKey {
private:

public:

};

//���͐��䏉����
void InitInput();

//���͐���X�e�b�v
//����Step��葁���Ă�
void StepInput();

//�P���ɉ�����Ă��邩
bool IsKeyDown(int key_code);

//�������ꂽ
bool IsKeyPush(int key_code);

//�����������Ă��邩
bool IsKeyKeep(int key_code);

//�������������ꂽ��
bool IsKeyRelease(int key_code);
