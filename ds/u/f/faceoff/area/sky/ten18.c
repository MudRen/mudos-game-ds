#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","���D");
 set("long",@LONG
�A���b���s����_�����D���W, �o���D�����G�q���A
�F�誺�@�y�T��, �o�y�T�Τ��P��@��, ��o�S�O����o, 
�]�\�O�]����b�̭����H�������P��@��?
LONG
    );
 set("exits",([   "east":__DIR__"ten19",
               "southeast":__DIR__"ten17",
    ]));
set("no_clean_up",0);
set("outdoors","land");
 setup();
 replace_program(ROOM);
}

