#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","���F�q�j��");
set("long",@LONG
�o�̬O���F�q���j���F, �C�ɪ�����[�W��Ǫ��ե۷�, 
�G�M���@�Ѥ��Z�����Y, ���Lť����Ӯ��F�q�S�F�ܦh�訥, 
�ԲӪ����δN���o�Ӫ��F.
LONG
    );
 set("exits",([ "enter":__DIR__"seacoun8",
		"south":__DIR__"seacoun6",
]));
 set("objects", ([__DIR__"npc/seaguard" : 2,
    ]));

 set("no_clean_up",0);
 set("outdoors","land");
 setup();
}             
int valid_leave(object me, string dir)
{
       if( dir=="out" && !userp(me) )
                return notify_fail("���̥u�����a�~��i�h�C\n");
        return ::valid_leave(me, dir);
}