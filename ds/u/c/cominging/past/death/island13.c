// Room: /u/c/cominging/past/death/island13.c

inherit ROOM;

void create()
{
	set("short", "�p�q�W");
	set("long", @LONG
�o�O�@������]�S�����ũж��C
LONG
	);
	set("current_light", 2);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"island15",
  "south" : __DIR__"island8",
  "west" : __DIR__"island12",
  "east" : __DIR__"island14",
]));
	set("world", "undefine");

	setup();
	replace_program(ROOM);
}
