// Room: /u/t/tmr/area/lake-road2.c

inherit ROOM;

void create()
{
	set("short", "白色石階");
	set("long", @LONG
你正走在一條蜿蜒崎嶇的石階，往東南邊是一片翠綠的竹林，南方不
遠處有座涼亭，是提供給過往旅客小憩。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "southeast" : __DIR__"lake-road3",
  "south" : __DIR__"arbour",
  "westdown" : __DIR__"lake-road1",
]));
	set("outdoors","land");
	set("no_clean_up", 0);
	set("no_map",1);
	setup();
	replace_program(ROOM);
}
