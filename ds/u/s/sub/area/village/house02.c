// Room: /u/s/sub/area/village/house02.c

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
        set("objects", ([
        __DIR__"npc/village_man1_40" : 1,
        ]) );
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"vi06",
]));

	setup();
	replace_program(ROOM);
}
