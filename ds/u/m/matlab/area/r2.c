// Room: /u/m/matlab/area/r2.c

inherit ROOM;

void create()
{
	set("short", "斷陽路");
	set("long", @LONG
走道到這�堣嬪O向東西兩邊分了開來，乍看之下兩邊竟然一模一樣!!
你心�堣ㄧT泛起一股異樣的感覺....
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"r1.c",
  "west" : __DIR__"r2-2.c",
  "east" : __DIR__"r2-1.c",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
