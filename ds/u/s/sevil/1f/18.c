// Room: /u/s/sevil/1f/18.c

inherit ROOM;

void create()
{
	set("short", "�ũж�");
	set("long", @LONG
�o�O�@������]�S�����ũж��C
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"13.c",
  "west" : __DIR__"19.c",
  "north" : __DIR__"23.c",
  "east" : __DIR__"17.c",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
