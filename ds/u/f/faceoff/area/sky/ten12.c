#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","���D");
 set("long",@LONG
�o�̬O���������D���A�A�i�H�ݨ��_�䦳�@�y�ִ���
���T�ΡA���b�Ϋe���F�@���H���ƿ�����P�A�W���g�F�ӡu
�ġv�r�A�ӫn��h�O�@�a�ݰ_�ӧ֭˳����ȴ̡A�����D�b�o
�̪��ȴ̭n�p����͡H�ܩ����h�O�@�Ӽs���A�]�O���l��
���c�a���a��F.
LONG
    );
 set("exits",([   "north":__DIR__"ten13",
               "south":__DIR__"ten15",
               "west":__DIR__"ten17",
               "east":__DIR__"ten11",
    ]));
set("no_clean_up",0);
set("outdoors","land");
 setup();
 replace_program(ROOM);
}

