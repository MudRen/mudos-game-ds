// Room: /u/b/bennyng/area/room38.c

inherit ROOM;

void create()
{
	set("short", "山羊宮");
	set("long", @LONG
這裡便是山羊宮的出口，為什麼仍不見山羊座黃金聖鬥士？？是不是
害怕你們而找地方躲起來？？嘿嘿！！嘿嘿！！
LONG
	);
        set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"room43",
  "south" : __DIR__"room39",
  "east" : __DIR__"room37",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
