#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","����");
set("long",@LONG
�o�̦�󥫶����F�n��, ���L����P�䥦�B�P���c��, �A�o
�{�o�̩ҥ�����F��j�����O�g��, �]�N�O���~��ӤH�ĶR���a
��, �A���M�o�{�A���F�観�@�a���ª��u�{, ���G�ᦳ�W��.....
LONG
    );
 set("exits",([ "north":__DIR__"seacoun23",
	    "west":__DIR__"seacoun27",
	    "east":__DIR__"seacoun40",
]));
 set("objects", ([__DIR__"npc/salesman3" : 2,
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);
}            