#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","�ϸz�D");

 set("long",@LONG
�A�ש��X�F�ϸz�D, �q�o�̩���_���|��Q�U�j�s���H�f
�̸Y�K���A�Ѱ�, ���F�h�q�������᪺�ѱ��M�Ĥ@���ΥL�̪���
�Ķ�.
LONG
    );
 set("exits",([ "southwest":__DIR__"ten11",
                "east":__DIR__"pill1",
    ]));
 set("objects", ([__DIR__"npc/soldier" : 2,
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();                    
}

