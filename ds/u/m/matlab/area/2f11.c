// Room: /u/m/matlab/area/2f11.c

inherit ROOM;

void create()
{
	set("short", "�ũж�");
	set("long", @LONG
�o�O�@������]�S�����ũж��C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"2f4.c",
  "west" : __DIR__"2f12.c",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
