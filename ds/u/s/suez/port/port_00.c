#include <ansi.h>
inherit ROOM;
void create()
{
        set("short",CYN"�V���O��"NOR);
        set("long",@LONG
���m���g�׹������۰��|�X���e�o�y�j�Ѫ��O��A�𩳪����F�ý���
���A���ɦ������q�O�𤺭��X�A�ǥզ⪺�����T�I��b�U�Ө����C�u�o��
�O�����ӫܥj�ѤF�a�I�v�A�o��Q�ۡA���O�z�ߤ��n���������ߦb�A���e
�A���G���۳s�ɶ����L�k�����������ݤO�C
LONG 
);
        set("exits",([
            "in":__DIR__"port_a1",
            "westdown":__DIR__"port_01"
                ]));
        set("world","world1");
        set("outdoor","mount");

        setup();
        replace_program(ROOM);

}

