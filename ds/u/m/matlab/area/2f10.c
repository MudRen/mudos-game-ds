// Room: /u/m/matlab/area/2f10.c

inherit ROOM;

void create()
{
	set("short", "�ũж�");
	set("long", @LONG
�o�O�@������]�S�����ũж��C
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"2f13.c",
  "north" : __DIR__"2f3.c",
  "east" : __DIR__"2f9.c",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
