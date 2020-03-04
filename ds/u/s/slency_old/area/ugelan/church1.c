// Room: /u/s/slency/area/ugelan/church1.c

inherit ROOM;

void create()
{
	set("short", "青石街道");
	set("long", @LONG
這裡是一條由青石鋪設而成的街道，路旁種滿了各種奇花異草，彷
彿進入了一個生態花園，同時路上也設置了不少座椅，供路人休息之用
，往北是一條通往護城河畔的小徑，往西通往城市中心，往東則是一座
極大長形的廣場。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"church5",
  "west" : __DIR__"road15",
  "east" : __DIR__"church2",
]));
	set("no_clean_up", 0);
	set("outdoors", "land");

	setup();
	replace_program(ROOM);
}
