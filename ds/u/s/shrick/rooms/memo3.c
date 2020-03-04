// memery_st3.c
#include <path.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIR"紀念路"NOR);
        set("long",@LONG
  這條猶羅村的紀念路。是為要紀念那些已故的海
上英雄所建的，這條路在向左去便是紀念館，裡面
收藏著許多資料和文獻。
LONG
        );
        set("exits", ([/*sizeof=2*/
                "east"    : __DIR__"memo_d",
                "south"    : __DIR__"memo2",
                ]) );
        set("outdoors","workroom.c");
        setup();
        replace_program(ROOM);
}
