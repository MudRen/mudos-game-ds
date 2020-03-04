// Room: /u/a/acme/area2/t29.c

inherit ROOM;

void create()
{
	set("short", "幽冥地窖[地下三層]");
	set("long", @LONG
你再前行數丈，地道突然收窄，必須弓身而行，越向前行，彎腰
越低。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"t28",
  "south" : __DIR__"t30",
]));
         set("objects",([
            __DIR__"npc/tan" : 1,
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

