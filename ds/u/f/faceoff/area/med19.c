#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",YEL"��L"NOR);

 set("long",@LONG
�o�̬O��L���n��, �ҿױ�L�N�O�شӻݭn���׷î�~��
�ͪ����Ӫ����a��, �ҥH�o�̪��î�O�۷���, ����O�A�P
�줣�ΪA....
LONG
    );
 set("exits",([ "north":__DIR__"med18",
		"west":__DIR__"med20",
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);                      
}