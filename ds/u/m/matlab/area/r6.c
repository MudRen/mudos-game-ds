// Room: /u/m/matlab/area/r6.c

inherit ROOM;

void create()
{
	set("short", "�ũж�");
	set("long", @LONG
�o�O�@������]�S�����ũж��C
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "northeast" : __DIR__"r7-1.c",
  "north" : __DIR__"r7.c",
  "south" : __DIR__"r5.c",
  "northwest" : __DIR__"r7-2.c",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
