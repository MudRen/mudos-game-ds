#include <room.h>
inherit ROOM;
void create()
{
        set("short", "礦坑入口");
        set("long", @LONG
這裡是地下城通往礦坑的唯一道路，來往的礦工都哼著小曲，看起
來十分的快樂。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */ 
//     "enter":"/u/t/truewind/Minetown/area/minetown.c",
     "south":__DIR__"sec7.c",
]));
        set("light",1);
        set("objects", ([ /* sizeof() == 1 */
]));

        setup();
        replace_program(ROOM);

}
