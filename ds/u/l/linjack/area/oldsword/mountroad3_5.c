#include <room.h>
inherit ROOM;
void create()
{
 set("short","�L���Ŧa");
 set("long",@LONG
�g���d���U�W�A�ש�q�L�F�����g�c�몺�˪L, �Ө�F�@
�B�Ŧa, �_��]�O�@���Ŧa, �ө���n�����t�@����, ���G�O
�U�s��. 
LONG
    );
 set("exits",([ "east":__DIR__"forest1",
                "north":__DIR__"mountroad3_4",
                "southwest":__DIR__"mountroad6_1",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}