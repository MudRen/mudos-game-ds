// Room: /open/world1/tmr/dragoncity/northroad2w.c

inherit ROOM;

void create()
{
	set("short", "大街口");
	set("long", @LONG
這兒是南城內的十字街口，非常熱鬧，小商小販們在向
行人吆喝著，兜售他們的商品。雖然磐龍飽受虎人軍侵擾，
但這兒看不出人們有絲毫的緊張，好像他們已司空見慣、習
以為常了，南面和西面是胡同，許多磐龍城的老百姓住在裡
面，東面和北面是青石鋪就的大街。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"westroad2",
  "east" : __DIR__"southroad2",
]));
	set("current_light", 3);
	set("no_clean_up", 0);
	set("outdoors", "land");

	setup();
	replace_program(ROOM);
}
