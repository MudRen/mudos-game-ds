#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","�ײ�t");
set("long",@LONG
���M�L��T�~�e�N���ײ�t���]�m, ���L�L�c�a����᪺
�j½�פ~�O�Ĳv�������D�], ���M�L�⪺�ײ�t���j, ���Ҧ�
���]�ƫo�@���ѥ�. 
LONG
    );
 set("exits",([ "west":__DIR__"seacoun33",
		"south":__DIR__"seacoun35",
]));
 set("objects", ([__DIR__"../npc/worker2" : 1,
    ]));
 set("no_clean_up",0);
 set("light",1);
 setup();
 replace_program(ROOM);
}            