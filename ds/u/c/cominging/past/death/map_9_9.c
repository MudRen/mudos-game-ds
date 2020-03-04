// Room: /u/c/cominging/past/death/map_9_9.c

inherit ROOM;

void create()
{
	set("short", "�ȴ�");
	set("long", @LONG

LONG
	);
	set("current_light", 1);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"map_9_8",
  "east" : __DIR__"hotel2",
]));
	set("map_long", 1);
	set("world", "undefine");

	setup();
	replace_program(ROOM);
}
