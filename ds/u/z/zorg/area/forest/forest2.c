// Room: /u/z/zorg/area/forest/forest2.c

inherit ROOM;

void create()
{
	set("short", "�ũж�");
	set("long", @LONG
�o�O�@������]�S�����ũж��C
LONG
	);
	set("exits", ([ /* sizeof() == 6 */
  "southeast" : __DIR__"forest8",
  "south" : __DIR__"forest5",
  "north" : __DIR__"forest4",
  "west" : __DIR__"forest1",
  "east" : __DIR__"forest3",
  "southwest" : __DIR__"forest7",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
