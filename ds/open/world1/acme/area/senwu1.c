// Room: /open/world1/acme/area/senwu1.c

inherit ROOM;

void create()
{
	set("short", "黃土小徑");
	set("long", @LONG
這裡是黃沙陵東南邊的黃土小徑，說也奇怪，黃沙陵強風凜凜，
此地卻無風，且轉沙為土，土成黃色，卻寸草不生。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"senwu2",
  "northwest" : __DIR__"hills1",
]));
	set("world", "past");
    set("outdoors","land");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
