// Room: /open/world1/wilfred/sand/room8.c

inherit ROOM;

void create()
{
	set("short", "分岐小路");
	set("long", @LONG
從此處去，西邊的丘陵為黃沙嶺，往南不遠處則是黃沙道上唯
一的小鎮－黃沙鎮，要是你旅行累了，不妨可以去鎮上歇歇。而此
處往西方走，則是赫赫有名的磐龍城，駐有天下第一勁旅-少帥軍。
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/npc4" : 4,
]));
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"room9",
  "east" : __DIR__"room4",
  "westup" : __DIR__"room34",
]));
	set("outdoors", "land");
	set("no_clean_up", 0);
	set("current_light", 1);

	setup();
	replace_program(ROOM);
}
