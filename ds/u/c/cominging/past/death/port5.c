// Room: /u/c/cominging/past/death/port5.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�o�O�@������]�S�����ũж��C
LONG
	);
	set("current_light", 1);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"port2",
  "south" : __DIR__"port6",
]));
	set("world", "undefine");

	setup();
	replace_program(ROOM);
}
