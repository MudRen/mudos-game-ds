#include <room.h>
inherit ROOM;
void create()
{
 set("short","�e��");
 set("long",@LONG
�A�S�Ө�F�@�����e�����W��, ���O���F��_�T��ӥh,
�q�_��i�H�Pı���������y�F�@�ѭ��L��.
LONG
    );
 set("exits",([ "west":__DIR__"secret2_9",
                "north":__DIR__"secret2_7",
                "east":__DIR__"secret2_12",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
