#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",YEL"��L"NOR);

 set("long",@LONG
�o�̬O��L���F�n��, �A�o�{�o�̪��î�S�󰪤F�@��, ��
�H�A�]�󤣵ΪA�F, �A���M�o�{�A�}�U���\�h�p�������b���Ӫ�
�h....
LONG
    );
 set("exits",([ "north":__DIR__"med21",
		"east":__DIR__"med19",
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);                      
}