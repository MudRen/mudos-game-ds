#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"�p��"NOR);
set("long",@LONG
�o�̪�����w�g�Sԣ�n�y�z���F, �|�B�O�@���@��L�ڪ�
�쳥, �A�ߤ����M�Q�D: �����D�p�G�o�䪺�쳥�Ҷ}�����A��
�|�O�p�󪺱���?...
LONG
    );
 set("exits",([ "southwest":__DIR__"road3",
		"northeast":__DIR__"road5",
]));
 set("no_clean_up",0);
 set("light",1);
 setup();
 replace_program(ROOM);
}             
