// Room: /u/c/cominging/past/death/hotel12.c

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
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"hotel11",
  "west" : __DIR__"hotel13",
]));
	set("world", "undefine");

	setup();
	replace_program(ROOM);
}
