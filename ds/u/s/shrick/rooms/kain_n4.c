// Kain_north_4.c
#include <path.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short",HIB"�ͮ��j�D�w"HIW" �_��"NOR);
        set("long",@LONG
  �o�̬O�Sù���n�_�V���D���C
LONG
        );
        set("exits", ([/*sizeof=2*/
                "north"    : __DIR__"kain_n5",
                "south"    : __DIR__"kain_n3",                
        ]) );
        set("outdoors","workroom.c");
        setup();
        replace_program(ROOM);
}

