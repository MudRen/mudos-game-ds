// Room: /u/b/bennyng/area/room40.c

inherit ROOM;

void create()
{
	set("short", "山羊宮");
	set("long", @LONG
這裡便是山羊宮，為什麼仍不見山羊座黃金聖鬥士？？是不是害怕你
們而找地方躲起來？？嘿嘿！！嘿嘿！！
LONG
	);
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room41",
  "north" : __DIR__"room39",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
