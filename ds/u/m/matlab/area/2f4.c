// Room: /u/m/matlab/area/2f4.c

inherit ROOM;

void create()
{
	set("short", "�ũж�");
	set("long", @LONG
�o�O�@������]�S�����ũж��C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"r2fstart.c",
  "southwest" : __DIR__"2f11.c",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
