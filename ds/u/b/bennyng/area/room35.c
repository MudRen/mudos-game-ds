// Room: /u/b/bennyng/area/room35.c

inherit ROOM;

void create()
{
	set("short", "�Q���W");
	set("long", @LONG
�o�O�@����צn���Q���A���U�ݤ@�ݡA�A���ߤ]�֭n���X�ӡD
LONG
	);
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"room36",
  "north" : __DIR__"room34",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
