// Room: /u/d/darkfool/area1/15.c

inherit ROOM;

void create()
{
	set("short", "�_��v�ϵ�D");
	set("long", @LONG
�_��v�Ϫ��@�Ө����A�S������S�O���a��C
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"14",
]));

	setup();
	replace_program(ROOM);
}
