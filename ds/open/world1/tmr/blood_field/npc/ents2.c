#include <ansi.h>
inherit NPC;
inherit __DIR__"fight_ai.c";

void create()
{
        set_name(HIG "����H" NOR, ({"wild-tree ents", "ents","_BLOOD_FIELD_NPC_" }) );
        set("long",@long
��H�O�@�ع����몺�ͪ��A�L�̶V�ӶV�����C�C�ⵥ�C�L�̤]���@��
�P�R���z�I�A���Τ@�ǯ����˾�H�����j����C�@�W��H�q�`�u�@�ۯS�x
���جۦ������A��H�����]�ܹ��s����]���B�]���^�C
long
);
        set("title","��{�");
		set("race","evil");
		set("level", 50+random(10));
        set("age", 320);
        set("chat_chance", 8);
        set("chat_msg", ({
               (: command("think") :),
               (: command("hmm") :),
        	    (: random_move :),
        }) );
		/* �԰��ʧ@ */
	   	 set("chat_chance_combat", 50);
	   	 set("chat_msg_combat", ({
	      	(: do_fight_help :),        
			(: do_fight_heal :),        
	   	 }) );
	   	  
        set("attitude", "aggressive");
        set("addition/bar", 10);
       set("addition/bio", 2);
        set("addition/wit", 10);
        set("addition_armor", 200);
        set("addition_damage", 200);
        set("addition_shield", 300);
        setup();
        set_temp("apply/hit", 200);
        set_living_name("_BLOOD_FIELD_NPC_");
      	if(random(3))
      		carry_object(__DIR__"obj/stone");
}



