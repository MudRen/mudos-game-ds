// pray_steat2.c
#include <path.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short",HIG"�����D"NOR);
        set("long",@LONG
  �o���Sù���������D���q�o�̦V�訫�O�����C
�V�F���O�ͮ��j�D�n���C
LONG
        );
        set("exits", ([/*sizeof=2*/
                "east"    : __DIR__"pray_st1",
                "west"    : __DIR__"pray_bridge",
                ]) );

        set("outdoors","workroom.c");
        setup();
        replace_program(ROOM);
}
