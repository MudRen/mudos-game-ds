// �����ӤH�d��(1) 
// by Luky 19993.20
#include <ansi.h>
inherit NPC;
inherit LOTTERYMAN;
void create()
{
//=========================�򥻳]�w==========================

        set_name( "�ª���", ({ "heish choun ting","ting"}));
        set("long", "�@�����۲��誺���~�H�M���b�o���\\�u���m���C\n\n"
        	    +"  �ݦs�f�Х� <list> \n"
        	    +"  �n�R�F��� <buy ���~> <buy �ƶq ���~> \n"
        	    +"  �n����� <reward> \n\n"
        );
        set("level",20);
        set("title","[1;32m������[m");
        set("gender", "�k��");
        set("race", "�H��");
        set("age", 42);
        set("exp",1000);		//���a�����|�o��exp/10 (�i�K)
        				//��ĳ���n�ۤv�]exp. �Ѩt�ΨM�w
        				//�H�K���Pwiz�g��mob �|�X�{�Ӥj���t��
       
        set("combat_exp",2000);		//�Լ�(���bmob level��100�����k���y)
//        set("env/wimpy", 20);		//�k�]wimpy (20%)
        set("evil",20);			//���c�� 20 (�������c, �t���})

   set("attitude", "peaceful");   //�ũM�� NPC�C
   set("talk_reply","�h�R�I�m���a..����..");
	//�`�N. �n�]�w�f�~�M��
   set("sell_list",([	
           TICKET    : 20, //��ܨC�R�@�i�m���|��20�I�ɵ��I��
       ]) );
  set("no_kill",1);
  set("no_fight",1);
  set("chat_chance", 3 );  //�ʧ@���v
  set("chat_msg", ({       //�ʧ@���e
"�ª��ʯ�������: �j����, �n���n�R�I�m��<buy>��? �ڽ檺�m��<list>�����v�ܰ���!\n",
(:command("grin"):),
(:command("think"):),
}) );

//===========================���D�^��==================================
set("inquiry/name", @LONG
  [1;36m �ڥs���ª���.. �Цh����!![m
LONG );

        setup();

      add_money("coin", 120);		//�a����

}

void init()
{
::init();
add_action("do_list","list");
add_action("do_buy","buy");
add_action("do_reward","reward");
}


