#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"���D"NOR);

 set("long",@LONG
�o�̦A���F���N�O�ѱ��w�b�@�����j�U�F, ����h�q�V�_
���D�M�n���D, �A�o�{�n���F�h�j�U���H���h, �M�Ӥj������
���O�ѱ��̤l, �ӬO�@�ǹC�H
LONG
    );
 set("exits",([ "east":__DIR__"pill4",
                "west":__DIR__"pill2",
    ]));
// set("objects", ([__DIR__"npc/traveller" : 2,
//    ]));
 set("no_clean_up",0);
 set("light",1);
 setup();
 replace_program(ROOM);                      
}
