#include <room.h>
inherit ROOM;
void create()
{
 set("short","�շt���q�D");
 set("long",@LONG
�o�̪��a�O���G�����÷ư_��, �a�W���F�@�ǫC�a, �A���_��
�ӱo�p�ߤ@�I, �~���|�Q�ƭˤF...
LONG
    );
 set("exits",([ "north":__DIR__"secret2_15",
                "southwest":__DIR__"secret2_17",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);

}
