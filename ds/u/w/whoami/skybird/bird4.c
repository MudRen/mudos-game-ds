#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"�ѱ��F����"NOR);

 set("long",@LONG 
�o�̨�B���˴˪�, ��ӴN�O�����j�W���ѱ��F����, �]�N
�O�M�����ѱ��갣�ĤH���@�Ӥ���, �A�ݨ체�e���D��u�O�d�_
�ʩ�, �Q�_�H�e�ѱ������D�b�o�B�z�F�X�ӤϹ��, �A���o��
�����ˤ]���F����. �q�o�̩��訫�N�i�^��ѱ����j�|. �A�߸�
�u�Q�����]�h....
LONG
    );
 set("exits",([ "west":__DIR__"bird2",
    ]));
set("no_clean_up",0);
set("light",1);
 setup();
 replace_program(ROOM);
}

