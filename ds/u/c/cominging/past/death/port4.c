// Room: /u/c/cominging/past/death/port4.c

inherit ROOM;

void create()
{
	set("short", "�ܮw");
	set("long", @LONG
�o�O�@������]�S�����ũж��C
LONG
	);
	set("current_light", 1);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"port2",
]));
	set("world", "undefine");

	setup();
	replace_program(ROOM);
}
