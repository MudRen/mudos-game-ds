// Moga_road_w1.c
#include <path.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short",HIG"莫格大道─ "HIW"西路"NOR);
        set("long",@LONG
  這條猶羅村東西向的道路莫格大道，此處是西路。
從這裡向北走是商業街。向南走則是在猶羅鎮中注
明的武器店。
LONG
        );
        set("exits", ([/*sizeof=4*/
                "east"    : __DIR__"crossd",
                "west"    : __DIR__"moga_w2",
                "north"    : __DIR__"bus_st1", 
                "south"    : __DIR__"wp",               
        ]) );

        set("outdoors","workroom.c");
        setup();
        replace_program(ROOM);
}
