// bigdoor.c
#include <path.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIG"������ޤj�Ӫ��j��"NOR);
        set("long",@LONG
�o�O�E������ޤ��ߡE���j���Q�i�J���ܡA�Ь�:7979939 �Gp
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


