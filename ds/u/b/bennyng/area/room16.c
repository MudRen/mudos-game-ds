// Room: /u/b/bennyng/area/room16.c
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "雙魚宮大門");
	set("long", @LONG
這裡就是十二宮中最後一個宮－－雙魚宮．只要打倒雙魚座黃金聖鬥
士，你就可以見到教皇了．在這裡你發現了一件怪事，為什麼這裡會傳來
陣陣幽香？？
LONG
	);
    set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"room13",
  "westdown" : __DIR__"room17",
]));
        set("objects", ([
  __DIR__"npc/guard.c":4,
]));
        create_door("north", "雙魚宮大門", "south", DOOR_CLOSED);
    set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
