#include <ansi.h>
inherit ROOM;
void create()
{
         set("short",HIM"�Z�^���q"NOR);
        set("long",@LONG
�A�@�i��o�̡A�N�Q�o�̵ξA�����ҩҧl�ޡA�Ȧ檺�h�����������F
�@�j�b�C���R������Q�ˤ����۩I�ۨC�ӤH�A�𺸯�����o�X�ɤH������
�A�|�P����W�O�u�Z�^���q�ǻ��v�����e�A�@�ӧu�C�֤H�����۽ݵ^�۵�
�����R���ǻ��A�o�ɭԦp�G�A�Ӥ@�ȵۦW��Ĩۣ���մ��N��n�F�I
LONG 
);
        set("exits",([
            "north":__DIR__"port_21",
                ]));

        set("world","world1");
        set("no_fight",1);
        set("no_magic", 1);
        set("light",1);
        set("objects",([
            __DIR__"npc/bard":1,
            __DIR__"reihi":1,
                ]));
        setup();
        replace_program(ROOM);

}

