//updated 26/12
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", HIC"ST�CRoad�INorth"NOR);
	set("long", "�o�̬OSaint�����䤤�@����D�A�o�̵��A���Pı�Q���n�A�]���o��
����w�R�a�I�����ɫo�]������H�b���ު����Y���ܱo���ǹ˧n�A�O�H�P
�즳�Ƿдo�C\n");
 set("exits",([ 
"north":__DIR__"dst9.c",
"south":__DIR__"dst5.c",
]));
set("outdoors","land");
	setup();
	replace_program(ROOM);
}
