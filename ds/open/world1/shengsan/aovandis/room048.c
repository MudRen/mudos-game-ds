// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"���D"NOR);
	set("long", @LONG
�A���b�@�����b�����D�W�C���_�O�Ův�u�|�A���n�i�H��F���v�u�|
�C���F�����O�Ӫ���C
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"room049",
	    "west" : __DIR__"room047",
	    "south": __DIR__"room084",
	    "north": __DIR__"room085",
            ]));

	set("no_clean_up", 0);

	set("light", 1);

	setup();
	replace_program(ROOM);
}