// Moga_road_e1.c
#include <path.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short",HIG"����j�D�w "HIW"�F��"NOR);
        set("long",@LONG
  �o���Sù���F��V���D������j�D�A���B�O�F���C
�q�o�V�n���Oĵ��C
LONG
        );
        set("exits", ([/*sizeof=3*/
                "east"    : __DIR__"moga_e2",
                "west"    : __DIR__"crossd",
                "south"    : __DIR__"police",
                ]) );
        set("outdoors","workroom.c");
        setup();
        replace_program(ROOM);
}
