#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
        set("short", "空地"NOR);
        set("long", @LONG
這裡是皇陵內的一處空地，看起來頗陰森的。在這空地還有許多花花
草草的，但都以雕落了，你心裡不禁為這些生物悲哀阿!!
LONG
        );

           set("exits", ([ /* sizeof() == 1 */
            "north" : __DIR__"room3",
            ]));
        
       set("no_clean_up", 0);
        set("no_light", 1);
       set("valid_startroom",1);

        setup();
        replace_program(ROOM);
}


        
