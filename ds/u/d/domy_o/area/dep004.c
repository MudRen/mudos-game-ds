// Room: /u/d/domy/area/dep004.c

inherit ROOM;

void create()
{
	set("short", "�@��");
	set("long", @LONG
�o�O�@������]�S�����ũж��C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"dep003",
  "south" : __DIR__"dep001",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
