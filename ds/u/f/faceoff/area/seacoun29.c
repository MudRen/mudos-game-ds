#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","�D��");
set("long",@LONG
�o�̩��F�N�O�L�⪺��f�ϤF, �L����O�@�Ӭ۷���
����f, �@������c�a�������ϧA�P��L�������O!
LONG
    );
 set("exits",([ "east":__DIR__"seacoun30",
		"west":__DIR__"seacoun4",
]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);
}            