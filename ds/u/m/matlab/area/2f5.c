// Room: /u/m/matlab/area/2f5.c

inherit ROOM;

void create()
{
	set("short", "�ũж�");
	set("long", @LONG
�o�O�@������]�S�����ũж��C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"2fto3f.c",
  "south" : __DIR__"2f1.c",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
