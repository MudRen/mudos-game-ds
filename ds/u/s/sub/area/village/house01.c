// Room: /u/s/sub/area/village/house01.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�o�O�@������]�S�����ũж��C
LONG
	);
	set("world", "undefine");
	set("no_clean_up", 0);
	set("current_light", 1);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"vi04.c",
]));

	setup();
	replace_program(ROOM);
}
