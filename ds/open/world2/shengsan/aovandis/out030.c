// 奧凡迪斯郊區
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "樹林");
	set("long", @LONG
一棵一棵的大樹就在你的眼前，數量不會很多，大多數是針葉的樹種
，也有幾株小樹在大樹的下面，空氣變得新鮮了不少。你可以很清楚的看
到有人走過的痕跡，可能是住在這附近的居民所留下的吧？
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
	    "south": __DIR__"out038",
	    "north": __DIR__"out021",
            ]));

	set("outdoors","land");	// 平原
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}