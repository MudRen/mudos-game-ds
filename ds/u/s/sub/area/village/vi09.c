// Room: /u/s/sub/area/village/eqroom.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�o�O�@������]�S�����ũж��C
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"vi05",
]));
	set("world", "undefine");
	set("current_light", 2);

	setup();
	replace_program(ROOM);
}
