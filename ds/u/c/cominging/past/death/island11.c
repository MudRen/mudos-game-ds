// Room: /u/c/cominging/past/death/island11.c

inherit ROOM;

void create()
{
	set("short", "�}�]�e");
	set("long", @LONG
�o�O�@������]�S�����ũж��C
LONG
	);
	set("current_light", 2);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "enter" : __DIR__"hole3",
  "south" : __DIR__"island10",
  "east" : __DIR__"island12",
]));
	set("world", "undefine");

	setup();
	replace_program(ROOM);
}
