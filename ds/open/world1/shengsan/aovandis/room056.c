// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"����"NOR);
	set("long", @LONG
�o���\�]�ۤ@�륫���һݪ��a��A�èS������S�O���a��C
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
            "east" : __DIR__"room084",
            ]));

	set("no_clean_up", 0);

	set("light", 1);

	setup();
	replace_program(ROOM);
}