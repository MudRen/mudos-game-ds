#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","�_�ٮp");

 set("long",@LONG
�o�̬O�_�ٮp���F�_��, �A���T�]�����e�������ӷP���
�v�����p, �_�ٮp�O�Ѱ�w����^���Φ�, �]���|�P�����S��
����Ӫ��K.
LONG
    );
 set("exits",([ "south":__DIR__"ten10",
		"west":__DIR__"ten14",
    ]));

 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);                      
}
