#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","�����j��");
set("long",@LONG
�o�̬O�������j��, �A�i�H�ݨ��Ⱖ�L�⪺�N��, �ե۷�, 
���˪צb�����j����, �Ӭ����j���W�����B�g��: �|���ҥS��, 
���L��M�o�̪�������w���u�Υ|���ҥS�̨ӧήe�o!
LONG
    );
 set("exits",([ "east":__DIR__"seacoun22",
		"south":__DIR__"seacoun26",
]));
 set("objects", ([__DIR__"npc/sea_guard" : 2,
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);
}            