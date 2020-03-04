// Room: /open/world1/tmr/dragoncity/northgate2.c
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "青龍外門");
        set("long", 
"這裡是磐龍城的東城門的外城門，只見城門上方是三個大字。\n"
"\n"
HIC"                      青龍門\n"NOR
"\n"
        );
        set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"eastgate1",
]));
        set("current_light", 2);
        set("no_clean_up", 0);
        set("outdoors", "land");

        setup();
        replace_program(ROOM);
}

