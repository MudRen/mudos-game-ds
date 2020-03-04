// memery_st4_door.c
#include <path.h>
#include <ansi.h>
inherit ROOM;
void create()
{
       set("short",HIR"紀念館"HIY"大門"NOR);
        set("long",@LONG
  你正站在紀念館大門下。向裡望去四周瀰漫著莊嚴肅
靜的氣氛。
LONG
        );
        set("exits", ([/*sizeof=2*/
                "east"    : __DIR__"memo_bd",
                "west"    : __DIR__"memo3",
                ]) );
        set("outdoors","workroom.c");
        setup();
        replace_program(ROOM);
}



