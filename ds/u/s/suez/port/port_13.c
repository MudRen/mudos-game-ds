#include <ansi.h>
inherit ROOM;
void create()
{
        set("short","小徑");
        set("long",@LONG
雖然這裡也有不少人出入，但是明顯比港口那邊安靜多了，薩爾薩斯
的居民通常都住在這附近。從這裡往北就是卡卡彌恩小徑。
LONG 
);
        set("exits",([
            "north":__DIR__"port_14",
            "south":__DIR__"port_12"
                ]));
        set("world","world1");
        set("outdoor","land");

        setup();
        replace_program(ROOM);

}
