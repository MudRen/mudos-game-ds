// Room: /u/s/sonicct/area/road1.c

inherit ROOM;

void create()
{
	set("short", "Naboo城街道");
	set("long", @LONG
在這裡你可以看到北面的大街十分繁榮，還聽到熱鬧的人群
聲。南面可以乘坐太空船到其他地方去。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"road2",
  "south" : __DIR__"gate1",
]));
	set("outdoors","road");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
