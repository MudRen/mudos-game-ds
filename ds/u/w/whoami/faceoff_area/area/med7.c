#include <ansi.h>
#include <room.h>
inherit ROOM;
inherit DOOR;
void create()
{
 set("short",HIR"�ū�"NOR);

 set("long",@LONG
�o�̬O�ѱ��M�Ĭ����Ӷݼ��Ӫ����ū�, �A�o�{�̭�����
�Ťj����~�����W�G, �T��, �ä��|���D�`������, �A�i�H�b
�o���A�n���ħ�.
LONG
    );
 set("exits",([ "north":__DIR__"med8",
		"west":__DIR__"med6",
		"east":__DIR__"med10",
    ]));
create_door("west","�˪�","east",DOOR_CLOSED);
 set("no_clean_up",0);
 set("outdoors","land");
 setup();
}
