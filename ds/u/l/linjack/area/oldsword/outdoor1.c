#include <room.h>
inherit ROOM;
void create()
{
 set("short","���۪��U");
 set("long",@LONG
�A�{�b���b�V����e���@�ӥ��j�۪�, �ݰ_�ӦV�O�@�y�p
����, �٬O���[. �۪��W�U�����F�ƦW�ͽ�, �u�ƴ��Y. �q�L
�F�۪��N��V���󤺤F. ���k���٦���. ���Ӽӱ�i�q���۪�
��.
LONG
    );
 set("exits",([ "north":__DIR__"outroom6",
                "south":__DIR__"mountroad1",
                "east":__DIR__"outdoor2",
                "west":__DIR__"outdoor3",
                "up":__DIR__"outdoor4",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}