// cross_road.c
#include <path.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short",HIY"�Q�r���f"NOR);
        set("long",@LONG
  �o�̬O�Sù�����Q�r���f�C�ͮ��j�D�P����j�D
�N�O��|�󦹡A�H�餧�h�h�p�����C
LONG
        );
        set("exits", ([/*sizeof=4*/
                "east"    : __DIR__"moga_e1",
                "west"    : __DIR__"moga_w1",
                "north"    : __DIR__"center",
                "south"    : __DIR__"kain_s1",                
        ]) );

        set("outdoors","workroom.c");
        setup();
        replace_program(ROOM);
}
