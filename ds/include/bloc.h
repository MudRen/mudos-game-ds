#ifndef __BLOC_H__
#define __BLOC_H__

//
// �p��¾��
//
string *__E_Bloc_Rank_Table__ = ({"none","first","second","presbyter",
				"third","fourth","fifth",
				"sixth","seventh","eighth",
				"ninth"});
// ��l�p��¾���
string *CBlocRankTable = ({"�S��","�`��","���`��","����","�j��",
			"����","�Ƴ���","�ժ�","�Ʋժ�",
			"�խ�","��ߥ�" });

#define __BlocFileLocate__	"/data/bloc/"
#define __BlocInfoFile__	__BlocFileLocate__ + "bloc"
#define BlocData(x)		( __BlocFileLocate__ + x +".info" )

//string *__E_Bloc_Rank_Table__ = ({"director","deputy_director","presbyter",
//				"official","minister","vice_minister",
//				"chief","vice_chief","member",
//				"trainee"});

#define FIRST		1
#define SECOND		2
#define PRESBYTER	3
#define THIRD		4
#define FOURTH		5
#define FIFTH		6
#define SIXTH		7
#define SEVENTH		8
#define EIGHTH		9
#define NINTH		10

//
// �p�����O�v��
//

string *__BLOC_CMDS_TABLE__ = ({"Void","creat","ruin","setrank","setcmds","setmark","creatroom","addmember","kickmember","show"});

#define BLOC_CMDS_Void		0	// �ŵL���O
#define BLOC_CMDS_CREAT		1	// �إ��p��
#define BLOC_CMDS_RUIN		2	// �����p��
#define BLOC_CMDS_SETRANK	3	// �]�w�p���U¾�Ȫ��W��
#define BLOC_CMDS_SETCMDS	4	// �]�w�p���U¾�Ȫ��ۭq���O
#define BLOC_CMDS_SETMARK	5	// �إ��p�����лx
#define BLOC_CMDS_CREATROOM	6	// �إ��p���ж�
#define BLOC_CMDS_ADDMEMBER	7	// �W�[����
#define BLOC_CMDS_KICKMEMBER	8	// �R������
#define BLOC_CMDS_SHOW		9	// ����p����T

#endif
