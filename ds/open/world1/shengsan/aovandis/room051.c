// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"�ǳN���D"NOR);
	set("long", @LONG
�A���b�@�����ǳN�𮧪����D�W�C
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
            "east" : __DIR__"room045",
	    "west" : __DIR__"room052",
            ]));

	set("no_clean_up", 0);

	set("light", 1);

	setup();
	replace_program(ROOM);
}