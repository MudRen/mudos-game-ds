#include <room.h>
inherit ROOM;
void create()
{
 set("short","�򤤨��D");
 set("long",@LONG
�A�Ө�F�@���򤤨��D, ���k��ǦU���@�Ӥp����. �Z�`��,
���ǳ��b�̭����. ���D�W�٬O���Ǧu��, �A�J�ӬݤF�@�U�|�P
���a�z, �o�{�V����|�P���e�������O�H�����D�n�����X�a.
LONG
    );
 set("exits",([ "north":__DIR__"outroom4",
                "south":__DIR__"outdoor1",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
