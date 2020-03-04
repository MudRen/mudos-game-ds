// Room: /u/a/acme/area/room1.c

inherit ROOM;

void create()
{
	set("short", "皂班");
	set("long", @LONG
這裡是執勤的官兵在此駐紮看管的地方，也是執勤官兵交接的地
方，日夜都有人看守，免得讓宵小闖入。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"passage1",
]));
set("objects",([
    __DIR__"npc/guard2":2,
]));
	set("no_clean_up", 0);
        set("light",1);

	setup();
	replace_program(ROOM);
}
