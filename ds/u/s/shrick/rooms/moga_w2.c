// Moga_road_w2.c
#include <path.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short",HIG"����j�D�w "HIW"���"NOR);
        set("long",@LONG
  �o���Sù���F��V���D������j�D�A���B�O����C
LONG
        );
        set("exits", ([/*sizeof=2*/
                "east"    : __DIR__"moga_w1",
                "west"    : __DIR__"moga_w3",
                            ]) );
        set("outdoors","workroom.c");
        setup();
        replace_program(ROOM);
}

