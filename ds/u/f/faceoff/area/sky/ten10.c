#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","�p�|");
 set("long",@LONG
�o���p�|�j�ϤQ�U�j�s��D����^�A�|�P���O��A�y��
���C���O�A�b�o�@���C���O���u��j�j�ݨ�@���b�C�󤤪�
�p�|�A�ӧA��b�����۫H�o�O�@���q���s�����p��....
LONG
    );
 set("exits",([   "west":__DIR__"ten11",
               "east":__DIR__"ten6",
    ]));
set("no_clean_up",0);
set("outdoors","land");
 setup();
 replace_program(ROOM);
}

