// Moga_road_w2.c
#include <path.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short",HIG"莫格大道─ "HIW"西路"NOR);
        set("long",@LONG
  這條猶羅村東西向的道路莫格大道，此處是西路。
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

