#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"���Y"NOR);
 set("long",@LONG
�o�̦A���F���N�O�ѱ��M�Ĥ@�����j�U�F, �n��O�A�訫�L
�Ӫ���V, �o�̪����Y�W���ۤ@��㪺��H, �Q���O�d����J��
���̤l�m�߰w�b�Ϊ�. 
LONG);
 set("exits",([ "southwest":__DIR__"pill2",
                "northwest":__DIR__"pill4",
                "east":__DIR__"pill5",
    ]));
// set("objects", ([__DIR__"npc/traveller" : 2,
//    ]));
 set("no_clean_up",0);
 set("light",1);
 setup();
 replace_program(ROOM);                      
}

