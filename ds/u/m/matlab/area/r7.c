// Room: /u/m/matlab/area/r7.c

inherit ROOM;

void create()
{
	set("short", "�_�뷵");
	set("long", @LONG
�o�O�@������]�S�����ũж��C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"r8.c",
  "south" : __DIR__"r6.c",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
