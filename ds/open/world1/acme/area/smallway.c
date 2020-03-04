// Room: /open/world1/acme/area/smallway.c
#include <path.h>
inherit ROOM;

void create()
{
	set("short", "青磚長道");
	set("long", @LONG
你正站在漫漫的長道上，長道是由青磚所構成，想必是官府所造的道
路，四周景物蕭條，一片寂靜，微風一吹，二旁高聳的樹，落葉紛飛。
LONG
	);
	set("world", "past");
	set("outdoors", "land");
	set("exits", ([ /* sizeof() == 1 */
  "southeast" : __DIR__"pathway1",
  "enter" : ACME_PAST+"cominging/bigwall.c",
]));
	set("no_clean_up", 0);
     set("outdoors","land");

	setup();
}
int valid_leave(object me, string dir)
{
       if( dir=="enter" && !userp(me) )

                return notify_fail("那裡只有玩家才能進去。\n");
        return ::valid_leave(me, dir);
}
