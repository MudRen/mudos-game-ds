#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"�j�q�Q"NOR);
set("long",@LONG
�o�̬O�ѱ����ѨӳX�̥�ͪ��F��ɦ�, �A�o�{�o�̥��
�j�����O�ӤH, �]�\�A�i�H�M�L�̥��.
LONG
    );
 set("exits",([ "west":__DIR__"bed1",
            "south":__DIR__"bed3",
]));
 set("objects", ([__DIR__"npc/vendor" : 1,
    ]));

 set("no_clean_up",0);
 set("light",1);
 setup();
 replace_program(ROOM);
}             
