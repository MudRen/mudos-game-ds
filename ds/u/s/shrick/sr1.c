// sr1.c
#include <path.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",HIG"研究室﹝一﹞"NOR);
        set("long",@LONG
這是•研究室﹝一﹞•安靜一點,不要吵到他們了ㄡ!
LONG
        );
        set("exits", ([
                "east" : __DIR__"bigdoor",
                "west" : __DIR__"sr2",
                
        ]) );

        set("outdoors","workroom.c");
        setup();
        replace_program(ROOM);
}
