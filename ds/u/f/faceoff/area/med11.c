#include <ansi.h>
#include <room.h>
inherit ROOM;
inherit DOOR;
void create()
{
 set("short","�p�|");

 set("long",@LONG
�o�O�@���p�p����, �s���۷ūǩM�n�誺�w�L, �w�L���j��
�����O�شӶݴH�Ӫ�, �M�_�誺�ūǤj�O���P, �A�i�H�b���Ĩ�
�A�ҭn���ħ�.
LONG
    );
 set("exits",([ "west":__DIR__"med10",
		"south":__DIR__"med12",
    ]));
create_door("west","�˪�","east",DOOR_CLOSED);
 set("no_clean_up",0);
 set("outdoors","land");
 setup();
}
