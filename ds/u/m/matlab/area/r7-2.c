// Room: /u/m/matlab/area/r7-2.c

inherit ROOM;

void create()
{
	set("short", "���鷵");
	set("long", @LONG
�o�O�@������]�S�����ũж��C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"r6.c",
  "north" : __DIR__"r8.c",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
