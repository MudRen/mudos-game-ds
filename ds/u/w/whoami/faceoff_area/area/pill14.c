#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"�F���D"NOR);

 set("long",@LONG
�o�̬O�ѱ��M�Ĥ@������b��, �q�o�̩��F�_�訫�|�q�V
�ѱ��M�Ĥ@�����îѻ�, ���̦��\�h�����į��Ѫ����y, ��
�F�n�h�O������.
LONG
    );
 set("exits",([ 
		"west":__DIR__"pill13",
    ]));
 set("objects", ([__DIR__"npc/birdguard" : 2,
    ]));
 set("no_clean_up",0);
 set("light",1);
 setup();
 replace_program(ROOM);                      
}
