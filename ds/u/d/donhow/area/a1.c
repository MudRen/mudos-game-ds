// Room: /u/d/donhow/area/a1.c

inherit ROOM;

void create()
{
	set("short", "�ũж�");
	set("long", @LONG
�o�O�@������]�S�����ũж��C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"a6",
  "east" : __DIR__"a2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
