#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"�ū�"NOR);

 set("long",@LONG
�o�̬O�ūǪ�����, �A�o�{�A���F����G���@�Ӥj�j����
������, �A���n�_���X�ϧA������h�ݤ@��....
LONG
    );
 set("exits",([ "east":__DIR__"med9",
		"south":__DIR__"med7",
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);                      
}