#include <room.h>
inherit ROOM;
void create()
{
 set("short","���۪��U");
 set("long",@LONG
�A�{�b���b�V����e���@�ӥ��j�۪�, �ݰ_�ӦV�O�@�y�p
����, �٬O���[. �۪��W�U�����F�ƦW�ͽ�, �u�ƴ��Y. �o��
�O�۪����F��, ���@���ӱ�i�H���W����۪����W.
LONG
    );
 set("exits",([ "west":__DIR__"outdoor1",
                "up":__DIR__"outdoor5",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}