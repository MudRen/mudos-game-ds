// �ӤH�d��(1) 
// by Luky 19993.20
#include <ansi.h>
inherit NPC;
inherit SHOPMAN;
void create()
{
//=========================�򥻳]�w==========================

        set_name( "�L����", ({ "boss lin","lin","boss"}));
        set("long", "�@�ӭD�D�����~�k�H�M�ǬN����ۧA���ۡC\n\n"
        	    +"  �ݦs�f�Х� <list> <list wp> <list eq>\n"
        	    +"  �n�R�F��� <buy ���~> <buy �ƶq ���~> \n"
        	    +"  �n��F��� <sell ���~> <sell all> <sell �ƶq ���~>\n\n"
        );
        set("level",20);
        set("title","[1;32m�ӤH[m");
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
        set("evil",20);			//���c�� 20 (�������c, �t���})

	set_skill("blade",40);		// �ޯ�(�۩w)
	set_skill("parry",20);		//
	set_skill("dodge",30);		//

   set("attitude", "peaceful");   //�ũM�� NPC�C
   set("talk_reply","�n��.. �h���Ф@�ǪB�ͨӶR�F��a!!");
	set("storeroom","/u/l/luky/shop");	//�`�N. �n�إߤ@��room��F��(�Ѧ�/u/l/luky/shop.c)

  set("chat_chance", 3 );  //�ʧ@���v
  set("chat_msg", ({       //�ʧ@���e
"�L���󯺯�����: �p�S��, �n���n�R�I�F���? �ڥi�H��A�K�y�@�I��..\n",
(:command("smile"):),
}) );

//===========================���D�^��==================================
set("inquiry/name", @LONG
  [1;36m �ڥs���L�j�o.. �Цh����!![m
LONG );

        setup();

      add_money("coin", 120);		//�a����
      carry_object(__DIR__"item/bag");
      carry_object(__DIR__"eq/blackjacket")->wear();
}

void init()
{
add_action("do_list","list");
add_action("do_buy","buy");
add_action("do_sell","sell");
}


