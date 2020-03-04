// Room: /u/s/sub/area/valley/map_4_3.c

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG

LONG
	);
	set("outdoors", "land");
	set("world", "undefine");
	set("no_clean_up", 0);
	set("map_long", 1);
        set("objects", ([
        __DIR__"npc/beast_grasshopper_3" : 2,
          ]) );
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"map_4_4",
  "north" : __DIR__"map_3_3",
  "west" : __DIR__"map_4_2",
  "south" : __DIR__"map_5_3",
]));
	set("current_light", 1);

	setup();
	replace_program(ROOM);
}
