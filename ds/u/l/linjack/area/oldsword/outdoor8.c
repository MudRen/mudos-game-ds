#include <room.h>
inherit ROOM;
void create()
{
 set("short","�������a");
 set("long",@LONG
�q�L�F�@���U�D, �Ө�F�@�ӫ��R���L������, �o�Ө�
�|�P���s���ä��~�k, �u�n���A���u��, �i�H�ܮe������
�}�o�Ӥs��.
LONG
    );
 set("exits",([ "west":__DIR__"outdoor9",
                "north":__DIR__"outdoor10",
                "east":__DIR__"outdoor7",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}