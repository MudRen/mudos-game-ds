// Room: /u/c/cominging/past/death/hole2.c

inherit ROOM;

void create()
{
	set("short", "�·t���p�}�]");
	set("long", @LONG
�o�O�@������]�S�����ũж��C
LONG
	);
	set("current_light", 2);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"island8",
]));
	set("world", "undefine");

	setup();
	replace_program(ROOM);
}
