// Moga_road_e3.c
#include <path.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short",HIG"莫格大道─ "HIW"東路"NOR);
        set("long",@LONG
  這條猶羅村東西向的道路莫格大道，此處是東路。
從這向南走是南北雜貨店。
LONG
        );
        set("exits", ([/*sizeof=3*/
                "east"    : __DIR__"moga_e4",
                "west"    : __DIR__"moga_e2",
                "south"    : __DIR__"store",
                ]) );

        set("outdoors","workroom.c");
        setup();
        replace_program(ROOM);
}
