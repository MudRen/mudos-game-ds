// sr2.c
#include <path.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",HIG"研究室﹝二﹞"NOR);
        set("long",@LONG
這是•研究室﹝二﹞•安靜一點,不要吵到他們了ㄡ!
他們正在研究怎麼把"垃圾(TRASH)"變成有用的東西•
LONG
        );
        set("exits", ([
                "east" : __DIR__"sr1",
                
        ]) );

        set("outdoors","workroom.c");
        setup();
        replace_program(ROOM);
}

