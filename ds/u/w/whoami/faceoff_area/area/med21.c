#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",YEL"��L"NOR);

 set("long",@LONG
�A�ש�ΤF�@�f��, �q�o�̩��F���N�i�H���}�o�Ӽ�ê�
�a��F, �A���M�Q�_�b��L�����S���ݨ�|��������, �Q�ӬO
�]������|�g�W�ͻH, �ҥH�S�����Χa?
LONG
    );
 set("exits",([ "west":__DIR__"med22",
		"east":__DIR__"med18",
		"south":__DIR__"med20",
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);                      
}