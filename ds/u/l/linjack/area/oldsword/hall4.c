#include <room.h>
inherit ROOM;
void create()
{
 set("short","花崗迴廊");
 set("long",@LONG
花崗迴廊四周都是遍佈的花崗岩, 地上有擺了一些小盆栽,
你偶爾可以看到幾隻小蝴蝶在這邊穿縮著. 你剛走進來, 就發
現這邊的風異常的寒冷, 直朝你迎面吹來, 通過這條迴廊不知
道會通到哪裡去?
LONG
    );
 set("exits",([
               "west":__DIR__"hall3",
               "east":__DIR__"hall5",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
