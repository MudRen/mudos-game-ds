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

        set_name( "�H�j�I", ({ "harn-tar-fu","harn","fu","boss"}));
        
        //tmr, long�A�ۤv���a. �t�Ieq..
        set("long", "�@�Ө�����R�A�����L�D���~�H, �L�]�O�o���������D�H�C\n\n"
        	    +"  �d�߱b��Х� <balance> \n"
                +"  �n�s���Х� <deposit �򥻪��B> \n"
        	    +"  �n�����Х� <withdraw �򥻪��B> \n\n"
        );
        
        set("level",17);
        set("title","[1;32m���~[m");
        set("gender", "�k��");
        set("race", "�H��");
        set("age", 45);

        set("combat_exp",1700);		//�Լ�(���bmob level��100�����k���y)
        
        set("evil",20);			//���c�� 20 (�������c, �t���})

	set_skill("blade",40);		// �ޯ�(�۩w)
	set_skill("parry",40);		//
	set_skill("dodge",40);		//

   set("attitude", "peaceful");   //�ũM�� NPC�C
   set("talk_reply","�Q�s��(deposit)��? �`�`�s�ڥi�H�קK�򥢳�!!");

  set("chat_chance", 3 );  //�ʧ@���v
  set("chat_msg", ({       //�ʧ@���e
(: command("stare") :),
}) );
	set("chat_chance_combat", 10);
	set("chat_msg_combat", ({
(: call_out("call_help",0) :),
(: call_out("call_help",0) :),
(: call_out("call_help",0) :),
 HIR"���~�j�s : �u�ϩR����T���H�m�T���T�v\n"NOR,
     }) );
//===========================���D�^��==================================
set("inquiry/name", @LONG
  [1;36m �ڥs���H�j�I.. �Цh����!![m
LONG );

        setup();

	add_money("gold", 1);		//�a����(coin�j�N,dollar�{�N,���ӨS��)
	add_money("silver", 36);
}

void init()
{
 add_action("do_deposit","deposit");
 add_action("do_withdraw","withdraw");
}

void call_help()
{
	object guard,target;
	target = offensive_target(this_object());
	if(!target) return ;

	guard=present("guard", environment(this_object()));
	if(!guard)
	{
		message_vision("���~�j�s: �֨ӤH��~~ �ϩR��!! \n",target);
		return ;
	}
	if(guard->is_fighting(target))
	{
		message_vision("�u�ìݰ_�ӫܥͮ𪺼ˤl!!\n",target);
		return ;
	}
	else
	{
	 guard->kill_ob(target);
	 message_vision("�u�äj�ܤ@�n, �}�l��$N�o�ʧ���!!\n",target);
	 return ;
	}
}

