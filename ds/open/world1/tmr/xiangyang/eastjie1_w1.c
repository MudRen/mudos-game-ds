// Room: /open/world1/tmr/xiangyang/eastjie1_w1.c

inherit ROOM;

void create()
{
	set("short", "東大街");
	set("long", @LONG
這是一條寬闊的青石板街道，向東西兩頭延伸。街上的人
潮非常擁擠，看的出來這一帶非常的熱鬧繁華，四週盡是一片
詳和的氣氛，百姓們都安居樂業。.
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"guangchang",
  "east" : __DIR__"eastjie1_w2",
]));
	set("coor", ([ /* sizeof() == 3 */
  "y" : -510,
  "x" : -490,
  "z" : 0,
]));
	set("current_light", 1);
	set("no_clean_up", 0);
	set("outdoors", "xiangyang");

	setup();
	replace_program(ROOM);
}
