// Kain_north_1.c
#include <path.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short",HIB"凱恩大道─"HIW" 北路"NOR);
        set("long",@LONG
  這裡是猶羅村南北向的道路。
LONG
        );
        set("exits", ([/*sizeof=2*/
                "north"    : __DIR__"kain_n2",
                "south"    : __DIR__"center",                
        ]) );
        set("outdoors","workroom.c");
        setup();
        replace_program(ROOM);
}
