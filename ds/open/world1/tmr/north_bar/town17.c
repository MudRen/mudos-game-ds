// Room: /open/world1/tmr/north_bar/town17.c

inherit ROOM;

void create()
{
	set("short", "北蠻村－防具店");
	set("long", @LONG
來到這裡，兩旁的牆壁上掛著許多防具，金光閃閃，前面就
是櫃檯，老闆正站在那裡，如果你缺少防具的話，就買幾件穿穿
吧，不過只想要觀賞也是可以的。
LONG
	);
	set("objects", ([ ]));
	set("exits", ([ /* sizeof() == 1 */
  "southeast" : __DIR__"town16",
]));
	set("current_light", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
