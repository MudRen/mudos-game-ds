// Npc: /u/m/mulder/npc/1.c

#include <ansi.h>
inherit NPC;

void create()
{
	set_name( HIR "黑武士" NOR , ({"darth vader", "vader","darth" }) );
	set("long", " 他頭上帶著一個頭盔，原來他就是黑武士！\n");
	set("race", "人類");
	set("gender", "男性");
	set("age", 35);
	set("level", 50);
	set("evil", 999);
	set("combat_exp",20000);
	set_skill("sword", 100);
	set("title","『Dark Side』");
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("unarmed",100);
	
	
	setup();
	carry_object(__DIR__"wp/lightsaber2")->wield();
	
}

