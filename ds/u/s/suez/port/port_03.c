#include <ansi.h>
inherit ROOM;
void create()
{
        set("short","崖邊小道");
        set("long",@LONG
這附近的崖壁上被開闢出一條窄窄的小路，順著這小路就可以到達燈
塔，這條小路可能也是為了這個目的才築起的吧。
LONG 
);
        set("exits",([
            "east":__DIR__"port_06",
            "westup":__DIR__"port_02"
                ]));
        set("world","world1");
        set("outdoor","mount");

        setup();
        replace_program(ROOM);

}

