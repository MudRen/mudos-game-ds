#include <room.h>
inherit ROOM;
void create()
{
 set("short","�γ����");
 set("long",@LONG
�o��N�O�V����ť�W����R���γ����, �j�@�D��N��
�ȩФ����F, ���L�ȩФ��S������, �ҥH�A�]����q�o��i��
�Τl��. �a�W���Ǭ��⪺�F��, �����D������\��.
LONG
    );
 set("exits",([ "west":__DIR__"garden3",
               "north":__DIR__"garden2",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
