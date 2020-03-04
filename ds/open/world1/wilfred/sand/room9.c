// Room: /open/world1/wilfred/sand/room9.c

inherit ROOM;

void create()
{
	set("short", "黃沙鎮口");
	set("long", @LONG
這是一個人煙稀少的小鎮，居民可能不超過二十人，此鎮座落於黃
沙道及黃沙嶺之間，鎮上有間偶爾可看見旅人或商隊在此打尖。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"room10",
  "north" : __DIR__"room8",
]));
	set("outdoors", "land");
	set("current_light", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
