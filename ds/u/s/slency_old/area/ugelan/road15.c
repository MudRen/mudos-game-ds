// Room: /u/s/slency/area/ugelan/road15.c

inherit ROOM;

void create()
{
	set("short", "青石街道");
	set("long", @LONG
這裡是一條青石鋪設而成的街道，路上行人熙來攘往，和其他街道
並沒有多大差別，由此往西是幽遮蘭大道，往東是通往城東郊區的一條
路。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"road16",
  "west" : __DIR__"road4",
  "east" : __DIR__"church1",
]));
	set("no_clean_up", 0);
	set("outdoors", "land");

	setup();
	replace_program(ROOM);
}
