// Npc: /u/d/dragonku/npc/2.c
#include <ansi.h>
inherit NPC;

void create()
{
	set_name(HIW"�@�ö�"NOR"����", ({"bigguard"}) );
	set("long", "�����@�ö��������L�ݰ_�ӬO�@��ܱj���H�C\n");
	set("race", "�H��");
   set("age", 35);
    set("level", 20);

	setup();
carry_object(__DIR__"wq/guardsword")->wield();
}
