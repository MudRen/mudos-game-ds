// Room: /open/world3/alickyuen/area/dst17.c

inherit ROOM;

void create()
{
	set("short", "[1;36mCircle tunnel＠Saint[2;37;0m");
	set("long", @LONG
你正走著一條連接saint 城和礦區的行人通道，往南直走可通往舊世
界採礦區，往北不遠處就是城門了，盡是擁擠的人潮。這條通道呈處在一
圓管形的防護薄膠中，完全地隔離了礦區中汙穢難聞的空氣。
LONG
	);
	set("world", "future");
	set("outdoors", "land");
	set("exits", ([ /* sizeof() == 2 */
  "south" : "/open/world3/tmr/basic/district1",
  "enter" : __DIR__"gate1.c",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
