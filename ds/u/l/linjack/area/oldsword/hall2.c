#include <room.h>
inherit ROOM;
void create()
{
 set("short","花崗迴廊");
 set("long",@LONG
花崗迴廊四周都是遍佈的花崗岩, 地上有擺了一些小盆栽,
你偶爾可以看到幾隻小蝴蝶在這邊穿縮著. 你仔細望了一望,
前方似乎就是花缸迴廊的盡頭了, 或許你該出去看看?
LONG
    );
 set("exits",([
               "north":__DIR__"hall1",
               "south":__DIR__"hall3",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
