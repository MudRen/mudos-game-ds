#include <room.h>
inherit ROOM;
void create()
{
 set("short","�L���Ŧa");
 set("long",@LONG
�g���d���U�W�A�ש�q�L�F�����g�c�몺�˪L, �Ө�F�@
�B�Ŧa, ���Ӥp�c�b�o���F��. ���_�����G�����p��, ���n
���]�O�b�Ŧa����.
LONG
    );
 set("exits",([ "westup":__DIR__"mountroad3_3",
                "south":__DIR__"mountroad3_5",
                "southeast":__DIR__"forest1",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}