#pragma once

// �摜�p�X
#define TITLE_BG_PATH				"Data/TitleImage/TitleGround.png"	// �w�i
#define TITLE_NAME_PATH				"Data/TitleImage/TitleName.png"		//�^�C�g����
#define TITLE_RULES_PATH			"Data/TitleImage/rules.png"			//���[���{�^��
#define TITLE_RULES_PICTURE_PATH	"Data/TitleImage/RulesPicture"		//���[�������摜
//�摜�T�C�Y
#define TITLE_START_WIDE	(340)		//�X�^�[�g��
#define TITLE_START_HIGH	(100)		//�X�^�[�g����
#define TITLE_RULES_WIDE	(320)		//���[����
#define TITLE_RULES_HIGH	(100)		//���[������
//�{�^���̊g���
#define TITLE_BUTTON_WIDE	(50)		//��
#define TITLE_BUTTON_HIGH	(20)		//����

class SceneTitle {
private:
	//�摜�n���h��
	int title_bg_handle;	// �w�i
	int title_name_handle;	//�^�C�g����
	int title_start_handle;	//�X�^�[�g�{�^��
	int title_rules_handle;	//���[���{�^��
	//�}�E�X�̕\���ݒ�
	int mouse_flag;
	//���W
	//�}�E�X�̍��W
	int mouseX;
	int mouseY;
	//�X�^�[�g�{�^��
	int startPosX_L;
	int startPosY_L;
	int startPosX_R;
	int startPosY_R;
	//���[���{�^��
	int rulesPosX_L;
	int rulesPosY_L;
	int rulesPosX_R;
	int rulesPosY_R;
	//�{�^��Bool
	bool IsStart;	//�X�^�[�g�{�^��
	bool IsRules;	//���[���{�^��

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
