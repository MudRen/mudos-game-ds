#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"�p��"NOR);
set("long",@LONG
�q�o�̶}�l, �N�|�i�J��F�_�a�ϤF, �q�o�̨�Q�U�j�s, ��
���n�Q�Ѹ}�{,  �@���W������V�ӶV��D, ���Ǫ��p�c�]�ݤ����F
....
LONG
    );
 set("exits",([ "south":__DIR__"road1",
		"east":__DIR__"road3",
]));
 set("objects", ([__DIR__"npc/man" : 2,
    ]));

 set("no_clean_up",0);
 set("light",1);
 setup();
 replace_program(ROOM);
}             
