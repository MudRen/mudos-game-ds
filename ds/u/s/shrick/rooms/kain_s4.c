// Kain_south_4.c
#include <path.h>
#include <ansi.h>
inherit ROOM;
void create()
{
       set("short",HIB"凱恩大道─"HIW" 南路"NOR);
        set("long",@LONG
  這裡是猶羅村南北向的道路。
LONG
        );
        set("exits", ([/*sizeof=3*/
                "west"    : __DIR__"pray_st1",
                "north"    : __DIR__"kain_s3",
                "south"    : __DIR__"kain_s5",                
        ]) );
        set("outdoors","workroom.c");
        setup();
        replace_program(ROOM);
}
