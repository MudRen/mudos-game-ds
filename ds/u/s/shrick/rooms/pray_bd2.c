// pray_building2.c
#include <path.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short",HIY"�����w" HIW"���U"NOR);
        set("long",@LONG
  �o�̬O�Sù���������A�����ǱN�n�X���������ë�i
�^�D�O�����a��A�o�̬O���U�C���U�|�P�y���ۼƤ��M
�������C
LONG
        );
        set("exits", ([/*sizeof=2*/
                "east"    : __DIR__"pray_bd1",
                ]) );
        set("outdoors","workroom.c");
        setup();
        replace_program(ROOM);
}


