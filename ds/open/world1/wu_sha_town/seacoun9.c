#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","���F�q-���x");
set("long",@LONG
�A�{�b���m������F�q�����x, �ѩ�L����M���T����
��, �]���쥻��ª���F�ưȥH�ܪ��c�ƵL��, �A���F��O�t
�d�B�z�F���F���F�᳡, �Ӧ����M�N�O��᳡�o! �p�G��
�_�h�|��t�d�B�z�@���T�������F���x�B�F.
LONG
    );
 set("exits",([ "east":__DIR__"seacoun14",
		"west":__DIR__"seacoun16",
		"north":__DIR__"seacoun10",
		"out":__DIR__"seacoun8",
]));
 set("objects", ([__DIR__"../npc/seaguard" : 2,
    ]));

 set("no_clean_up",0);
 set("light",1);
 setup();
 replace_program(ROOM);
}             
