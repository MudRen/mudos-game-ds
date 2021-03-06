// Room: /u/a/acme/area2/t39.c

inherit DOOR;
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
  "north" : __DIR__"t38",
  "northeast" : __DIR__"t40",
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

