// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"�������j��"NOR);
	set("long", @LONG
�@���u���u�����v�i�H�����A�]�\�A�ݭn��h���u���C
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
	    "south": __DIR__"room045",
            ]));

	set("no_clean_up", 0);

	set("light", 1);

	setup();
	replace_program(ROOM);
}