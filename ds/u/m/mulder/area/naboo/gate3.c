// Room: /u/s/sonicct/area/gate3.c

inherit ROOM;

void create()
{
	set("short", "Naboo城門");
	set("long", @LONG
過了這道東城門，就能通往Naboo的大森林。而這裡有不少獵
戶出出入入，看起來這個森林有不少野獸可以捉到。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"road9",
 "east" :"/u/m/mulder/area/naboo/jungle/jungle",
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