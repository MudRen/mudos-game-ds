// Room: /open/world1/manto/sky2_1f/map_5_9.c

inherit ROOM;

void create()
{
	set("short", "�޲z��");
	set("long", @LONG

LONG
	);
	set("current_light", 2);
	set("light", 1);
	set("map_long", 1);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"map_3_9",
  "south" : __DIR__"map_7_9",
]));

	setup();
        set("stroom", 1);
      call_other( "/open/world1/manto/sky2_1f/board/sky_chat_b", "???" );
}
