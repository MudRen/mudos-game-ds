// Moga_road_e4.c
#include <path.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short",HIG"����j�D�w "HIW"�F��"NOR);
        set("long",@LONG
  �o���Sù���F��V���D������j�D�A���B�O�F���C
�q�o�V�n���O���]�C
LONG
        );
        set("exits", ([/*sizeof=2*/
                "east"    : __DIR__"door2",
                "west"    : __DIR__"moga_e3",
                "south"    : __DIR__"hotel",
                ]) );
        set("outdoors","workroom.c");
        setup();
        replace_program(ROOM);
}
