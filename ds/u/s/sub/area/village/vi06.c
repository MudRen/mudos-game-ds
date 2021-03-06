// Room: /u/s/sub/area/village/vi06.c

inherit ROOM;

void create()
{
	set("short", "碎石小路");
	set("long", @LONG
這是一條貫穿小村莊的南北向道路。在人來人往的路上，可以看到有
的村民眉頭深鎖，看來每個人都有自己的煩惱。路邊有幾棵松樹，在夏天
的時候樹下可是擠滿了想避暑的人。西邊是一間民房，東邊是一間商店。
LONG
	);
	set("world", "undefine");
	set("no_clean_up", 0);
	set("outdoors", "land");
	set("current_light", 2);
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"store",
  "north" : __DIR__"vi07",
  "west" : __DIR__"house02",
  "south" : __DIR__"vi05",
]));

	setup();
	replace_program(ROOM);
}
