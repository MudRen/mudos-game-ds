// Npc: /u/d/dragonku/npc/2.c
#include <ansi.h>
inherit NPC;

void create()
{
	set_name(HIY"���"NOR, ({"Ugelan Lord","lord"}) );
	set("long", "�L�O�վB����������A�]�O�վB�������̰���ɤH�C\n");
	set("title",HIW"�i�վB���Ұ�j"NOR);
 set("race", "�H��");
	set("age", 50);
	set("level", 40);

	setup();
carry_object(__DIR__"wq/goldsword")->wield();
}
