// �ӤH�d��(1) 
// by Luky 19993.20
#include <ansi.h>
inherit NPC;
inherit BANKMAN;
inherit SSERVER;
void call_help();
void create()
{
//=========================�򥻳]�w==========================

        set_name( "���洵", ({ "rancus",}));
        
        //tmr, long�A�ۤv���a. �t�Ieq..
        set("long", "�@�Ө����A���u�@�H��, �����ө����ȤH�C\n\n"
        	    +"  �d�߱b��Х� <balance> \n"
        	    +"  �ݦs���Х� <deposit �򥻪��B> \n"
        	    +"  �n�����Х� <withdraw �򥻪��B> \n\n"
        );
        
        set("level",3);
        set("title","[1;32m�U��[m");
        set("gender", "�k��");
        set("race", "�H��");
        set("age", 45);

        set("combat_exp",300);		//�Լ�(���bmob level��100�����k���y)
        
        set("evil",-20);			//���c�� 20 (�������c, �t���})

	set_skill("unarmed",20);		// �ޯ�(�۩w)
	set_skill("parry",10);		//
	set_skill("dodge",10);		//

   set("attitude", "peaceful");   //�ũM�� NPC�C
   set("talk_reply","�Q�s��(deposit)��? �`�`�s�ڥi�H�קK�򥢳�!!");

  set("chat_chance", 3 );  //�ʧ@���v
  set("chat_msg", ({       //�ʧ@���e
(: command("smile") :),
}) );
	set("chat_chance_combat", 10);
	set("chat_msg_combat", ({
(: call_out("call_help",0) :),
(: call_out("call_help",0) :),
(: call_out("call_help",0) :),
 HIR"���洵�j�s : �u�ϩR����T���H�m�T���T�v\n"NOR,
     }) );
//===========================���D�^��==================================
set("inquiry/name", @LONG
  [1;36m �ڥs�����洵.. �Цh����!![m
LONG );

        setup();

		//�a����(coin�j�N,dollar�{�N,���ӨS��)
	add_money("silver", 25);
}

void init()
{
 add_action("do_deposit","deposit");
 add_action("do_withdraw","withdraw");
}

void call_help()
{
	object roken,target;
	target = offensive_target(this_object());
	if(!target) return ;

	roken=present("roken", environment(this_object()));
	if(!roken)
	{
		message_vision("�����j�s: �֨ӤH��~~ �ϩR��!! \n",target);
		return ;
	}
	if(roken->is_fighting(target))
	{
		message_vision("���֬ݰ_�ӫܥͮ𪺼ˤl!!\n",target);
		return ;
	}
	else
	{
	 roken->kill_ob(target);
	 say(HIW"���֫�|�D�G���ѤƤ餧�U�x�����H�m�T�I�ڭn���Ѧ�D�I�I\n"NOR);
	 message_vision("���֤j�ܤ@�n, �}�l��$N�o�ʧ���!!\n",target);
	 return ;
	}
}

