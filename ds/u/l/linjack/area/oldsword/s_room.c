#include <room.h>
inherit ROOM;
void create()
{
 set("short","�۫Ǥ�");
 set("long",@LONG
�o�ӥ۫Ǥ��ſ�����, ����]�S��.....
�A�oı�o�䪺�a�O�n���ǩǪ�.
LONG
    );
 set("exits",([ "west":__DIR__"outroom9",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}