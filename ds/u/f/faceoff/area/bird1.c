#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"�}�Ѫ��۪�"NOR);

 set("long",@LONG
�A��F�@�����, �o�{�@�����O�}�Ѥ�����, �G�M����W
�Ǩ��ѱ��S���O�u�ꪺ, �A���T�P�İ_�������M����Ϥ@�׺�
�Q����, �Ǩ�[����۷�����P, �ߦ��ѱ��Q�d�@]���@�ӱЬ�
���o�p���U��.....
LONG
    );
 set("exits",([ "enter":__DIR__"bird2", 
                "west":__DIR__"ten_mountain7",
    ]));
 set("objects", ([__DIR__"npc/birdguard" : 2,
    ]));
set("no_clean_up",0);
set("light",1);
 setup();
 replace_program(ROOM);
}
