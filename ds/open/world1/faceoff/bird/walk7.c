#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"�_���D"NOR);
 set("long",@LONG
�o�̤w�g�O�_���D�����ݤF, �A���e���N�O�ѱ��M�Ĥ@��
�M�����ѫȤH�ΤQ�U�j�s�C�ȥ𮧪��ȩ�, �̭����\�h�D���
, �����̩M�C��, ���o�۷��b, ���n���h�|�^��_���D.
LONG
    );
 set("exits",([ "north":__DIR__"bed1",
            "south":__DIR__"walk5",
            "east":__DIR__"bed2",
]));
set("objects", ([__DIR__"npc/birdguard" : 2,
    ]));

 set("no_clean_up",0);
 set("light",1);
 setup();
 replace_program(ROOM);
}             
