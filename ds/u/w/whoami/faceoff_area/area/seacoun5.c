#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","�L����");
set("long",@LONG
�o�̩��_���|�q�����F�q, �ҿ׮��F�q���]�N�O����, 
���L�o�̪����F�q�O�b�@�~�e�~���ߪ�, ���e�O�ѪL�c�a�۶�
�q���Ӻ޲z�L�����@�����.
LONG
    );
 set("exits",([ "north":__DIR__"seacoun6",
		"south":__DIR__"seacoun4",
]));
 set("objects", ([__DIR__"npc/seaguard" : 2,
		  __DIR__"npc/thief" : 1,
    ]));

 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);
}             
