// Room: /u/c/cominging/past/death/port8.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�o�O�@������]�S�����ũж��C
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 2);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"port7",
]));
	set("world", "undefine");

	setup();
	replace_program(ROOM);
}
