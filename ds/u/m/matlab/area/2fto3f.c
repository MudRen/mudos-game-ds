// Room: /u/m/matlab/area/2fto3f.c

inherit ROOM;

void create()
{
	set("short", "�ӱ�");
	set("long", @LONG
�o�O�@������]�S�����ũж��C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"r3fstart.c",
  "east" : __DIR__"2f5.c",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
