#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","�F��F��");
set("long",@LONG
�o�̬O���F�����F��F��, �M����z�@�������~�ư�, �b��
���������H�N�O�F��F�x�F
LONG
    );
 set("exits",([ "south":__DIR__"seacoun14",
]));
 set("objects", ([__DIR__"../npc/east_master" : 1,
    ]));

 set("no_clean_up",0);
 set("light",1);
 setup();
 replace_program(ROOM);
}             
