#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"�p��"NOR);
set("long",@LONG
�q�o�̦A���F�_���N��Q�U�j�s���s�f�F, �q�A�o�̤w�g
�i�H�ݨ�Q�U�j�s���s�ߤF, ���M�Q�U�j�s���]���s���̨��
�W�n�j��, ���L�{�b�]�u�Ѥ@�ǹA�Ҧb���̤F....
LONG
    );
 set("exits",([ "northeast":__DIR__"road7",
		"southwest":__DIR__"road5",
]));
 set("objects", ([__DIR__"npc/mountain_cat": 4,
    ]));

 set("no_clean_up",0);
 set("light",1);
 setup();
 replace_program(ROOM);
}             
