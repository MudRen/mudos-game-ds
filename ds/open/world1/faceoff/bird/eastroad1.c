#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"�F�j�Y"NOR);

 set("long",@LONG
�o�O�@���@��L�ڪ��j�Y, ���G�S�����Y, �A�`�N��j�Y��
�����O������B�J, �ϧA���۸T���g�İ_��, �A�J�Ӥ@��, �B�J
���O�@�ǳ����ϼ�, ��M�L��k���M�h��ѱ����Q�q����, ���O
�٬O�S���ѥ�, �A���T��L��k�S��`�@�h���L�q, �P���k�P��
�ˬO�o���j�Y����ɭԤ~�ਫ����Y�O?
LONG
    );
 set("exits",([ "east":__DIR__"eastroad2",
                "west":__DIR__"bird5",
    ]));
set("light",1);
set("no_clean_up",0);
 setup();
 replace_program(ROOM);
}
