#include <room.h>
inherit ROOM;
void create()
{
 set("short","�շt���q�D");
 set("long",@LONG
�x? �a�W���G���ǿn��? �����D�o���O�q���̺��i�Ӫ�,
�A�̦n�p�ߤ@�I�e�i. ���䦳�ө��U�����q�D.
LONG
    );
 set("exits",([ "north":__DIR__"secret2_17",
                "west":__DIR__"secret2_19",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
