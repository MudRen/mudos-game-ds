#include <room.h>
inherit ROOM;
void create()
{
 set("short","�s���U");
 set("long",@LONG
�o�䪺�u���w�g�������@�Ӥp����, ��������, ����
���������z�X�_�������~, �쩳�����򯫩_���B�O?
LONG
    );
 set("exits",([ "east":__DIR__"outroom24",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
