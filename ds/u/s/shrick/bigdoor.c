// bigdoor.c
#include <path.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIG"中央科技大樓的大門"NOR);
        set("long",@LONG
這是•中央科技中心•的大門想進入的話，請洽:7979939 ：p
LONG
        );
        set("exits", ([
                "east" : __DIR__"workroom",
                "west" : __DIR__"sr1",
                
        ]) );

        set("outdoors","workroom.c");
        setup();
        replace_program(ROOM);
}


