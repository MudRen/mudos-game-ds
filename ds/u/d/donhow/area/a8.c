// Room: /u/d/donhow/area/a8.c

inherit ROOM;

void create()
{
	set("short", "�ũж�");
	set("long", @LONG
�o�O�@������]�S�����ũж��C
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"a3",
  "west" : __DIR__"a7",
  "north" : __DIR__"b5",
  "east" : __DIR__"a9",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
