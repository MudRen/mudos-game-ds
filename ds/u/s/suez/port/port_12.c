#include <ansi.h>
inherit ROOM;
void create()
{
        set("short","小徑");
        set("long",@LONG
從這裡往北就是薩爾薩斯北方的出口了，和港口那邊的喧鬧不同，這
裡安靜多了。幾間商店坐落在小徑的兩旁，賣著當地居民需要的日常用品
，旁邊的牆上懶懶的睡著幾隻貓，訴說著午後的悠閒。
LONG 
);
        set("exits",([
            "west":__DIR__"port_11",
            "north":__DIR__"port_13"
                ]));
        set("world","world1");
        set("outdoor","land");

        setup();
        replace_program(ROOM);

}
