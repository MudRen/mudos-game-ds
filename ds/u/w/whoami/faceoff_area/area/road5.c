#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"�p��"NOR);
set("long",@LONG
�o�̤��M�O�@���e�s���쳥, �ӳo���p���]�V��V�p, ���L
�Q�U�j�s�N�b�A�F�_�褣���B, �o�̪��a��w�g���@�ǰ_��, ��
���n�樫....
LONG
    );
 set("exits",([ "northeast":__DIR__"road6",
		"southwest":__DIR__"road4",
]));
 set("objects", ([__DIR__"npc/mountain_cat": 4,
    ]));

 set("no_clean_up",0);
 set("light",1);
 setup();
 replace_program(ROOM);
}             
