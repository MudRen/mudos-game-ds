// Room: /open/world1/dragoncity/southroad2.c

inherit ROOM;

void create()
{
	set("short", "南內大街");
	set("long", @LONG
你正走在一條用青石鋪就的大道。向東就是丁字街口，
可通往玄武門，西面也是一個大街口，你好像看到一條大街
通向南面。北面是一堵上蓋紅色琉璃瓦的高牆，裡面是少帥
軍統帥寇仲的府邸。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"south_din",
  "west" : __DIR__"southroad2w",
]));
	set("outdoors", "land");
	set("no_clean_up", 0);
	set("current_light", 3);

	setup();
	replace_program(ROOM);
}
