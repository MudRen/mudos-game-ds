#include <room.h>
inherit ROOM;
void create()
{
 set("short","�γ����");
 set("long",@LONG
�o��N�O�V����ť�W����R���γ����, �j�@�D��N��
�𮧫Ǥ����F, ���L�𮧫Ǥ��S������, �ҥH�A�]����q�o��
�i��Τl��. �A�i�H�ݨ�o�̤@���������F�C���⪺�ᦷ, ��
�g�H�Ŧ⪺�G��.
LONG
    );
 set("exits",([ "east":__DIR__"garden3",
               "north":__DIR__"garden4",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
