// Room: /u/b/bennyng/area/room8.c

inherit ROOM;

void create()
{
	set("short", "碎石路");
	set("long", @LONG
這裡是雙魚宮和教皇大殿之交界處，兩旁都種滿玫瑰，這裡可以看到
雅典的全景．
LONG
	);
        set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"room9",
  "northup" : __DIR__"room7",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
