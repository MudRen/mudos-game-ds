// memery_st4_door.c
#include <path.h>
#include <ansi.h>
inherit ROOM;
void create()
{
       set("short",HIR"�����]"HIY"�j��"NOR);
        set("long",@LONG
  �A�����b�����]�j���U�C�V�̱�h�|�P�j���۲��Y��
�R����^�C
LONG
        );
        set("exits", ([/*sizeof=2*/
                "east"    : __DIR__"memo_bd",
                "west"    : __DIR__"memo3",
                ]) );
        set("outdoors","workroom.c");
        setup();
        replace_program(ROOM);
}



