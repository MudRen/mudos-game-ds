// Room: /open/world1/tmr/bagi/area/3f/map_1_2.c
#include <room.h>

inherit DOOR;

inherit ROOM;

void create()
{
	set("short", "�H��}�T�h");
	set("long", @LONG

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "up" : "/open/world1/tmr/bagi/area/2f/map_17_10",
  "southeast" : __DIR__"map_2_3",
]));
	set("map_long", 1);
	set("no_clean_up", 0);
	set("current_light", 3);

	setup();
        create_door("up","�۪�","down",DOOR_LOCKED,"bagi_key");

}
