// pray_building1.c
#include <path.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short",HIY"�����w" HIW"�e�U"NOR);
        set("long",@LONG
  �o�̬O�Sù���������A�����ǱN�n�X���������ë�i
�^�D�O�����a��C�o�̬O�e�U�C�|�P�����b�b���n���`
�`���H�ӥ������ˤl�C
LONG
        );
        set("exits", ([/*sizeof=2*/
                "east"    : __DIR__"pray_bridge",
                "west"    : __DIR__"pray_bd2",
                ]) );
        set("outdoors","workroom.c");
        setup();
        replace_program(ROOM);
}
