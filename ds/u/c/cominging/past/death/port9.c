// Room: /u/c/cominging/past/death/port9.c

inherit ROOM;

void create()
{
	set("short", "�_�S���j�}");
	set("long", @LONG
�o�O�@������]�S�����ũж��C
LONG
	);
	set("current_light", 1);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "northeast" : __DIR__"port7",
]));
	set("world", "undefine");

	setup();
	replace_program(ROOM);
}
