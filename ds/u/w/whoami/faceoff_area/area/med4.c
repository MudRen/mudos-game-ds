#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIC"����"NOR);

 set("long",@LONG
�o�̬O����������, �A�o�{�o�̪��g�[���M�ܷ�, ���o�۷�
�A�X����Ӫ����ͪ�, �ҥH�o�̤@���Y�Y�V�a������, �O�H�ݤF
�۷�κZ.
LONG
    );
 set("exits",([ "south":__DIR__"med5",
		"west":__DIR__"med3",
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);                      
}