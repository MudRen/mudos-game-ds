// �ӤH�d��(1) 
// by Luky 19993.20
#include <ansi.h>
inherit NPC;
inherit SHOPMAN;
void create()
{
//=========================�򥻳]�w==========================

        set_name( "�ө�����", ({ "shop boss","boss"}));
        set("long",@LONG
        �@�ӭD�D�����~�k�H�A���b�M��f�[�C
	==============================================
	�d�ߦs�f 	<list> <list wp> <list eq>
	�R�F�� 		<buy ���~> <buy �ƶq ���~>
	��F�� 		<sell ���~> <sell all> <sell �ƶq ���~>
	�եΪF�� 	<try ���~>
	==============================================
LONG);
        set("level",19);
        set("title","[1;32m�ӤH[m");
        set("gender", "�k��");
        set("race", "human");
        set("age", 42);
        set("evil",10);			//���c�� 20 (�������c, �t���})

	set("attitude", "peaceful");   //�ũM�� NPC�C
	set("talk_reply","�n��.. �h���Ф@�ǪB�ͨӶR�F��a!!");
	set("storeroom",__DIR__"shop1");	//�`�N. �n�إߤ@��room��F��

//===========================���D�^��==================================
set("inquiry/name", @LONG
  [1;36m �ڥs���L�_.. �Цh����!![m
LONG );
        setup();
      add_money("dollar", 1100);		//�a����
      carry_object(__DIR__"../eq/cloth_pants_5")->wear();
      carry_object(__DIR__"../eq/leather_boots_3")->wear();
      carry_object(__DIR__"../eq/cloth_clothes_5")->wear();
}

void init()
{
	::init();
	add_action("do_list","list");
	add_action("do_buy","buy");
	add_action("do_sell","sell");
	add_action("do_try","try");
}


