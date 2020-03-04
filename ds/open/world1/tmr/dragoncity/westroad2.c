// Room: /open/world1/dragoncity/westroad2.c

inherit ROOM;

void create()
{
	set("short", "西內大街");
	set("long", @LONG
這是一條用青石鋪就的大街，東面是一堵上蓋紅色琉璃
瓦的高牆，裡面是少帥軍統帥寇仲的府邸。南面是用青石鋪
的大街道。北面是一個大的十字街道，只見人來人往，非常
熱鬧。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"southroad2w",
  "north" : __DIR__"west_din",
]));
	set("outdoors", "land");
	set("no_clean_up", 0);
	set("current_light", 5);

	setup();
	replace_program(ROOM);
}
