// Room: /open/world1/manto/sky2_1f/map_3_9.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG

LONG
	);
	set("current_light", 7);
	set("light", 1);
	set("map_long", 1);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"map_1_9",
  "east" : __DIR__"map_3_11",
  "west" : __DIR__"map_3_7",
  "south" : __DIR__"map_5_9",
]));

	setup();
      call_other( "/open/world1/manto/sky2_1f/board/sky_announce_b", "???" );
        set("stroom", 1);
}
