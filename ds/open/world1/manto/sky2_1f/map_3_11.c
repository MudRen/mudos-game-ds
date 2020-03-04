// Room: /open/world1/manto/sky2_1f/map_3_11.c

inherit ROOM;

void create()
{
	set("short", "���㶡");
	set("long", @LONG

LONG
	);
	set("light", 1);
	set("current_light", 1);
	set("map_long", 1);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"map_1_11",
  "east" : __DIR__"map_3_13",
  "west" : __DIR__"map_3_9",
  "south" : __DIR__"map_5_11",
]));
        set("objects",([
    __DIR__"obj/equip_box" :1,
]));

	setup();
      call_other( "/open/world1/manto/sky2_1f/board/sky_wish_b", "???" );
        set("stroom", 1);
}
