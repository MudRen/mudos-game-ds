#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIG"�U�D"NOR);

 set("long",@LONG
�o�̵M�O�b�Q�U�j�s���������@�����a�ն}�P���p��, 
���o�ڥ��O�@�����O�����p��, �`�@���u���T�o�e, �A
�ߤ���b�h�÷|�����ӺƤl�Ө��o�ؤ@�������d�j�몺�p
��?....
LONG
    );
 set("exits",([ "westup":__DIR__"ten_mountain5", 
                "southdown":__DIR__"ten_mountain7",
    ]));
set("no_clean_up",0);
set("outdoors","land");
 setup();
 replace_program(ROOM);
}

