// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"���D"NOR);
	set("long", @LONG
�A�b�@�ӧN�M�����D�W�C
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"room039",
	    "south": __DIR__"room041",
            ]));

	set("no_clean_up", 0);

	set("light", 1);

	setup();
	replace_program(ROOM);
}