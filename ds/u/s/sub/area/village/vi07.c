// Room: /u/s/sub/area/village/vi07.c

inherit ROOM;

void create()
{
	set("short", "碎石小路");
	set("long", @LONG
這是一條貫穿小村莊的南北向道路。由於接近村莊的出口了，所以這
裡的人也少了很多。東邊有一間銀行，往北邊走就可以離開村莊了。
LONG
	);
	set("world", "undefine");
	set("no_clean_up", 0);
	set("outdoors", "land");
	set("current_light", 2);
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"bank",
  "north" : __DIR__"vi08",
  "south" : __DIR__"vi06",
]));

	setup();
	replace_program(ROOM);
}
