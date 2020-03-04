#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "洞窟");
        set("long",@LONG
你到了洞窟的內部，野獸的吼聲更劇烈了，猛獸的的叫聲讓你的眼皮
一直猛跳，你看到裡面好像有個人?
LONG
);
        set("exits", ([ /* sizeof() == 2 */
  "south" :"/u/t/tako/area/room~2.c",
  "north" :"/u/t/tako/area/room~4.c",
]));
    set("light",1);
set("objects", ([ /* sizeof() == 1 */
"/u/t/tako/area/redhone.c" : 1,
]));        set("no_clean_up", 0);
                set("outdoors","land");

        setup();
        replace_program(ROOM);
}

