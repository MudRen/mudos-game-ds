// Room: /u/s/sevil/1f/22.c

inherit ROOM;

void create()
{
	set("short", "�ũж�");
	set("long", @LONG
�o�O�@������]�S�����ũж��C
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"17.c",
  "west" : __DIR__"23.c",
  "east" : __DIR__"21.c",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
