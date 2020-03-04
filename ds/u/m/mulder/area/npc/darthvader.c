// Npc: /u/m/mulder/npc/1.c

#include <ansi.h>
inherit NPC;

void create()
{
	set_name( HIR "Darth Vader" NOR , ({"darth vader", "vader","darth" }) );
	set("long", " �L�Y�W�a�ۤ@���Y���A��ӥL�N�O"HIR"Darth Vader"NOR"�I\n");
	set("race", "�H��");
	set("gender", "�k��");
	set("age", 35);
	set("attitude", "aggressive");
	set("level", 50);
	set("evil", 999);
	set("combat_exp",20000);
	set_skill("sword", 100);
	set("title",HIB"�yDark Side�z"NOR);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("unarmed",100);
	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
	(:command("wield sword"):),
	}) );
	
	
	setup();
	carry_object(__DIR__"wp/lightsaber2");
	
}

