#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","�ײ�t");
set("long",@LONG
���ҿצ���ì�����I�X, ��@����X�v�k�Ӯ�, ������쪺
�ˮ`�i�O�۷�j��, �ҥH�~�|���ײ�t���X�{, �L��ײ�t���W
�����M���j, ���Ĳv�ٺ⤣��!
LONG
    );
 set("exits",([ "north":__DIR__"seacoun30",
		"south":__DIR__"seacoun34",
		"east":__DIR__"seacoun36",
]));
 set("objects", ([__DIR__"npc/worker2" : 1,
		  __DIR__"npc/worker3" : 2,
    ]));
 set("no_clean_up",0);
 set("light",1);
 setup();
 replace_program(ROOM);
}            