#pragma once

#define KEY_BUF_LEN	(256)

//���͐��䏉����
void InitInput();

//���͐���X�e�b�v
//����Step��葁���Ă�
void StepInput();

class InputKey {
public:
//�P���ɉ�����Ă��邩
static bool Down(int key_code);

//�������ꂽ
static bool Push(int key_code);

//�����������Ă��邩
static bool Keep(int key_code);

//�������������ꂽ��
static bool Release(int key_code);
};
