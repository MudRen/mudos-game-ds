#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"��j�Y"NOR);

 set("long",@LONG
�o�̸�F�j�Y�@��, �ⰼ���B�J�]�P�������R, ���L��j�Y
�o���G��F�j�Y�u�ܦh, ����`�@�u���X�B����, �b�A���P��_
�Ǫ��ɭ�, ���M�q�A���U��ǨӤ@�}�n��, �i�O�o�̨èS���X��
���U��? ���D������K�D?.....
LONG);
 set("exits",([ "east":__DIR__"bird5",
                "west":__DIR__"westroad2",
    ]));
set("no_clean_up",0);
set("light",1);
 setup();
 replace_program(ROOM);
}

