// Room: /u/c/cominging/past/death/underground5.c

inherit ROOM;

void create()
{
	set("short", "�ũж�");
	set("long", @LONG
�o�O�@������]�S�����ũж��C
LONG
	);
	set("current_light", 1);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"underground2",
  "south" : __DIR__"underground8",
  "west" : __DIR__"underground4",
  "east" : __DIR__"underground6",
]));
	set("world", "undefine");

	setup();
	replace_program(ROOM);
}
