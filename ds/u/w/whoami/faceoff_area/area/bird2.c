#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"�ѱ��j�|"NOR);

 set("long",@LONG 
�A�@���i����, ���e���}�Ѯ�^�ߨ�h�F�j�b, �o�@�Ӥj�|
�Q�ӥ��w�O�Ҧ��ѱ��̤lť�V, �ŶǤj�ƪ��a��, �]����������
�q, �A�}���U���C�ۿj�H�g���F�t��, �i���ѱ����M�S��, ���b
����W���v�T�O�٬O�۷�j��, �q�A������m�V�_�i�H�ݨ�ѱ�
���j�U, �F��h�U���@�Ӥ���.
LONG);
 set("exits",([ "north":__DIR__"bird5",
                "east":__DIR__"bird4",
                "west":__DIR__"bird3",
                "out":__DIR__"bird1",
    ]));
set("no_clean_up",0);
set("light",1);
 setup();
 replace_program(ROOM);
}

