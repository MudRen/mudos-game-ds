#include <room.h>
inherit ROOM;
void create()
{
 set("short","����");
 set("long",@LONG
�A���Ө�@�Ӧ�������, �^�h�N�O����K�}�Ϥ����F, �i�O�A
�ݨ�a�W���@�ӽc�l. �O�_�}�ӥ��}���O?
LONG
    );
 set("exits",([ "south":__DIR__"secret6_7",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
