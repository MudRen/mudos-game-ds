// Room: /u/b/bennyng/area/room10.c

inherit ROOM;

void create()
{
	set("short", "雙魚宮");
	set("long", @LONG
四周散佈了玫瑰花的幽香．令你如入仙境般陶醉．要通過雙魚宮，就
必先解決眼前的雙魚宮守護者－－雙魚座黃金聖鬥士．往北就是通往教皇
大殿的唯一通道．
LONG
	);
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"room11",
  "west" : __DIR__"room12",
  "south" : __DIR__"room13",
  "north" : __DIR__"room9",
]));
        set("objects", ([
  __DIR__"npc/Pisces.c":1,
]));
        set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
