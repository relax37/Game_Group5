#pragma once

// �摜�p�X
#define TITLE_BG_PATH		"Data/TitleImage/TitleGround.png"	// �w�i
#define TITLE_NAME_PATH		"Data/TitleImage/TitleName.png"		//�^�C�g����
#define TITLE_START_PATH	"Data/TitleImage/start.png"			//�X�^�[�g�{�^��
#define TITLE_RULES_PATH	"Data/TitleImage/rules.png"			//���[���{�^��

enum TitleSelect
{
	START_BOTTUN,
	RULES_BOTTUN
};

class SceneTitle {
private:
	//�摜�n���h��
	int title_select;		//���̃{�^�����g�傷�邩
	int title_bg_handle;	// �w�i
	int title_name_handle;	//�^�C�g����
	int title_start_handle;	//�X�^�[�g�{�^��
	int title_rules_handle;	//���[���{�^��
	//�}�E�X�̕\���ݒ�
	int mouse_flag;
	//�}�E�X�̍��W
	int mouseX;
	int mouseY;

public:
	SceneTitle();
	~SceneTitle();

	// �^�C�g���̏�����
	void InitTitle();

	// �^�C�g���ʏ폈��
	void StepTitle();

	// �^�C�g���`�揈��
	void DrawTitle();

	// �^�C�g���I������
	void FinTitle();
};
