#include <ansi.h>
#include <box.h>
//#define COVER_NONE 	   	2
//#define COVER_OPENED    	3
//#define COVER_CLOSED		4
//#define COVER_SMASHED		5
//#define LOCK_NONE		6
//#define LOCK_OPENED	    	7
//#define LOCK_CLOSED		8
//#define LOCK_SMASHED		9
//inherit F_CLEAN_UP;
inherit BOX;
void create()
{

	set_name("ż�K�c",({"dirty box","box"}));
        set("unit", "��");
        set("long",@LONG

�A�ݨ�@�ӻ�ż���K�c�l�A�j���s��̽m�߶}��Ϊ��C

  �o���K�c�i�H�θU��P���}��άO�W��A�A�i�H
  �N�c�l��W(lock box with dagger)�άO���}��
  (unlock box with dagger)�C

  �p�G�A�Q�Υ��ӽm�߶}��A��ĳ�A�i�H���N�c�l
  ��W�M��յۨϥζ}��ޥ��Ӷ}�ҥ�(pick box)�C

LONG
);
        set("value", 1);
        set("no_sac", 1);
        set("no_get", 1);
        
        set_max_encumbrance(300000);
        set_max_capacity(50);
	set("cover_name","�K�\\");	//�\�l�W��
	set_cover(COVER_CLOSED);	//��l�\�l���A == ����
	set_lock(LOCK_CLOSED);		//��l�ꪬ�A == ��W
	set_keys( ({"/open/always/thief_mark"}) ); //�ϥ��_���ɮ�
	set_lock_level(1); //�]�w�ꪺ���� 1~10
	setup();
}

