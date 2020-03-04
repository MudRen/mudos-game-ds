// Room: /u/a/acme/area/hills3.c

inherit ROOM;

void create()
{
	set("short", "黃沙陵");
	set("long", @LONG
這裡就是黃沙陵了，在你腳底盡是黃顏色的細沙，此處竟是寸草不生
甚是古怪，但心中的疑問卻已被恐懼所取代，只見沙地中有個不知名的東
西在蠕動著。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"hills",
  "south" : __DIR__"portal",
  "east" : __DIR__"hills2",
]));
	set("no_clean_up", 0);
    set("outdoors","land");

	setup();
	replace_program(ROOM);
}
