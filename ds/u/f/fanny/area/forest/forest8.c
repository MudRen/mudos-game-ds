// Room: /u/f/fanny/area/forest/forest8.c

inherit ROOM;

void create()
{
	set("short", "��F");
	set("long", @LONG
��F�̥u��²�檺��ȡA�W���٧G���F�ǹСA�ݨӳo�̦��G�H��
�u�ܡA���T�O�ӥ𮧪��n�a��C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"forest7",
]));

	setup();
	replace_program(ROOM);
}
