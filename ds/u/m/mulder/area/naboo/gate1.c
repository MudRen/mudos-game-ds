// Room: /u/s/sonicct/area/gate1.c

inherit ROOM;

void create()
{
	set("short", "Naboo城門");
	set("long", @LONG
這裡是Naboo南邊的城門，通過了就可以乘太空船到其他地方
去。你看到有些士兵在這裡管制人群，免得人們發生意外。北邊
就是通往Naboo市中心。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"road1",
]));
		 set("objects",([
  __DIR__"npc/guard":1,
__DIR__"npc/guard1":2,
 ]));

	set("outdoors","land");
	set("no_clean_up", 0);

	setup();
	
}
int valid_leave(object me, string dir)
{
        if( dir=="east" && !userp(me) )
                return notify_fail("那裡只有玩家才能進去。\n");
        return ::valid_leave(me, dir);
}