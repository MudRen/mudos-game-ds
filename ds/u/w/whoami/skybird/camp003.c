#include <room.h>
inherit DOOR;
inherit ROOM;

void create()
{
        set("short", "固山寨大門");
        set("long", @LONG
固山寨得名是因為這座寨子建在一座小山頭上，與其說是小
山，不如說是一座岩石丘陵，而且寨子�堶惘酗@眼水量極大的泉
水，順著山勢流下。
LONG);
        set("exits", ([ /* sizeof() == 3 */
  "out" : __DIR__"camp002",
  "north" : __DIR__"camp004",
  "south" : __DIR__"camp005",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"mob/camp_guard" : random(2)+1,
  ]));
        set("light",1);
        set("outdoors","land");
        set("no_clean_up", 0);
        setup();
        create_door("out","寨門","enter",DOOR_CLOSED);
}

int valid_leave(object me, string dir)
{
       ::valid_leave();
       if( dir=="out" && !userp(me) )
           return notify_fail("那裡只有玩家才能進去。\n");
       return ::valid_leave(me, dir);
}

