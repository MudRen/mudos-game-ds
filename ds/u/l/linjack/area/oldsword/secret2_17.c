#include <room.h>
inherit ROOM;
void create()
{
 set("short","�շt���q�D");
 set("long",@LONG
�x? �a�W���G���ǿn��? �����D�o���O�q���̺��i�Ӫ�,
�A�̦n�p�ߤ@�I�e�i.
LONG
    );
 set("exits",([ "northeast":__DIR__"secret2_16",
                "south":__DIR__"secret2_18",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
