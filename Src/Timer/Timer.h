// ���c
#pragma once

class Timer {
private:
	// �^�C�}�[�̍��W
	int TimerPosX, TimerPosY;

	// �^�C�}�[�̃T�C�Y
	int TimerWidth;
	int TimerHeight;

	// �^�C�}�[�̑���
	int TimerMinusSpeed;
	int TimerPlusSpeed;

	// �J�E���g�ϐ�
	int CountNum;

public:
	Timer();
	~Timer();

	// Timer�̏�����
	void Init();

	// Timer�ʏ폈��
	void Step();

	// Timer�`�揈��
	void Draw();

	// Timer�I������
	void Fin();
};

