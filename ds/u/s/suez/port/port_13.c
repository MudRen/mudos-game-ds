#include <ansi.h>
inherit ROOM;
void create()
{
        set("short","�p�|");
        set("long",@LONG
���M�o�̤]�����֤H�X�J�A���O������f����w�R�h�F�A�ĺ��Ĵ�
���~���q�`����b�o����C�q�o�̩��_�N�O�d�d�����p�|�C
LONG 
);
        set("exits",([
            "north":__DIR__"port_14",
            "south":__DIR__"port_12"
                ]));
        set("world","world1");
        set("outdoor","land");

        setup();
        replace_program(ROOM);

}
