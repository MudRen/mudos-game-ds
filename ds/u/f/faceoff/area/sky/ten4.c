#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"�_�ٮp"NOR);
 set("long",@LONG
�A�q�j�ժ����⤤�i�H�j�j�ݨ��A����_��X�B���B���A
�@�y���⪺�J���A�P�ɧA�]�i�H�ݨ�����s�U�������A�q�o��
���U��A���@�ضW��@�U���Pı...
LONG
    );
 set("exits",([   "northwest":__DIR__"ten6",
               "southeast":__DIR__"ten2",
    ]));
set("no_clean_up",0);
set("outdoors","land");
 setup();
 replace_program(ROOM);
}

