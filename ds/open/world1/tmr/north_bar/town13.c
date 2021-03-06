// Room: /open/world1/tmr/north_bar/town13.c

inherit ROOM;

void create()
{
	set("short", "北蠻村－街道");
	set("long", @LONG
這裡右邊就是村長家的門口，聽說村長為人很善良，但是最
近卻好像有什麼煩惱的事情。而往左走是村裡的唯一的一口
大井。
LONG
	);
	set("objects", ([ ]));
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"town11",
  "east" : __DIR__"town20",
  "north" : __DIR__"town15",
  "west" : __DIR__"town6",
]));
	set("current_light", 1);
	set("no_clean_up", 0);
	set("outdoors", "land");

	setup();
	replace_program(ROOM);
}
