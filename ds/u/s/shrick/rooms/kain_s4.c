// Kain_south_4.c
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
        set("exits", ([/*sizeof=3*/
                "west"    : __DIR__"pray_st1",
                "north"    : __DIR__"kain_s3",
                "south"    : __DIR__"kain_s5",                
        ]) );
        set("outdoors","workroom.c");
        setup();
        replace_program(ROOM);
}
