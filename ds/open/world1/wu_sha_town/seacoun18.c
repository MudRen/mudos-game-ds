#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","������");
set("long",@LONG
�o�̱��ۦU���U�˪�����, ���L�۱q�L����令�ӷ~���
, �o�������E�w�g�ܤ֫ܤ��o! �o���ٯ���ͦs�U��, �D�n�O
�]�����D�]�F�ʬO�o����W�֦������Ͱ���, �Өӳo�̲��
�`�O�n�R�@�Ǻ����~��, �]���~����b���ѧ�L����ݦs��
�����ͷN�q�q�]�U, �j�j�פ�a?
LONG
    );
 set("exits",(["east":__DIR__"seacoun6",
]));
 set("objects", ([__DIR__"../npc/bou" :1,
    ]));
 set("no_clean_up",0);
 set("light",1);
 setup();
}             