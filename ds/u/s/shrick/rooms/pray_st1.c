// pray_streat1.c
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
                "east"    : __DIR__"kain_s4",
                "west"    : __DIR__"pray_st2",
                ]) );

        set("outdoors","workroom.c");
        setup();
        replace_program(ROOM);
}
