// Room: /u/z/zorg/area/forest/forest10.c

inherit ROOM;

void create()
{
	set("short", "�ũж�");
	set("long", @LONG
�o�O�@������]�S�����ũж��C
LONG
	);
	set("exits", ([ /* sizeof() == 6 */
  "southeast" : __DIR__"forest16",
  "south" : __DIR__"forest13",
  "west" : __DIR__"forest9",
  "north" : __DIR__"forest12",
  "east" : __DIR__"forest11",
  "southwest" : __DIR__"forest15",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
