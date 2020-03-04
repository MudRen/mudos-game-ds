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
	set("level", 120);
	set("max_hp", 100000);
	set("max_mp", 100000);
	set("attitude", "killer");
	set("evil", 999);
	set("combat_exp",20000);
	set_skill("sword", 200);
	set_skill("dodge", 200);
	set_skill("parry", 200);
	set_skill("unarmed", 200);
	set("title", "『殺人不眨眼』");
	set_spell("mindkill",100);      
            set("chat_chance_combat", 100);
            set("chat_msg_combat", ({
            (:command("servenkill "):),
            }) );
	
	setup();
	carry_object("/u/t/tmr/test/sword.c")->wield();
	
}

