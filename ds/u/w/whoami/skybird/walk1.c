#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"�_���D"NOR);
 set("long",@LONG
�o�̬O�ѱ����_���D, �G�m�P�n���D�j�P�p��, �o�����D�W
���\�h��H, �H�ӤH�����n�����x! �ݨӦA���_���N�O�ѱ��Ю{
���~�ҤF, ���n�h�O���Y.
LONG
    );
 set("exits",([ "north":__DIR__"walk3",
            "south":__DIR__"pill2",
]));
 set("objects", ([__DIR__"npc/prayer" : 2,
    ]));

 set("no_clean_up",0);
 set("light",1);
 setup();
 replace_program(ROOM);
}             
