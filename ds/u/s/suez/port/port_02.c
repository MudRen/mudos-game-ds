#include <ansi.h>
inherit ROOM;
void create()
{
        set("short","�V��p�D");
        set("long",@LONG
�o���p���b�o�̤w�g���������@�q�Z���F�A�U�������ǨӮ���������
�۪��n���A���񪺱V���W�]�����F�C�a�C
LONG 
);
        set("exits",([
            "eastdown":__DIR__"port_03",
            "westup":__DIR__"port_01"
                ]));
        set("world","world1");
        set("outdoor","mount");

        setup();
        replace_program(ROOM);

}

