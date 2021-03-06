// Room: /open/world1/tmr/goat_maze/stairway1.c

inherit ROOM;

void create()
{
	set("short", "羊男的迷宮 - 地底階梯");
	set("long", @LONG
你正在走一條石頭鋪成的地底階梯，楷梯不停地往下延伸，在黑暗
中宛如條灰色石龍。你踏在階梯上的聲響，一聲聲地迴蕩在整個空間，
平添幾分詭異的色彩。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"maze15",
  "down" : __DIR__"stairway2",
]));
	set("no_clean_up", 0);
	set("current_light", 3);

	setup();
	replace_program(ROOM);
}
