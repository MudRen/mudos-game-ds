// Room: /u/s/sub/area/valley/map_6_1.c

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
            __DIR__"npc/beast_rabbit_10" : 2,
          ]) );
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"map_6_2",
  "north" : __DIR__"map_5_1",
]));
	set("current_light", 1);

	setup();
}
