// Room: /u/a/acme/area2/t37.c

inherit ROOM;

void create()
{
	set("short", "幽冥地窖[地下四層]");
	set("long", @LONG
你正走在黑暗無比的地道中，地道窄又長，好像走不完似的，越
往裡頭心裡越害怕，這股黑暗的氣流令你窒息。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"t38",
  "south" : __DIR__"t36",
]));
set("objects",([
   __DIR__"npc/to" : 1,
]));
	set("no_clean_up", 0);

	setup();
}
int valid_leave(object me, string dir)
{
    if( userp(me) && objectp( present("__GUARD__", this_object()) ))
            return notify_fail("這裡太過擁擠了，你走不過去。\n");
    return ::valid_leave(me, dir);
}

