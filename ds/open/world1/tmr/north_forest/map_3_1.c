// Room: /u/l/lestia/area/map_3_1.c

inherit ROOM;

void create()
{
	set("short", "魔力屏障");
	set("long", @LONG
這裡迷漫著一股充滿白色的霧氣，從你的四周緩緩升起直奔遠處而去，
霧氣中透露出絲絲寒氣，黑暗陰冷的氣息讓你不禁渾身發抖，你望著前
方一片茫然，當你回過神時，你發現你已經深深的陷在這片森林之中了。
LONG
	);
	set("no_clean_up", 0);
	set("world", "undefine");
	set("current_light", 3);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"map_4_1",
  "north" : __DIR__"map_2_1",
]));

	setup();
	replace_program(ROOM);
}
