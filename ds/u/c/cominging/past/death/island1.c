// Room: /u/c/cominging/past/death/island1.c

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
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"island3",
]));
	set("world", "undefine");

	setup();
	replace_program(ROOM);
}
