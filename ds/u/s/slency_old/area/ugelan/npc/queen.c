// Npc: /u/s/slency/area/ugelan/npc/queen.c
#include <ansi.h>
inherit NPC;

void create()
{
	set_name("�ӦZ", ({"Ugelan Queen","queen"}) );
	set("long", "�L�O�վB���������Z�A�O������d�l, �ݰ_�Ӻݲ��Ŷ�, �ܨ��H�����߷R�C\n");
	set("title",HIW"�i�վB���Ұ�j"NOR);
 set("race", "�H��");
	set("age", 40);
	set("level", 20);

	setup();
carry_object(__DIR__"wq/silversword")->wield();
}
