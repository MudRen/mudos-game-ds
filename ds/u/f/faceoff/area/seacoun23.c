#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","����");
set("long",@LONG
�o�̬O�������F��, �D�n�O�b�c��@�Ǯ��A, �o�̤��u����
��a�~�����C��, �s�~��H�]�۷���w�ӳo�̶R���A������Ŧ
�q�O! 
LONG
    );
 set("exits",([ "west":__DIR__"seacoun22",
		"south":__DIR__"seacoun24",
]));
 set("objects", ([__DIR__"npc/fisher" : 1,
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);
}            