#include <room.h>
inherit ROOM;
void create()
{
        set("short", "Item Recover Shop");
        set("long", @LONG
            這是一間空房間[0;1;31m [0m
LONG
        );
        set("exits", ([ /* sizeof() == 4 */ 
     "west":__DIR__"sec3.c",
]));
        set("light",1);
        set("objects", ([ /* sizeof() == 1 */
]));

        setup();
        replace_program(ROOM);

}


