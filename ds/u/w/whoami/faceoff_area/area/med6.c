#include <ansi.h>
#include <room.h>
inherit ROOM;
inherit DOOR;
void create()
{
 set("short","�p�|");

 set("long",@LONG
�o�O�@���q���ūǤν������p��, ���F���N�O�ū�, �ө���
���h�|�q������.
LONG
    );
 set("exits",([ "east":__DIR__"med7",
		"west":__DIR__"med5",
    ]));
create_door("east","�˪�","west",DOOR_CLOSED);
 set("no_clean_up",0);
 set("outdoors","land");
 setup();
}
