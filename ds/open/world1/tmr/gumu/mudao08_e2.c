// Room: /open/world1/tmr/gumu/mudao08_e2.c

inherit ROOM;

void create()
{
	set("short", "墓道");
	set("long", @LONG
這里是古墓中的墓道，四周密不透風，借著�暀W昏暗的燈光，你能
勉強分辨出方向。�椄O用整塊的青石砌合起來的，接合得甚是完美，難
以從中找出一絲縫隙。燈光照在青石壁上，閃爍著碧幽幽的光點。
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 2);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"mudao08_e",
  "east" : __DIR__"mudao21",
]));

	setup();
	replace_program(ROOM);
}
