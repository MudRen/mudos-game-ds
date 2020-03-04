// Room: /u/s/suez/fall.c

inherit ROOM;

void create()
{
	set("short", "雲煙瀑布");
	set("long", @LONG

瀑布附近清涼的水霧令你覺得很舒服，在你身後的是
一間綠意盎然的竹屋，聽說穿過瀑布就會進入桃花源
一般的世界。
LONG
	);
	set("current_light", 2);
	set("exits", ([ /* sizeof() == 4 */
  "area1" : __DIR__"area/hotel_hall",
  "area2" : __DIR__"grave/kiosk",
  "area3" : __DIR__"port/port_24",
  "in" : __DIR__"workroom",
]));
	set("no_clean_up", 0);
	set("world", "world1");

	setup();
	replace_program(ROOM);
}
