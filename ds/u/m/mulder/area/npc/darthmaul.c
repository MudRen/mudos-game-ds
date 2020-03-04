// Npc: /u/m/mulder/npc/1.c

#include <ansi.h>
inherit NPC;

void create()
{
	set_name( HIR "Darth Maul" NOR , ({"darth maul", "maul","darth" }) );
	set("long", " 他是一個大反派！\n");
	set("race", "人類");
	set("gender", "男性");
	set("age", 35);
	set("attitude", "aggressive");
	set("level", 50);
	set("evil", 999);
	set("combat_exp",2500);
	set_skill("sword", 100);
	set_skill("fork",100);
	set("title",HIB"『Dark Side』"NOR);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("unarmed",100);
	set("chat_chance_combat", 160);
	set("chat_msg_combat", ({
	(:command("wield pike"):),
	(:command("wield sword"):),
	}) );

	
	
	setup();
	carry_object(__DIR__"wp/lightsaber3");
	
}

