// Room: /u/f/fanny/area/town3.c

inherit ROOM;

void create()
{
	set("short", "�K�a��");
	set("long", @LONG
�o�O�@������]�S�����ũж��C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"town2",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
