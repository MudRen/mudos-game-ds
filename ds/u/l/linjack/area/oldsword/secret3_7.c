#include <room.h>
inherit ROOM;
void create()
{
 set("short","����");
 set("long",@LONG
�b�o��A���G�i�H�Pı��@���y�ʪ��Ů�q���_�����i
��....�o��ݨӤw�g�ܱ���~���F.
LONG
    );
 set("exits",([ "north":__DIR__"secret3_6",
                "up":__DIR__"secret2_1",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
