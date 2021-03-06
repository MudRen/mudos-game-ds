// Room: /future/area/digging_road4.c

inherit ROOM;

void create()
{
	set("short", "礦區道路");
	set("long", @LONG
你正走在礦區的一條道路，道路二旁盡是廢棄的鐵具、焦煤，顯得
陰穢骯髒，空氣也瀰漫著一股金屬的味道，往南不遠處有間酒館，往北
有條東西橫向的廢棄鐵路，可順著鐵路到達採礦區。
LONG
	);
	set("world", "future");
	set("no_clean_up", 0);
	set("outdoors", "desert");
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"digging_road5",
  "south" : __DIR__"digging_road1",
]));

	setup();
	replace_program(ROOM);
}
