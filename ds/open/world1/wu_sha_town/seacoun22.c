#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","����");
set("long",@LONG
�o�̴N�O�L������R����ͥΫ~���a��F, �A�o�{�|�B��
�O�s���n, �n�����x ! 
LONG
    );
set("exits",([ "north":__DIR__"seacoun21",
             "west":__DIR__"seacoun25",
		"east":__DIR__"seacoun23",
]));
 set("objects", ([__DIR__"../npc/salesman" : 2,
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);
}            
