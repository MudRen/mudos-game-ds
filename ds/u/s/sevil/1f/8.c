// Room: /u/s/sevil/1f/8.c

inherit ROOM;

void create()
{
	set("short", "�e�s�����D");
	set("long", @LONG
�o�O�@������]�S�����ũж��C
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"9.c",
  "north" : __DIR__"13.c",
  "south" : __DIR__"3.c",
  "east" : __DIR__"7.c",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
