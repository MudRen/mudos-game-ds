#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","���D");

 set("long",@LONG
�o�O�@���q���s�뤺�����D, �A���e�ݤF�@��, �o�{�e�観
��h���H����, �ݨӳo�Ӥs���b�j�����Y, �o�ˤ@�Q, �x�L�n
���󤣥i����i�ӤF....
LONG
    );
 set("exits",([ "north":__DIR__"ten8",
		"west":__DIR__"ten6",
    ]));
 set("objects", ([__DIR__"npc/bandit" : 2,
    ]));
 set("no_clean_up",0);
 set("light",1);
 setup();
 replace_program(ROOM);                      
}
