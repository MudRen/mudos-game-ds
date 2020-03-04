// Room: /u/s/sonicct/area/gate2.c

inherit ROOM;

void create()
{
	set("short", "Naboo城門");
	set("long", @LONG
你前面是一道巨大的城門，有兩個守衛在門前負責開門。
你看見一輛輛名貴的車經這道城門進入皇宮，而你只可在道路兩
旁觀看。這裡的南方是通去市中心。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"road6",
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
