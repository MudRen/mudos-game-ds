#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","���");

 set("long",@LONG
�A�����x�l�i�F���, �u���|�P���u�ì۷��Y�K, ���W�٦�
�@�ǽb�եi�H�V�~�g�b, ���n���x�L�ڥ����޳o��, �N��n��, 
�n�i��i�h�]����.
LONG
    );
 set("exits",([ "east":__DIR__"ten7", 
		"out":__DIR__"ten5",
		"north":__DIR__"ten16",
    ]));
 set("objects", ([__DIR__"npc/bandit" : 2,
    ]));
 set("no_clean_up", 0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);
}

