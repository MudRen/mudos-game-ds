// Room: /u/a/acme/area/pass2.c

#include <room.h>
inherit ROOM;
inherit DOOR;

void create()
{
	set("short", "山路");
	set("long", @LONG
你走在這蜿蜒的山路上，山路甚是崎嶇，小石佈滿了整條路，頗為難
行，往東可通往天城。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"wdoor",
  "west" : __DIR__"pass3",
]));
	set("no_clean_up", 0);
      set("outdoors","land");

	setup();
        create_door("northeast","西城門","southwest",DOOR_OPENED,"nokey");
}
