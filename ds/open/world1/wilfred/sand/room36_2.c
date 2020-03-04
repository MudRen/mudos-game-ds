// Room: /open/world1/wilfred/sand/room36_2.c

inherit ROOM;

void create()
{
	set("short", "黃沙嶺");
	set("long", @LONG
經年累月的風沙，堆出了這塊黃沙丘陵地，丘陵上寸草不生，鳥
獸難見，當地人稱之為『黃沙嶺』，此丘陵為連接舊磐龍城與黃沙道
之要道，惡名昭彰的『黃沙幫』的山寨便在這附近。
LONG
	);
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/npc20_0" : 3,
  __DIR__"npc/npc20_1" : 3,
]));
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"room36_2e",
  "west" : __DIR__"room36_2w",
  "south" : __DIR__"room36_1",
  "north" : __DIR__"room36_3.c",
]));
	set("outdoors", "land");
	set("current_light", 2);
	set("no_recall", 1);

	setup();
	replace_program(ROOM);
}
