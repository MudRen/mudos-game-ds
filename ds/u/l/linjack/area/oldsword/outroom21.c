#include <room.h>
inherit ROOM;
void create()
{
 set("short","��W�W");
 set("long",@LONG
�o��w�g�O����s����������V�F, �A���̭����N��s
���U�����W�ѤF. ���\�h�p�ʪ����b�o��X�S, �o�䥿�B��
�s������, ����y�H.
LONG
    );
 set("exits",([ "south":__DIR__"outroom20",
                "north":__DIR__"outroom22",
                "west":__DIR__"outroom23",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
