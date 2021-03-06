// Room: /open/world1/tmr/dragoncity/northroad1.c

inherit ROOM;

void create()
{
	set("short", "北內大街");
	set("long", @LONG
這是一條用青石鋪就的大道。向西就是丁字街口，只見
北面不時有馬車飛奔而出，東面也是一個大街口，你好像看
到一條大街通向南面。南面是一堵上蓋紅色琉璃瓦的高牆，
裡面是少帥軍統帥寇仲的府邸。
LONG
	);
	set("current_light", 4);
	set("outdoors", "land");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"bank",
  "west" : __DIR__"north_din",
  "east" : __DIR__"northroad1e",
]));

	setup();
	replace_program(ROOM);
}
