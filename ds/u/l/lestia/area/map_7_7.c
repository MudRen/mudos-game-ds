// Room: /u/l/lestia/area/map_7_7.c

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
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"map_7_6",
  "east" : __DIR__"sn1",
  "south" : __DIR__"map_8_7",
  "north" : __DIR__"map_6_7",
]));
	set("current_light", 3);

	setup();
}
int valid_leave(object me, string dir)
{
       object obj;
me = this_player();
 if( dir=="west")      //&& !wizardp(me))
        {
if( me->query("level") < 10) return notify_fail("你用力的往魔力屏障衝過去，但是因為力量不足而被彈了回來。\n");
}
        return ::valid_leave(me, dir);
}
