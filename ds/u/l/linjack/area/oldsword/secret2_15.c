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
 set("exits",([ "northeast":__DIR__"secret2_12",
                "south":__DIR__"secret2_16",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
