#include <room.h>
inherit ROOM;
void create()
{
 set("short","��W�W");
 set("long",@LONG
�o�O�@�B�Z���R����W, ���Ǥp�ʪ������|�b�o��X�S,
�����S���H�n�پx���n��, �����ˬy�q�o��g�L, �n���O��
�V������y�L�h. 
LONG
    );
 set("exits",([ "west":__DIR__"outroom7",
                "east":__DIR__"outroom9",
               "south":__DIR__"outroom10",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
