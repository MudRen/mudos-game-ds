#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"�p��"NOR);
set("long",@LONG
���M�o�@�q���{�۷��D, ���ä��N����F�_�a�ϬҬO�Z
��a, �u���L�O�o�@�q���{�����D�Ӥw, �A���F�_��h��
�Q�U�j�s�N���]���s���̹D���c�a....
LONG
    );
 set("exits",([ "west":__DIR__"road2",
		"northeast":__DIR__"road4",
]));
 set("objects", ([__DIR__"npc/man" : 2,
    ]));

 set("no_clean_up",0);
 set("light",1);
 setup();
 replace_program(ROOM);
}             
