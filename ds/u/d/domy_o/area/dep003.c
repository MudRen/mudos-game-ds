// Room: /u/d/domy/area/dep003.c

inherit ROOM;

void create()
{
	set("short", "�@��");
	set("long", @LONG
�o�O�@������]�S�����ũж��C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"dep002",
  "east" : __DIR__"dep004",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
