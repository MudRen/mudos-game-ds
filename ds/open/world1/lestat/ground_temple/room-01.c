#include <ansi.h>
inherit ROOM;

void create()
{
        set( "short", "�}�޳q�D") ;
        set( "long", @LONG
���F�n�[�A���U���q�D�̵M�������Y�A�A�^�Y�@��A�W�誺�X��
�]�u�Ѥ@�Ӥp���I�F�A�b�o�������q�D���A�A�ߤ@���o�{�O�V���U��
�A��Ӭ}�ު��H�y����V����C
LONG
);
        set("exits", ([ /* sizeof() == 2 */
                  "down" : __DIR__"room-02",
                  "up" : __DIR__"room-46",
        ]));
        set("light",0);
        set("no_recall","���@�ѩǲ����ϳ��O�q�ϱo�A�L�k�ǰe�C");
        set("no_clean_up", 0);
        setup();
}

