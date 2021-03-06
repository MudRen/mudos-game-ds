// Room: /u/a/acme/area2/t41.c

#include <room.h>
inherit ROOM;
inherit DOOR;

void create()
{
	set("short", "幽冥地窖[地下四層]");
	set("long", @LONG
你正走在黑暗無比的地道中，地道窄又長，好像走不完似的，越
往裡頭心裡越害怕，這股黑暗的氣流令你窒息。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"t42",
  "north" : __DIR__"t40",
]));
  set("item_desc", ([ /* sizeof() == 1 */
      "大門" : "這是一扇紅色的大門，門似乎上了鎖。\n",
      "紅色大門" : "這是一扇紅色的大門，門似乎上了鎖。\n",
  ]) );
 
  set("hide_exits", ([
  ]));
	set("no_clean_up", 0);

	setup();
    create_door("north","紅色大門","south",DOOR_LOCKED,"redkey");
}
int valid_leave(object me, string dir)
{
    if( userp(me) && objectp( present("__GUARD__", this_object()) ))
            return notify_fail("這裡太過擁擠了，你走不過去。\n");
    return ::valid_leave(me, dir);
}

