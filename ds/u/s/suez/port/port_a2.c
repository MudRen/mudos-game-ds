#include <ansi.h>
inherit ROOM;
void create()
{
        set("short",BLU"�O��G��"NOR);
        set("long",@LONG
�G�ӤѪ�O���������A�@�ӥ��j�������b�����A�����٦��@�Ǹ��p��
�_�Ǿ���A�ݰ_�ӹ��O���ݰ����A���O�b�o���e���p���o�F�����ݤu����
�N�ܡH�ݵۨ��륩���զX�A�A���T�h�óo�ӿO����O�G�H�ڪ��@�~�C��
���@�����@�ӳq���T�Ӫ�����A�ݰ_�Ӧ��G�O�̪�~��m�󦹡C
LONG 
);      
        set("light",0);
        set("exits",([
            "up":__DIR__"port_a3",
            "down":__DIR__"port_a1",
                ]));
        set("objects",([
             __DIR__"npc/bat":3,
                ]));
        set("world","world1");

        setup();
        replace_program(ROOM);

}

