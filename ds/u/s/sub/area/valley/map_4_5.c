// Room: /u/s/sub/area/valley/map_4_5.c

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
        __DIR__"npc/beast_rabbit_10":2,
          ]) );
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"map_3_5",
  "west" : __DIR__"map_4_4",
  "south" : __DIR__"map_5_5",
]));
	set("current_light", 1);

	setup();
	replace_program(ROOM);
}
