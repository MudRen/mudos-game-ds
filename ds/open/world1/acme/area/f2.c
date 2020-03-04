// Room: /open/world1/acme/area/f2.c

inherit ROOM;

void create()
{
	set("short", "野林");
	set("long", @LONG
幾絲陽光，從高大濃密的茂葉中射落陰暗的林中，林中靜到極點
，四周都是高大的喬木，就似到了另一世界般。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"f3",
  "south" : __DIR__"f1",
]));
     set("outdoors","land");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
