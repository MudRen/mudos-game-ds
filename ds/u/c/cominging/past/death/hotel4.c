// Room: /u/c/cominging/past/death/hotel4.c

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
  "north" : __DIR__"hotel5",
  "south" : __DIR__"hotel10",
  "west" : __DIR__"hotel2",
  "east" : __DIR__"hotel6",
]));
	set("world", "undefine");

	setup();
	replace_program(ROOM);
}
