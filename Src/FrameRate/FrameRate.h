#pragma once

//�ݒ�t���[�����[�g�i60FPS�j
#define FRAME_RATE	(60)

//1�t���[���̎���
#define FRAME_TIME	(1000/FRAME_RATE)

//FPS����
void ProcessingFPS();

//FPS�v�Z
void CalcFPS();

//FPS�\���i�f�o�b�N�p�j
void DrawFPS();
