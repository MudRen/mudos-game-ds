// Moga_road_w1.c
#include <path.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short",HIG"����j�D�w "HIW"���"NOR);
        set("long",@LONG
  �o���Sù���F��V���D������j�D�A���B�O����C
�q�o�̦V�_���O�ӷ~��C�V�n���h�O�b�Sù���`
�����Z�����C
LONG
        );
        set("exits", ([/*sizeof=4*/
                "east"    : __DIR__"crossd",
                "west"    : __DIR__"moga_w2",
                "north"    : __DIR__"bus_st1", 
                "south"    : __DIR__"wp",               
        ]) );

        set("outdoors","workroom.c");
        setup();
        replace_program(ROOM);
}
