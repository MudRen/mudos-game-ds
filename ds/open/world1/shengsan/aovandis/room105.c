// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"���]�G��"NOR);
	set("long", @LONG
�����q����z�g�i�ӡA�ӫG�F��өж��C
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
	    "south": __DIR__"room104",
            ]));

	set("no_clean_up", 0);

	set("light", 1);

	setup();
	replace_program(ROOM);
}

