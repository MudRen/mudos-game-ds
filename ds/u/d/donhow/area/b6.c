// Room: /u/d/donhow/area/b6.c

inherit ROOM;

void create()
{
	set("short", "�ũж�");
	set("long", @LONG
�o�O�@������]�S�����ũж��C
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"b11",
  "west" : __DIR__"b5",
  "east" : __DIR__"b7",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
