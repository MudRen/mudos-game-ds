// Kain_south_2.c
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
                "north"    : __DIR__"kain_s1",
                "south"    : __DIR__"kain_s3",                
        ]) );
        set("outdoors","workroom.c");
        setup();
        replace_program(ROOM);
}
