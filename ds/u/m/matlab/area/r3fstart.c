// Room: /u/m/matlab/area/r3fstart.c

inherit ROOM;

void create()
{
	set("short", "�I�ѻ�3��");
	set("long", @LONG
�o�O�@������]�S�����ũж��C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"2fto3f.c",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
