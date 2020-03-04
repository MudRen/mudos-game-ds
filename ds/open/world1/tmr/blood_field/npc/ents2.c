#include <ansi.h>
inherit NPC;
inherit __DIR__"fight_ai.c";

void create()
{
        set_name(HIG "野樹人" NOR, ({"wild-tree ents", "ents","_BLOOD_FIELD_NPC_" }) );
        set("long",@long
樹人是一種像樹木般的生物，他們越來越像樹木。顏色等。他們也有一些
致命的弱點，火及一些能擊倒樹人的巨大物體。一名樹人通常守護著特徵
物種相似的樹木，樹人本身也很像山梨樹（高、苗條）。
long
);
        set("title","血腥荒野");
		set("race","evil");
		set("level", 50+random(10));
        set("age", 320);
        set("chat_chance", 8);
        set("chat_msg", ({
               (: command("think") :),
               (: command("hmm") :),
        	    (: random_move :),
        }) );
		/* 戰鬥動作 */
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



