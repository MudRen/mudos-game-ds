#include <ansi.h>
inherit ROOM;
void create()
{
        set("short",MAG"���Z����"NOR);
        set("long",@LONG
�b��Ǥs�������A�ĺ��Ĵ��ߤ@�������u���Z�����v���ߩ󦹡A���M
�o�ӫ��Z�����Q����T�A�]���F�@���S�`�S�e���@���e�A�a�W�F�ԯ����W
�A�Ʀ��٥[�W�F���]�k�����ɡA���O�q�o�̥X�h�O�Q���w�������Z�j�D�A
�ڥ��S���ݭn�o�ث����A��Ӧ����Q���٬��u�ĺ��Ĵ��̶Q���U���v�C
LONG 
);
        set("exits",([
            "west":__DIR__"port_21",
            //"east":__DIR__"",
                ]));
        set("no_magic", 1);
        set("world","world1");
        set("outdoor","land");

        setup();
        replace_program(ROOM);

}
