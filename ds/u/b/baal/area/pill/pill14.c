#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"�F���D"NOR);

 set("long",@LONG
�o�̬O�ѱ��w�b�@������b��, �q�o�̩��F�_�訫�|�q�V
�ѱ��w�b�@�����îѻ�, ���̦��\�h����w�b���Ѫ����y, ��
�F�n�h�O������.
LONG
    );
 set("exits",([ "northeast":__DIR__"pill15",
                "southeast":__DIR__"pill16",
                "west":__DIR__"pill13",
    ]));
// set("objects", ([__DIR__"npc/birdguard" : 2,
//    ]));
 set("no_clean_up",0);
 set("light",1);
 setup();
 replace_program(ROOM);          
}
