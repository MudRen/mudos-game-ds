// cross_road.c
#include <path.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short",HIY"十字路口"NOR);
        set("long",@LONG
  這裡是猶羅村的十字路口。凱恩大道與莫格大道
就是交會於此，人潮之多多如海水。
LONG
        );
        set("exits", ([/*sizeof=4*/
                "east"    : __DIR__"moga_e1",
                "west"    : __DIR__"moga_w1",
                "north"    : __DIR__"center",
                "south"    : __DIR__"kain_s1",                
        ]) );

        set("outdoors","workroom.c");
        setup();
        replace_program(ROOM);
}
