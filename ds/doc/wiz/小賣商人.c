// �ӤH�d��(1) 
// by Luky 19993.20
#include <ansi.h>
inherit NPC;
inherit SELLMAN;
void create()
{
//=========================�򥻳]�w==========================

        set_name( "���j�o", ({ "dar far wang","wang"}));
        set("long", "�@�ӥ��u���~���H�M���b�o���\\�u���Ȩ��ǶO�C\n\n"
        	    +"  �ݦs�f�Х� <list> \n"
        	    +"  �n�R�F��� <buy ���~> <buy �ƶq ���~> \n\n"
        );
        set("level",20);
        set("title","[1;32m�p�c[m");
        set("gender", "�k��");
        set("race", "�H��");
        set("age", 42);
        set("combat_exp",2000);		//�Լ�(���bmob level��100�����k���y)
//        set("env/wimpy", 20);		//�k�]wimpy (20%)
        set("evil",-20);		//���c�� 20 (�������c, �t���})

   set("attitude", "peaceful");   //�ũM�� NPC�C
   set("talk_reply","�h�R�I�F��N�����F�j���o..����..");

//�`�N. �n�]�w�f�~�M��

   set("sell_list",([	
           "/u/l/luky/npc/item/bag"    : 25, //��ܨC�R�@�ӳU�l�|��15�I�ɵ��I��
           "/u/l/luky/npc/item/dump"   : 10, //���D���S��z�ѧ_�h���i�]��0 (�L���q����)
       ]) );				     //���a�򥻦�40�I, �C�@���ŦA�[20�I. Lv25=540�I

  set("chat_chance", 3 );  //�ʧ@���v
  set("chat_msg", ({       //�ʧ@���e
"���j�o��������: �j����, �n���n�R�I�F��<take>��? �ڽ檺�F��<show>�O����̫K�y����!\n",
(:command("dance master"):),
(:command("coffee wang"):),
}) );

//===========================���D�^��==================================
set("inquiry/name", @LONG
  [1;36m �ڥs�����j�o.. �Цh����!![m
LONG );

        setup();

      add_money("coin", 120);		//�a����
      carry_object(__DIR__"item/bag");
      carry_object(__DIR__"eq/blackjacket")->wear();
}

void init()
{
	::init();
	add_action("do_list","list");
	add_action("do_buy","buy");
}


