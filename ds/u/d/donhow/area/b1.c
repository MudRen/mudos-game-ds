// Room: /u/d/donhow/area/b1.c

inherit ROOM;

void create()
{
	set("short", "�ũж�");
	set("long", @LONG
�o�O�@������]�S�����ũж��C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"b2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
