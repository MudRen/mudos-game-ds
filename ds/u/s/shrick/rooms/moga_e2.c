// Moga_road_e2.c
#include <path.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short",HIG"����j�D�w "HIW"�F��"NOR);
        set("long",@LONG
  �o���Sù���F��V���D������j�D�A���B�O�F���C
�q�o�V�n���O�˳Ʃ��C
LONG
        );
        set("exits", ([/*sizeof=3*/
                "east"    : __DIR__"moga_e3",
                "west"    : __DIR__"moga_e1",
                "south"    : __DIR__"eq",
                ]) );
        set("outdoors","workroom.c");
        setup();
        replace_program(ROOM);
}
