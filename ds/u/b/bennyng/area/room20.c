// Room: /u/b/bennyng/area/room20.c

inherit ROOM;

void create()
{
	set("short", "寶瓶宮後園");
	set("long", @LONG
這裡一片死寂，四周白芒芒的，沒有任何生物，四處冰冷異常．往北
走你就可以繼續你的挑戰．
LONG
	);
    set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"room19",
  "east" : __DIR__"room21",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
