// Room: /u/c/cominging/past/death/hotel2.c

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
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"hotel3",
  "west" : __DIR__"map_9_9",
  "east" : __DIR__"hotel4",
]));
	set("world", "undefine");

	setup();
	replace_program(ROOM);
}
