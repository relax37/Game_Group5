#pragma once

// �摜�p�X
#define TITLE_BG_PATH				"Data/TitleImage/TitleGround.png"	// �w�i
#define TITLE_NAME_PATH				"Data/TitleImage/TitleName.png"		//�^�C�g����
#define TITLE_RULES_PATH			"Data/TitleImage/rules.png"			//���[���{�^��
#define TITLE_RULES_PICTURE_PATH	"Data/TitleImage/RulesPicture.png"		//���[���摜
//�摜�T�C�Y
#define TITLE_RULES_WIDE	(320)		//���[����
#define TITLE_RULES_HIGH	(100)		//���[������

class SceneTitle {
private:
	//�摜�n���h��
	int title_bg_handle;			// �w�i
	int title_name_handle;			//�^�C�g����
	int title_start_handle;			//�X�^�[�g�{�^��
	int title_rules_handle;			//���[���{�^��
	int title_rules_picture_handle;	//���[���摜
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
	//���[���\��Bool
	bool IsRulesDraw;

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
