#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","���F�q-�F��F��");
set("long",@LONG
�o�̬O���F�q���F��F��, �Q��M�N�ƳB�z�J�U, ���~����
�o! ���L�������F��F���٭n�A���_�@��, �o�̬O���ݿ�z�ư�
���H�̪����ݫ�.
LONG
    );
 set("exits",([ "north":__DIR__"seacoun15",
		"west":__DIR__"seacoun9",
]));
 set("objects", ([__DIR__"npc/wait_man" : 3,
    ]));

 set("no_clean_up",0);
 set("light",1);
 setup();
 replace_program(ROOM);
}             
