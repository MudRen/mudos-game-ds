// Npc: /u/m/mulder/npc/1.c

#include <ansi.h>
inherit NPC;

void create()
{
	set_name( HIR "蒙面人" NOR , ({"super mask", "mask" }) );
	set("long", " 他是來自不同時間的殺手，你可能成為他另一個目標！\n");
	set("race", "人類");
	set("gender", "男性");
	set("age", 30);
	set("level", 20);
	set("max_hp", 500);
	set("max_mp", 100);
	set("attitude", "aggressive");
	set("str", 30);
	set("evil", 99);
	set("combat_exp",2000);
	set_skill("fork", 20);
	set_skill("dodge", 30);
	set_skill("parry", 30);
	set_skill("unarmed", 60);
	set("title", "『殺人如麻』"); 
            set("chat_msg_combat", ({
            (:command("hehe"):),
            }) );

 
	
	setup();
	carry_object("/u/s/sopher/area/npc/npcwp/light_spear.c")->wield();
	carry_object("/u/m/mulder/area/npc/eq/armor.c")->wear();
	
}

