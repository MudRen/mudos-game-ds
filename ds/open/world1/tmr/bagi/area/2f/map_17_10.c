// Room: /open/world1/tmr/bagi/area/2f/map_17_10.c
#include <room.h>
inherit DOOR;

inherit ROOM;

void create()
{
	set("short", "�H��}�G�h");
	set("long", @LONG

LONG
	);
	set("exits", ([ /* sizeof() == 3 */
    "down" : __DIR__"3f",
  "northeast" : __DIR__"map_16_11",
  "northwest" : __DIR__"map_16_9",
]));
	set("item_desc", ([ /* sizeof() == 1 */
  "down" : (: look_door,     "down",     "/open/world1/tmr/bagi/area/3f/map_1_2" :),
]));
	set("map_long", 1);
	set("current_light", 3);
	set("no_clean_up", 1);

	setup();
        create_door("down","�۪�","up",DOOR_LOCKED,"bagi_key");

}
