#include <ansi.h>
inherit NPC;
inherit SELLMAN;
void create()
{
//=========================�򥻳]�w==========================

        set_name( "�A�Ȥp�j", ({ "bar lady","lady"}));
        set("long",@LONG
        �@�Ӱs�����A�Ȥp�j�A���b��ۧA���y�C
	==============================================
	�ؿ� <list>
	�R�F�� <buy ���~> <buy �ƶq ���~>
	==============================================
LONG);
        set("level",17);
        set("gender", "�k��");
        set("race", "human");
        set("age", 33);
        set("evil",-10);			//���c�� 20 (�������c, �t���})

	set("attitude", "peaceful");   //�ũM�� NPC�C
	set("talk_reply","�ڭ̽檺�s�i�O�ܨ��w�諸��!!");
	set("sell_list",([
  __DIR__"../obj/bloodmarry_wine" : 15,
  __DIR__"../obj/bluegimi_wine" : 20,
  __DIR__"../obj/beer" : 5,
  __DIR__"../obj/greentea" : 10,
]));

//===========================���D�^��==================================
set("inquiry/name", @LONG
  [1;36m �ڥs���p��.. �Цh����!![m
LONG );
        setup();
      add_money("dollar", 780);		//�a����
      carry_object(__DIR__"../eq/cloth_clothes_f_5")->wear();
      carry_object(__DIR__"../eq/gem_ring_1")->wear();
      carry_object(__DIR__"../eq/leather_boots_f_5")->wear();
      carry_object(__DIR__"../eq/cloth_gloves_3")->wear();
}

void init()
{
	::init();
	add_action("do_list","list");
	add_action("do_buy","buy");
}

