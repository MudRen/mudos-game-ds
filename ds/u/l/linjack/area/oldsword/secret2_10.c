#include <room.h>
inherit ROOM;
void create()
{
 set("short","�շt���q�D");
 set("long",@LONG
�o�̪��q�D��o�Q�����t, �A�L�k�w���A�U�@�B�|����
���򰭦a��. �A�u�Ʊ���I�X�h�Ӥw.
LONG
    );
 set("exits",([ "north":__DIR__"secret2_9",
                "west":__DIR__"secret2_11",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
