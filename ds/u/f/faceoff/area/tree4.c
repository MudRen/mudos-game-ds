#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","�˪L");

 set("long",@LONG
�A�V�O�V�e�樫, �V�Pı�즳�H�b���ͬ�, �A�}�U���U�N�L��
���l�u, ���ǲ����ݯd�����, �b�b��ܥX���H�b���ͬ�, �A��
�̩��M�P��@�}�HŸ, ���D�ѱ��@�쪺�ǻ��O�u? 
LONG
    );

 set("exits",([ "south":__DIR__"tree3",

    ]));
set("no_clean_up",0);
set("outdoors","land");
 setup();
 replace_program(ROOM);
}
