#include <ansi.h>
inherit ROOM;
void create()
{
        set("short","�V��p�D");
        set("long",@LONG
�q�o�̥i�H�ݨ�O��N�b�������a��A�����ĺ��Ĵ���w�g�۷��F
�A�����n�����������i�Hť��A���x����f�q�o�̬ݨӹ��ε۪������w
�R�A�u����������s���M���۵ۡC
LONG 
);
        set("exits",([
            "eastdown":__DIR__"port_02",
            "eastup":__DIR__"port_00"
                ]));
        set("world","world1");
        set("outdoor","mount");

        setup();
        replace_program(ROOM);

}

