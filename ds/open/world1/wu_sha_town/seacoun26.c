#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","����");
set("long",@LONG
�A�@��L�����j��, �ߨ�Q�|�P���H���~�F�@��, ��ӳo��
�ҥ�����O���ͪ��~, �]�����\�h���L������b�o�D�ʤ�`�Ϋ~
, �]���Ƿ|�p�����x�F.
LONG
    );
 set("exits",([ "north":__DIR__"seacoun25",
		"east":__DIR__"seacoun27",
]));
 set("objects", ([__DIR__"npc/salesman" : 2,
		  __DIR__"npc/woman" : 2,
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);
}            