// Npc: /u/m/mulder/npc/1.c

#include <ansi.h>
inherit NPC;

void create()
{
	set_name( HIR "�ªZ�h" NOR , ({"darth vader", "vader","darth" }) );
	set("long", " �L�Y�W�a�ۤ@���Y���A��ӥL�N�O�ªZ�h�I\n");
	set("race", "�H��");
	set("gender", "�k��");
	set("age", 35);
	set("level", 50);
	set("evil", 999);
	set("combat_exp",20000);
	set_skill("sword", 100);
	set("title","�yDark Side�z");
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("unarmed",100);
	
	
	setup();
	carry_object(__DIR__"wp/lightsaber2")->wield();
	
}

