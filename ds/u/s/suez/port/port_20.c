#include <ansi.h>
inherit ROOM;
void create()
{
        set("short","�שԤj�D");
        set("long",@LONG
�q�o�̩��F�N�O�s�سy���j���D���u�שԤj�D�v�A���ѩ�ӤH�̩�
��_�誺�d�d�����p�|�Ӥp�F�A�~���]�����F�f���i�X�ɪ������C���Ҭ�
�F�o�Ӱ��D��ӤF�j�ӤH�שԡA��O�שԫK�X��W���E�]�F�o���j�D�A��
�B���A��L�ӤH�@�P�س]���X�i�ĺ��Ĵ���C���F�����o��ӤH�A�K�N�o
���j�D�٤����שԤj�D�C
LONG 
);
        set("exits",([
            "west":__DIR__"port_19",
            "east":__DIR__"port_21"
                ]));

        set("world","world1");
        set("outdoor","land");

        setup();
        replace_program(ROOM);

}
