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
        	    +"  �ݦs�f�Х� <show> \n"
        	    +"  �n�R�F��� <take ���~> <take �ƶq ���~> \n\n"
        );
        set("level",20);
        set("title","[1;32m�p�c[m");
        set("gender", "�k��");
        set("race", "�H��");
        set("age", 42);
        set("exp",1000);		//���a�����|�o��exp/10 (�i�K)
        				//��ĳ���n�ۤv�]exp. �Ѩt�ΨM�w
        				//�H�K���Pwiz�g��mob �|�X�{�Ӥj���t��
        				
        set("str",31);			//�]�w�ݩ�(�i�K)
        set("dex",21);			//�]�i�H�u�]�w level
        set("con",33);			//��L�S�]�w���ݩʨt�δN�|�۰ʲ���,
        set("int",18);			//�Y�ϬO�ۦP��level�]�|�����P�ݩ�.
        
        set("combat_exp",2000);		//�Լ�(���bmob level��100�����k���y)
//        set("env/wimpy", 20);		//�k�]wimpy (20%)
        set("evil",-20);		//���c�� 20 (�������c, �t���})

	set_skill("blade",40);		// �ޯ�(�۩w)
	set_skill("parry",20);		//
	set_skill("dodge",30);		//

   set("attitude", "peaceful");   //�ũM�� NPC�C
   set("talk_reply","�h�R�I�F��N�����F�j���o..����..");
	//�`�N. �n�]�w�f�~�M��
   set("sell_list",([	
           "/u/l/luky/npc/item/bag"    : 25, //��ܨC�R�@�ӳU�l�|��15�I�ɵ��I��
           "/u/l/luky/npc/item/dump"   : 10, //���D���S��z�ѧ_�h���i�]��0 (�L���q����)
       ]) );

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
add_action("do_list","show");
add_action("do_buy","take");
}


