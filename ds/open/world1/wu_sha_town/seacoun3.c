#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","�C�۹D");
set("long",@LONG
�o�̤��M�O�@���C�۹D, �q�o�̩��F�����B�N�i�H��L��
��F.
LONG
    );
 set("exits",([ "west":__DIR__"seacoun2",
		"east":__DIR__"seacoun4",
]));
 set("objects", ([__DIR__"../npc/salesman" : 2,
    ]));

 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);
}             
