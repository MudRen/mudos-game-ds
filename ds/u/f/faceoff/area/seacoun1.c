#include <ansi.h>
#include <path.h>
inherit ROOM;
void create()
{
 set("short","�˪L�p�D");
set("long",@LONG
�q�o�̩��A�F���N�|��L����F, �A�q�����F���N�O�@��
�L�v�j��, �ө���h�|�^��B�F�����@���e�F, �A���k���O�@
����o�o���˪L, �٬O���[!
LONG
    );
 set("exits",([ "east":__DIR__"seacoun2",
	"west":COMINGING_PAST+"area/river2",
]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);
}             
