#include <ansi.h>
inherit ROOM;
void create()
{
       set("short","�d�d�����p�|");
        set("long",@LONG
�d�d�����A�O���t�y���u�@�������v���N��A�H�۴�f���o�i�A�o��
�]���U�ӷU�h�_�I�̶i�X�F�A�쥻�u�O�B�e�����p�~�p�|�A�N�Q���F��
�R�����֪��W�r�A�Ʊ�C�ӱq�o�̥X�~���H�̳���@�������C
LONG 
);
        set("exits",([
            "south":__DIR__"port_13",
            //"north":__DIR__"",
                ]));
        set("world","world1");
        set("outdoor","land");

        setup();
        replace_program(ROOM);

}
