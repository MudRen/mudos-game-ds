#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"�w�b��"NOR);

 set("long",@LONG
�����j�W���ѱ��w�b��, ���e�ƤQ���d�l�̩�ۦU���U��
�w�b������, �Ʀʰ����w���̮̪����b��W, ����Q�ӭӤp�l
�l�N�ۤp��, �@�ѥO�H�@�ê����D�R���b��өж���...
LONG
    );
 set("exits",([ "north":__DIR__"pill8",
    ]));
 set("no_clean_up",0);
 set("light",1);
 setup();
 replace_program(ROOM);                      
}
