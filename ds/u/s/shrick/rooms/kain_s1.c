// Kain_south_1.c
#include <path.h>
#include <ansi.h>
inherit ROOM;
void create()
{
       set("short",HIB"�ͮ��j�D�w"HIW" �n��"NOR);
        set("long",@LONG
  �o�̬O�Sù���n�_�V���D���C
LONG
        );
        set("exits", ([/*sizeof=2*/
                "north"    : __DIR__"crossd",
                "south"    : __DIR__"kain_s2",                
        ]) );
        set("outdoors","workroom.c");
        setup();
        replace_program(ROOM);
}
