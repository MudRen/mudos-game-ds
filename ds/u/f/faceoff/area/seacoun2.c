#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","�C�۹D");
set("long",@LONG
�A�ש�q�˪L�����X�ӤF, ���e�O�@���q�ӥΪ��C�۹D, �A
�o�{�A���|�P���\�h�ӤH, ���O�L�̪��f�����O����B�X���~�P
��, �]�����|�b����H, �q�o�̦A���F�N�|��L����, ����h�|
�^��B�F��.
LONG
    );
 set("exits",([ "west":__DIR__"seacoun1",
		"east":__DIR__"seacoun3",
]));
 set("objects", ([__DIR__"npc/salesman" : 3,
    ]));

 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);
}             
