// Room: /u/m/matlab/area/2f6.c

inherit ROOM;

void create()
{
	set("short", "�ũж�");
	set("long", @LONG
�o�O�@������]�S�����ũж��C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"2f2.c",
  "southwest" : __DIR__"2f3.c",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
