#include <room.h>
inherit ROOM;
void create()
{
 set("short","��W�W");
 set("long",@LONG
�o��w�g�O����s����������V�F, �A���̭����N��s
���U�����W�ѤF. ���\�h�p�ʪ����b�o��X�S, �o�䥿�B��
�s������, �A�����O�@�Ӹ��G���s��, �s�����W�٦��V��
�󪺫ؿv��.
LONG
    );
 set("exits",([ "north":__DIR__"outroom24",
                "east":__DIR__"outroom21",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
