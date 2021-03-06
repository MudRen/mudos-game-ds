// Room: /open/world1/tmr/goat_maze/stairway3.c

inherit ROOM;

void create()
{
	set("short", "羊男的迷宮 - 地底階梯");
	set("long", @LONG
你正在走一條石頭鋪成的地底階梯，楷梯不停地往下延伸，在黑暗
中宛如條灰色石龍。你踏在階梯上的聲響，一聲聲地迴蕩在整個空間，
平添幾分詭異的色彩。階梯到此，你心中默數的階梯已經超過數百來階
了，但是你可經可以約略發現下面似乎有通到一處很大的廣場。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "down" : __DIR__"stairway4",
  "up" : __DIR__"stairway2",
]));
	set("current_light", 2);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
