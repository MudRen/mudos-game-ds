// Room: /u/l/linjack/area/emperor/forest1.c

inherit ROOM;

void create()
{
	set("short", "�ũж�");
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"road4",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
