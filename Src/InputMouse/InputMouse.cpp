#include "DxLib.h"

//�}�E�X����F����
//#define CLICK_BUF_LEN (3)

//���݃t���[���̃N���b�N���
//int currentMouseBuf[CLICK_BUF_LEN];
int currentMouseBuf;

//�O�t���[���̃N���b�N���
//int preMouseBuf[CLICK_BUF_LEN];
int preMouseBuf;

//���͐��䏉����
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

//���͐���X�e�b�v
//����Step��葁���Ă�
void StepInputMouse()
{
	//�O�t���[���̃L�[���ϐ��ɋL�^���Ă���
	//for (int index = 0; index < CLICK_BUF_LEN; index++)
	//{
	//	preMouseBuf[index] = currentMouseBuf[index];
	//}

	preMouseBuf = currentMouseBuf;

	//���݂̃N���b�N�����擾
	//currentMouseBuf[0] = GetMouseInput();
	currentMouseBuf = GetMouseInput();
}

//�������ꂽ
bool IsMouseClick(int key_code)
{
	//���N���b�N
	//�O�t���ŉ�����ĂȂ� ���� ���t���ŉ�����Ă���
	if (preMouseBuf != key_code && currentMouseBuf== key_code)
	{
		return true;
	}

	//������ĂȂ��̂� false
	return false;
}

//�����ꑱ���Ă���
bool IsMouseKeep(int key_code)
{
	//�O�t���ł�����Ă��� ���� ���t���ŉ�����Ă���
	if (preMouseBuf == key_code && currentMouseBuf == key_code)
		return true;

	return false;
}

//�����ꂽ
bool IsMouseRelease(int key_code)
{
	//�O�t���ŉ�����Ă��� ���� ���t���ŉ�����Ă��Ȃ�
	if (preMouseBuf == key_code && currentMouseBuf != key_code)
		return true;

	return false;
}

//�P���ɉ�����Ă��邩
bool IsMouseDown(int key_code)
{
	//���t���ŉ�����Ă���i�O�t���̏�Ԃ͊֌W�Ȃ��j
	if (currentMouseBuf == key_code)
		return true;

	return false;
}