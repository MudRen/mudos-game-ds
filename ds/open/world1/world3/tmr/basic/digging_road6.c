// Room: /open/world3/tmr/basic/digging_road6.c

inherit ROOM;

void create()
{
	set("short", "廢棄鐵路");
	set("long", @LONG
你正走著一條廢棄的鐵路上，你不時可看到不少礦工擔著挖掘的煤、
鐵走回礦區，也可看到背負著鐵鋤、十字鍬等工具順著鐵路往西走向礦區
。已廢棄的鐵路旁長滿了雜草，為這帶來了一絲綠意。
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
  "雜草" : "數株綠茵茵的不知何名的雜草。
",
]));
	set("world", "future");
	set("outdoors", "desert");
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"digging_road7",
  "east" : __DIR__"digging_road5",
  "northwest" : "/open/world3/tmr/hunter_forest/forest1",
  "north" : "/open/world3/super-light-area/1.c",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
