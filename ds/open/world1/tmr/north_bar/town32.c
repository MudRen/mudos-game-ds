// Room: /open/world1/tmr/north_bar/town32.c

inherit ROOM;

void create()
{
	set("short", "北蠻村－街道");
	set("long", @LONG
來到這裡，你發現這附近似乎是住宅區，旁邊都是一些民房
，但是附近卻有間相當老舊的房屋，特別引人注意。
LONG
	);
	set("objects", ([ ]));
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"town33",
  "west" : __DIR__"town11",
]));
	set("current_light", 1);
	set("no_clean_up", 0);
	set("outdoors", "land");

	setup();
	replace_program(ROOM);
}
