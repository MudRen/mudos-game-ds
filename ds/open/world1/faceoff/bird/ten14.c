#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","�_�ٮp");

 set("long",@LONG
�o�̬O�_�ٮp���_��, �p�G�q�o�̩���_���N�O�t�����W
�����V�F, �A���訫�h�O�F�_�A�L, �A��ĳo�̪����⳺�M
�p�����[, �G�M�O�Ĥ@���p.
LONG
    );
 set("exits",([ "south":__DIR__"ten11",
		"east":__DIR__"ten13",
		"northwest":__DIR__"ten15",
    ]));
 set("objects", ([__DIR__"npc/eagle" : 4,
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);                      
}